#include "Library.h"

namespace Network
{
	SkillStruct Skill::Struct[30];

	bool Skill::initComponents()
	{
		TokenizerEx _skill("..\\Data\\Config\\Language\\Item.txt");

		if(_skill.Loaded)
		{
			if(!_skill.SectionExists(12))
			{
				return false;
			}
			else if(!_skill.SectionExists(15))
			{
				return false;
			}
			else
			{
				for(int i = 0; i < 30; i++)
				{
					Struct[i].Item = 0;
				}

				for(int i = 7, n = 0; i < 20; i++, n++)
				{
					if(i == 15)
					{
						continue;
					}

					Struct[n].Item		= ITEMGET(12, i);
					Struct[n].Level		= (unsigned short)_skill[12][i][10].ToInteger();
					Struct[n].Strength	= (unsigned short)_skill[12][i][12].ToInteger();
					Struct[n].Dexterity	= (unsigned short)_skill[12][i][13].ToInteger();
					Struct[n].Energy	= (unsigned short)_skill[12][i][11].ToInteger();
					Struct[n].Class[0]	= (unsigned char)_skill[12][i][15].ToInteger();
					Struct[n].Class[1]	= (unsigned char)_skill[12][i][16].ToInteger();
					Struct[n].Class[2]	= (unsigned char)_skill[12][i][17].ToInteger();
					Struct[n].Class[3]	= (unsigned char)_skill[12][i][18].ToInteger();
				}

				for(int i = 0, n = 13; i < 16; i++, n++)
				{
					Struct[n].Item		= ITEMGET(15, i);
					Struct[n].Level		= (unsigned short)_skill[15][i][8].ToInteger();
					Struct[n].Strength	= 0;
					Struct[n].Dexterity	= 0;
					Struct[n].Energy	= (unsigned short)_skill[15][i][9].ToInteger();
					Struct[n].Class[0]	= (unsigned char)_skill[15][i][11].ToInteger();
					Struct[n].Class[1]	= (unsigned char)_skill[15][i][12].ToInteger();
					Struct[n].Class[2]	= (unsigned char)_skill[15][i][13].ToInteger();
					Struct[n].Class[3]	= (unsigned char)_skill[15][i][14].ToInteger();
				}

				return true;
			}
		}

		return false;
	}

	void Skill::initUse(PMSG_USEITEM* lpMsg, DWORD dwIndex)
	{
		BYTE Pos = lpMsg->Pos;
		bool szProceed = true;

		if(Object[dwIndex].pInventory[Pos].m_Type >= ITEMGET(12, 7) && Object[dwIndex].pInventory[Pos].m_Type <= ITEMGET(12, 14) || Object[dwIndex].pInventory[Pos].m_Type >= ITEMGET(12, 16) && Object[dwIndex].pInventory[Pos].m_Type <= ITEMGET(12, 19) || Object[dwIndex].pInventory[Pos].m_Type >= ITEMGET(15, 0))
		{
			for(BYTE i = 0; i < 30; i++)
			{
				if(Struct[i].Item == 0)
				{
					break;
				}
			
				if(Object[dwIndex].pInventory[Pos].m_Type == Struct[i].Item)
				{
					if(Object[dwIndex].Level < Struct[i].Level)
					{
						szProceed = false;
					}
					else if(Object[dwIndex].Strength < Struct[i].Strength)
					{
						szProceed = false;
					}
					else if(Object[dwIndex].Agility < Struct[i].Dexterity)
					{
						szProceed = false;
					}
					else if(Object[dwIndex].Energy < Struct[i].Energy)
					{
						szProceed = false;
					}
					else
					{
						BYTE szClass, szRequire[2];
					
						szClass		 = Struct[i].Class[Object[dwIndex].Class];
						szRequire[0] = (Object[dwIndex].Class == 0) ? 0 : (Object[dwIndex].Class == 1) ? 16 : (Object[dwIndex].Class == 2) ? 32 : 48;
						szRequire[1] = (Object[dwIndex].Class == 0) ? 1 : (Object[dwIndex].Class == 1) ? 17 : (Object[dwIndex].Class == 2) ? 33 : 48;

						if(szClass == 1)
						{
							if(Object[dwIndex].DbClass != szRequire[0] && Object[dwIndex].DbClass != szRequire[1])
							{
								szProceed = false;
							}
						}
						else if(szClass == 2)
						{
							if(Object[dwIndex].DbClass != szRequire[1])
							{
								szProceed = false;
							}
						}
						else
						{
							szProceed = false;
						}
					}

					break;
				}
			}
		}

		if(!szProceed)
		{
			ServerReFillSend(dwIndex, (WORD)Object[dwIndex].Life, 0xFD, 1);
			return;
		}

		ServerUseItemRecv(lpMsg, dwIndex);
	}
}