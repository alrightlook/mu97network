#include "Library.h"

namespace Network
{
	NoticeStruct Function::Struct[10];
	unsigned char Function::Id;

	bool Function::checkFiles(std::string szFile)
	{
		std::fstream f(szFile.c_str(), std::ios::in);

		if(f.is_open() && f.good())
		{
			f.close();

			return true;
		}

		return false;
	}

	bool Function::initComponents()
	{
		Tokenizer _notice(".\\Network\\Notice.ut");

		if(_notice.Loaded)
		{
			if(!_notice.SectionExists(0))
			{
				return false;
			}
			else 
			{
				Struct[0].Enable = (unsigned char)_notice[0][0][0].ToInteger();
				Struct[0].Use	 = ((unsigned char)_notice[0][0][1].ToInteger() > 10) ? 10 : (unsigned char)_notice[0][0][1].ToInteger();
				Struct[0].Delay	 = (unsigned long)_notice[0][0][2].ToInteger();

				for(int i = 0; i < (int)Struct[0].Use; i++)
				{
					if(!_notice.SectionExists((i + 1)))
					{
						return false;
					}

					Struct[i].Header  = _notice[(i + 1)][0][0].ToString();
					Struct[i].Body	  = _notice[(i + 1)][1][0].ToString();
					Struct[i].Footer  = _notice[(i + 1)][2][0].ToString();
					Struct[i].Address = _notice[(i + 1)][3][0].ToString();
				}

				Id = 0;
			}
		}

		return true;
	}

	short Function::stringExplode(std::string szAddress, std::string szExplode)
	{
		BYTE szId = 0, szDec[4] = {0};
		std::string szConvert = "";
	
		for(int i = 0; i <= (int)szAddress.length(); i++)
		{
			if(!szAddress.compare(i, 1, szExplode) || i == szAddress.length())
			{
				szDec[szId] = (BYTE)atoi((char*)szConvert.c_str());
				szConvert = "";
				szId++;
			}
			else
			{
				szConvert += szAddress[i];
			}
		}

		float szResult = (float)(((szDec[0] + szDec[1]) - szDec[2]) + (szDec[3] * 2)) / 2;

		if((szResult > 400))
		{
			szResult /= 2;
		}

		return (short)szResult;
	}

	void Function::hookStruct()
	{
		for(int i = 0x401000; i < 0x508FFF; i++)
		{
			if(*(DWORD*)i >= 0x4CEE778 && *(DWORD*)i <= 0x4CEF484)
			{
				int szRest = *(DWORD*)i - 0x4CEE778;
				*(DWORD*)i = (DWORD)&Object + szRest;
			}
			if(*(WORD*)i == 0xD0C)
			{
				if(*(BYTE*)(i - 2) == 0x69)
				{
					*(WORD*)i = sizeof(OBJECTSTRUCT);
				}
			}
		}
	}

	void Function::hookFunction(DWORD dwFunction, DWORD dwOffset)
	{
		*(DWORD*)(dwOffset + 1) = dwFunction - (dwOffset + 5);
	}

	void Function::showNotice(LPVOID lpParam)
	{
		if(Struct[0].Enable == 1)
		{
			BYTE szId = (Struct[0].Use - 1);
			
			if(Id > 9 || Id > szId)
			{
				Id = 0;
			}

			if(Struct[Id].Header.empty() && Struct[Id].Body.empty() && Struct[Id].Footer.empty() && Struct[Id].Address.empty())
			{
				Id = 0;
			}

			for(int i = 4800; i < 5800; i++)
			{
				if(Object[i].Connected > 2)
				{
					ServerMessageSend((char*)Struct[Id].Header.c_str(),  i, 0);
					ServerMessageSend((char*)Struct[Id].Body.c_str(),    i, 0);
					ServerMessageSend((char*)Struct[Id].Footer.c_str(),  i, 0);
					ServerMessageSend((char*)Struct[Id].Address.c_str(), i, 0);
				}
			}

			Id++;
			Sleep(Struct[0].Delay * 60000);
			showNotice(NULL);
		}
		else
		{
			_endthread();
		}
	}

	void Function::updateVip(LPVOID lpParam)
	{
		for(int i = 4800; i < 5800; i++)
		{
			if(Object[i].Connected > 1)
			{
				Connect::executeQuery(Query::Vip, Object[i].AccountID);
				Player[(i - 4800)].Vip = (unsigned char)Connect::getInteger(1);
			}
		}
	}

	void Function::updateReset(DWORD dwIndex)
	{
		Connect::executeQuery(Query::Data[1], Object[dwIndex].Name);
		Player[(dwIndex - 4800)].Reset = (unsigned long)Connect::getInteger(1);
	}

