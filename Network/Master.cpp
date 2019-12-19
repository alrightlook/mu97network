#include "Library.h"

namespace Network
{
	MasterStruct Master::Struct[6];
	std::string Master::Msg(255, ' ');
	unsigned long Master::Calcule;
	unsigned long Master::Delay;

	bool Master::initComponents()
	{
		Tokenizer _master(".\\Network\\Master.ut");

		if(_master.Loaded)
		{
			if(!_master.SectionExists(0))
			{
				return false;
			}
			else
			{
				Struct[0].String = _master[0][0][0].ToString();

				for(int i = 0; i < 6; i++)
				{
					Struct[i].Enable	 = (unsigned char)_master[0][(i + 1)][0].ToInteger();
					Struct[i].Level		 = (unsigned short)_master[0][(i + 1)][1].ToInteger();
					Struct[i].NextLevel	 = (unsigned short)_master[0][(i + 1)][2].ToInteger();
					Struct[i].Price		 = (unsigned int)_master[0][(i + 1)][3].ToInteger();
					Struct[i].Status	 = (unsigned long)_master[0][(i + 1)][4].ToInteger();
					Struct[i].NextStatus = (unsigned long)_master[0][(i + 1)][5].ToInteger();
					Struct[i].ZeroPoints = (unsigned char)_master[0][(i + 1)][6].ToInteger();
					Struct[i].ZeroResets = (unsigned char)_master[0][(i + 1)][7].ToInteger();
					Struct[i].Delay		 = (unsigned long)_master[0][(i + 1)][8].ToInteger();
				}
			}
		}

		return true;
	}

	void Master::initMaster(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Master) / 1000;

			if(Struct[szVip].Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Status > Object[dwIndex].Strength || Struct[szVip].Status > Object[dwIndex].Agility || Struct[szVip].Status > Object[dwIndex].Vitality || Struct[szVip].Status > Object[dwIndex].Energy)
			{
				sprintf_s(&Msg[0], 255, &Message::Master[0][0], Struct[szVip].Status);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Delay > Delay)
			{
				Calcule = Struct[szVip].Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				Player[szIndex].Delay.Master = GetTickCount();
			
				Object[dwIndex].Experience  = 0;
				Object[dwIndex].Level		= Struct[szVip].NextLevel;
				Object[dwIndex].Strength	= (unsigned short)Struct[szVip].NextStatus;
				Object[dwIndex].Agility		= (unsigned short)Struct[szVip].NextStatus;
				Object[dwIndex].Vitality	= (unsigned short)Struct[szVip].NextStatus;
				Object[dwIndex].Energy		= (unsigned short)Struct[szVip].NextStatus;
			
				if(Struct[szVip].ZeroPoints > 0)
				{
					Object[dwIndex].LevelUpPoint = 0;
				}

				if(Struct[szVip].Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				Connect::executeQuery(Query::Master[szVip], Object[dwIndex].Name);
				Connect::executeQuery(Query::Master[(szVip + 6)], Object[dwIndex].AccountID);

				if(Struct[szVip].ZeroResets > 0)
				{
					Connect::executeQuery(Query::Master[12], Object[dwIndex].Name);
				}

				ServerMessageSend((char*)Message::Master[1].c_str(), dwIndex, 1);

				ServerCloseClient(dwIndex, 1);
			}
		}
	}

	void Master::initNpcMaster(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpNpc)
	{
		WORD szIndex = (WORD)(lpObject->m_Index - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Master) / 1000;

			if(Struct[szVip].Level > lpObject->Level)
			{
				Calcule = Struct[szVip].Level - lpObject->Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else if(Struct[szVip].Price > lpObject->Money)
			{
				Calcule = Struct[szVip].Price - lpObject->Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else if(Struct[szVip].Status > lpObject->Strength || Struct[szVip].Status > lpObject->Agility || Struct[szVip].Status > lpObject->Vitality || Struct[szVip].Status > lpObject->Energy)
			{
				sprintf_s(&Msg[0], 255, &Message::Master[0][0], Struct[szVip].Status);
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else if(Struct[szVip].Delay > Delay)
			{
				Calcule = Struct[szVip].Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else
			{
				Player[szIndex].Delay.Master = GetTickCount();
			
				lpObject->Experience	= 0;
				lpObject->Level			= Struct[szVip].NextLevel;
				lpObject->Strength		= (unsigned short)Struct[szVip].NextStatus;
				lpObject->Agility		= (unsigned short)Struct[szVip].NextStatus;
				lpObject->Vitality		= (unsigned short)Struct[szVip].NextStatus;
				lpObject->Energy		= (unsigned short)Struct[szVip].NextStatus;
			
				if(Struct[szVip].ZeroPoints > 0)
				{
					lpObject->LevelUpPoint = 0;
				}

				if(Struct[szVip].Price > 0)
				{
					lpObject->Money -= Struct[szVip].Price;
					ServerMoneySend(lpObject->m_Index, lpObject->Money);
				}

				Connect::executeQuery(Query::Master[szVip], lpObject->Name);
				Connect::executeQuery(Query::Master[(szVip + 6)], lpObject->AccountID);

				if(Struct[szVip].ZeroResets > 0)
				{
					Connect::executeQuery(Query::Master[12], lpObject->Name);
				}

				ServerNpcTalkSend(lpNpc, (char*)Message::Master[1].c_str(), lpObject->m_Index);
				ServerCloseClient(lpObject->m_Index, 1);
			}
		}
	}
}