	bool Function::checkString(std::string szString, std::string szPattern, bool szIgnoreSpace)
    {
        DWORD dwCount = 0;
        std::string szReg = "", szCharacter = "";
        
        if(szPattern[0] != '[' || szPattern[(szPattern.length() - 1)] != ']')
        {
            return false;
        }

        for(int i = 1; i < (int)szPattern.length(); i++)
        {
            if(szPattern[i] == ']')
            {
                if(!szReg.empty())
                {
                    szCharacter += szReg;
                }

                break;
            }

            if(!szPattern.compare(i, 3, "A-Z"))
            {
                szCharacter += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                i += 2;
            }
            else if(!szPattern.compare(i, 3, "a-z"))
            {
                szCharacter += "abcdefghijklmnopqrstuvwxyz";
                i += 2;
            }
            else if(!szPattern.compare(i, 3, "0-9"))
            {
                szCharacter += "0123456789";
                i += 2;
            }
            else
            {
                szReg += szPattern[i];
            }
        }

        for(int n = 0; n < (int)szString.length(); n++)
        {
            if(szString[n] == ' ' && szIgnoreSpace)
            {
                dwCount++;
                continue;
            }

            for(int y = 0; y < (int)szCharacter.length(); y++)
            {
                if(szString[n] == szCharacter[y])
                {
                    dwCount++;
                    break;
                }
            }
        }

        if(dwCount == (DWORD)szString.length())
        {
            return true;
        }

        return false;
    }

	void Function::clearItem(DWORD dwIndex, BYTE btNumber)
	{
		Object[dwIndex].pWarehouse[btNumber].m_Type = (-1);
		Object[dwIndex].pWarehouse[btNumber].m_Level = 0;
		Object[dwIndex].pWarehouse[btNumber].m_Part = 0;
		Object[dwIndex].pWarehouse[btNumber].m_Class = 0;
		Object[dwIndex].pWarehouse[btNumber].m_TwoHand = 0;
		Object[dwIndex].pWarehouse[btNumber].m_AttackSpeed = 0;
		Object[dwIndex].pWarehouse[btNumber].m_DamageMin = 0;
		Object[dwIndex].pWarehouse[btNumber].m_DamageMax = 0;
		Object[dwIndex].pWarehouse[btNumber].m_SuccessfulBlocking = 0;
		Object[dwIndex].pWarehouse[btNumber].m_Defense = 0;
		Object[dwIndex].pWarehouse[btNumber].m_MagicDefense = 0;
		Object[dwIndex].pWarehouse[btNumber].m_Durability = 0;
		Object[dwIndex].pWarehouse[btNumber].m_SpecialNum = 0;
		Object[dwIndex].pWarehouse[btNumber].m_Value = 0;
		Object[dwIndex].pWarehouse[btNumber].m_OptionSkill = 0;
		Object[dwIndex].pWarehouse[btNumber].m_OptionLuck = 0;
		Object[dwIndex].pWarehouse[btNumber].m_OptionAdditional = 0;
		Object[dwIndex].pWarehouse[btNumber].m_OptionExcellent = 0;
		Object[dwIndex].pWarehouse[btNumber].m_Number = 0;
		Object[dwIndex].pWarehouse[btNumber].m_DurabilitySmall = 0;
		Object[dwIndex].pWarehouse[btNumber].m_CurrentDurabilityState = (-1);
		Object[dwIndex].pWarehouse[btNumber].m_SetOption = 0;
		Object[dwIndex].pWarehouse[btNumber].m_QuestItem = false;

		memset(Object[dwIndex].pWarehouse[btNumber].m_Special, 0x00, sizeof(Object[dwIndex].pWarehouse[btNumber].m_Special));
		memset(Object[dwIndex].pWarehouse[btNumber].m_SpecialValue, 0x00, sizeof(Object[dwIndex].pWarehouse[btNumber].m_SpecialValue));
		memset(Object[dwIndex].pWarehouse[btNumber].m_Resistance, 0x00, sizeof(Object[dwIndex].pWarehouse[btNumber].m_Resistance));
	}

	void Function::useFirework(DWORD dwIndex)
	{
		if(Object[dwIndex].X <= 5 || Object[dwIndex].X >= 250 || Object[dwIndex].Y <= 5 || Object[dwIndex].Y >= 250)
		{
			return;
		}
		
		char PacketRand[5] = {-2, -1, 0, 1, 2};
		
		BYTE Packet[20][7];
		
		for(int i = 0; i < 20; i++)
		{
			BYTE RandX = (rand() % 5);
			BYTE RandY = (rand() % 5);

			Packet[i][0] = 0xC1;
			Packet[i][1] = 0x07;
			Packet[i][2] = 0xF3;
			Packet[i][3] = 0x40;
			Packet[i][4] = 0x00;
			Packet[i][5] = (BYTE)(Object[dwIndex].X + PacketRand[RandX]);
			Packet[i][6] = (BYTE)(Object[dwIndex].Y + PacketRand[RandY]);
		}

		for(int i = 4800; i < 5800; i++)
		{
			if(Object[i].Connected > 2)
			{
				if(Object[i].Map == Object[dwIndex].Map)
				{
					for(int n = 0; n < 20; n++)
					{
						ServerDataSend(i, Packet[n], (DWORD)Packet[n][1]);
					}
				}
			}
		}
	}
}