#include "Library.h"

namespace Network
{
	ResetStruct Reset::Struct[6];
	std::string Reset::Msg(255, ' ');
	unsigned long Reset::Calcule;
	unsigned long Reset::Delay;
	unsigned char Reset::Count[6];

	bool Reset::initComponents()
	{
		Tokenizer _reset(".\\Network\\Reset.ut");

		if(_reset.Loaded)
		{
			if(!_reset.SectionExists(0))
			{
				return false;
			}
			else if(!_reset.SectionExists(1))
			{
				return false;
			}
			else if(!_reset.SectionExists(2))
			{
				return false;
			}
			else if(!_reset.SectionExists(3))
			{
				return false;
			}
			else if(!_reset.SectionExists(4))
			{
				return false;
			}
			else if(!_reset.SectionExists(5))
			{
				return false;
			}
			else if(!_reset.SectionExists(6))
			{
				return false;
			}
			else if(!_reset.SectionExists(7))
			{
				return false;
			}
			else if(!_reset.SectionExists(8))
			{
				return false;
			}
			else
			{
				Struct[0].String = _reset[0][0][0].ToString();

				for(int i = 0; i < 6; i++)
				{
					Struct[i].Enable = (unsigned char)_reset[0][(i + 1)][0].ToInteger();
					Struct[i].NPC	 = (unsigned char)_reset[0][(i + 1)][1].ToInteger();
					Struct[i].Type	 = (unsigned char)_reset[0][(i + 1)][2].ToInteger();
					Struct[i].Delay	 = (unsigned long)_reset[0][(i + 1)][3].ToInteger();

					Struct[i].Accumulative.Level	 = (unsigned short)_reset[1][i][0].ToInteger();
					Struct[i].Accumulative.NextLevel = (unsigned short)_reset[1][i][1].ToInteger();
					Struct[i].Accumulative.Price	 = (unsigned int)_reset[1][i][2].ToInteger();
					Struct[i].Accumulative.Points	 = (unsigned long)_reset[1][i][3].ToInteger();

					Struct[i].Scoring.Level		= (unsigned short)_reset[2][i][0].ToInteger();
					Struct[i].Scoring.NextLevel = (unsigned short)_reset[2][i][1].ToInteger();
					Struct[i].Scoring.Price		= (unsigned int)_reset[2][i][2].ToInteger();
					Struct[i].Scoring.Status	= (unsigned short)_reset[2][i][3].ToInteger();
					Struct[i].Scoring.Points	= (unsigned long)_reset[2][i][4].ToInteger();
					Struct[i].Scoring.Quantity	= (unsigned long)_reset[2][i][5].ToInteger();

					Count[i] = (_reset[(i + 3)].RowCount > 10) ? 10 : _reset[(i + 3)].RowCount;
					for(int n = 0; n < Count[i]; n++)
					{
						Struct[i].Tabulated[n].Initial	 = (unsigned long)_reset[(i + 3)][n][0].ToInteger();
						Struct[i].Tabulated[n].Final	 = (unsigned long)_reset[(i + 3)][n][1].ToInteger();
						Struct[i].Tabulated[n].Level	 = (unsigned short)_reset[(i + 3)][n][2].ToInteger();
						Struct[i].Tabulated[n].NextLevel = (unsigned short)_reset[(i + 3)][n][3].ToInteger();
						Struct[i].Tabulated[n].Price	 = (unsigned int)_reset[(i + 3)][n][4].ToInteger();
						Struct[i].Tabulated[n].Status	 = (unsigned short)_reset[(i + 3)][n][5].ToInteger();
						Struct[i].Tabulated[n].Points	 = (unsigned long)_reset[(i + 3)][n][6].ToInteger();
						Struct[i].Tabulated[n].Quantity	 = (unsigned long)_reset[(i + 3)][n][7].ToInteger();
					}
				}
			}
		}

		return true;
	}

	void Reset::initReset(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Enable == 1)
		{
			WORD wdLevel, wdTabulated;
			UINT uiPrice;
			
			Delay = (GetTickCount() - Player[szIndex].Delay.Reset) / 1000;
						
			switch(Struct[szVip].Type)
			{
			case 1:
				{
					wdLevel		= Struct[szVip].Scoring.Level;
					uiPrice		= Struct[szVip].Scoring.Price;
				}break;
			case 2:
				{
					Function::updateReset(dwIndex);

					for(int i = 0; i < (int)Count[szVip]; i++)
					{
						if(Player[szIndex].Reset >= Struct[szVip].Tabulated[i].Initial && Player[szIndex].Reset <= Struct[szVip].Tabulated[i].Final)
						{
							wdTabulated = (WORD)i;
							wdLevel		= Struct[szVip].Tabulated[i].Level;
							uiPrice		= Struct[szVip].Tabulated[i].Price;
							break;
						}

						if(i == (Count[szVip] - 1))
						{
							wdTabulated = 0;
							wdLevel		= Struct[szVip].Tabulated[0].Level;
							uiPrice		= Struct[szVip].Tabulated[0].Price;
						}
					}
				}break;
			default:
				{
					wdLevel		= Struct[szVip].Accumulative.Level;
					uiPrice		= Struct[szVip].Accumulative.Price;
				}break;
			}

			if(wdLevel > Object[dwIndex].Level)
			{
				Calcule = wdLevel - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(uiPrice > Object[dwIndex].Money)
			{
				Calcule = uiPrice - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
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
				Player[szIndex].Delay.Reset = GetTickCount();

				Object[dwIndex].Experience = 0;
			
				UINT uiPoints;

				switch(Struct[szVip].Type)
				{
				case 1:
					{
						uiPoints					 = (Player[szIndex].Reset + Struct[szVip].Scoring.Quantity) * Struct[szVip].Scoring.Points;
						Object[dwIndex].Level		 = Struct[szVip].Scoring.NextLevel;
						Object[dwIndex].LevelUpPoint = uiPoints >= 4250000000 ? 4250000000 : uiPoints;
						Object[dwIndex].Strength	 = Struct[szVip].Scoring.Status;
						Object[dwIndex].Agility		 = Struct[szVip].Scoring.Status;
						Object[dwIndex].Vitality	 = Struct[szVip].Scoring.Status;
						Object[dwIndex].Energy		 = Struct[szVip].Scoring.Status;
				
						if(Struct[szVip].Scoring.Price > 0)
						{
							Object[dwIndex].Money -= Struct[szVip].Scoring.Price;
							ServerMoneySend(dwIndex, Object[dwIndex].Money);
						}
					}break;
				case 2:
					{
						uiPoints					 = (Player[szIndex].Reset + Struct[szVip].Tabulated[wdTabulated].Quantity) * Struct[szVip].Tabulated[wdTabulated].Points;
						Object[dwIndex].Level		 = Struct[szVip].Tabulated[wdTabulated].NextLevel;
						Object[dwIndex].LevelUpPoint = uiPoints >= 4250000000 ? 4250000000 : uiPoints;
						Object[dwIndex].Strength	 = Struct[szVip].Tabulated[wdTabulated].Status;
						Object[dwIndex].Agility		 = Struct[szVip].Tabulated[wdTabulated].Status;
						Object[dwIndex].Vitality	 = Struct[szVip].Tabulated[wdTabulated].Status;
						Object[dwIndex].Energy		 = Struct[szVip].Tabulated[wdTabulated].Status;
				
						if(Struct[szVip].Tabulated[wdTabulated].Price > 0)
						{
							Object[dwIndex].Money -= Struct[szVip].Tabulated[wdTabulated].Price;
							ServerMoneySend(dwIndex, Object[dwIndex].Money);
						}
					}break;
				default:
					{
						uiPoints					 = (Object[dwIndex].LevelUpPoint + Struct[szVip].Accumulative.Points);
						Object[dwIndex].Level		 = Struct[szVip].Accumulative.NextLevel;
						Object[dwIndex].LevelUpPoint = uiPoints >= 4250000000 ? 4250000000 : uiPoints;

						if(Struct[szVip].Accumulative.Price > 0)
						{
							Object[dwIndex].Money -= Struct[szVip].Accumulative.Price;
							ServerMoneySend(dwIndex, Object[dwIndex].Money);
						}
					}break;
				}

				Connect::executeQuery(Query::Reset[szVip], Object[dwIndex].Name);
				ServerMessageSend((char*)Message::Reset.c_str(), dwIndex, 1);			
				ServerCloseClient(dwIndex, 1);
			}
		}
	}

	void Reset::initNpcReset(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpNpc)
	{
		WORD szIndex = (WORD)(lpObject->m_Index - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Enable == 1)
		{
			WORD wdLevel, wdTabulated;
			UINT uiPrice;
			
			Delay = (GetTickCount() - Player[szIndex].Delay.Reset) / 1000;
						
			switch(Struct[szVip].Type)
			{
			case 1:
				{
					wdLevel		= Struct[szVip].Scoring.Level;
					uiPrice		= Struct[szVip].Scoring.Price;
				}break;
			case 2:
				{
					Function::updateReset(lpObject->m_Index);

					for(int i = 0; i < (int)Count[szVip]; i++)
					{
						if(Player[szIndex].Reset >= Struct[szVip].Tabulated[i].Initial && Player[szIndex].Reset <= Struct[szVip].Tabulated[i].Final)
						{
							wdTabulated = (WORD)i;
							wdLevel		= Struct[szVip].Tabulated[i].Level;
							uiPrice		= Struct[szVip].Tabulated[i].Price;
							break;
						}

						if(i == (Count[szVip] - 1))
						{
							wdTabulated = 0;
							wdLevel		= Struct[szVip].Tabulated[0].Level;
							uiPrice		= Struct[szVip].Tabulated[0].Price;
						}
					}
				}break;
			default:
				{
					wdLevel		= Struct[szVip].Accumulative.Level;
					uiPrice		= Struct[szVip].Accumulative.Price;
				}break;
			}

			if(wdLevel > lpObject->Level)
			{
				Calcule = wdLevel - lpObject->Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else if(uiPrice > lpObject->Money)
			{
				Calcule = uiPrice - lpObject->Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
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
				Player[szIndex].Delay.Reset = GetTickCount();

				lpObject->Experience = 0;
			
				UINT uiPoints;

				switch(Struct[szVip].Type)
				{
				case 1:
					{
						uiPoints				 = (Player[szIndex].Reset + Struct[szVip].Scoring.Quantity) * Struct[szVip].Scoring.Points;
						lpObject->Level			 = Struct[szVip].Scoring.NextLevel;
						lpObject->LevelUpPoint	 = uiPoints >= 4250000000 ? 4250000000 : uiPoints;
						lpObject->Strength		 = Struct[szVip].Scoring.Status;
						lpObject->Agility		 = Struct[szVip].Scoring.Status;
						lpObject->Vitality		 = Struct[szVip].Scoring.Status;
						lpObject->Energy		 = Struct[szVip].Scoring.Status;
				
						if(Struct[szVip].Scoring.Price > 0)
						{
							lpObject->Money -= Struct[szVip].Scoring.Price;
							ServerMoneySend(lpObject->m_Index, lpObject->Money);
						}
					}break;
				case 2:
					{
						uiPoints				= (Player[szIndex].Reset + Struct[szVip].Tabulated[wdTabulated].Quantity) * Struct[szVip].Tabulated[wdTabulated].Points;
						lpObject->Level			= Struct[szVip].Tabulated[wdTabulated].NextLevel;
						lpObject->LevelUpPoint  = uiPoints >= 4250000000 ? 4250000000 : uiPoints;
						lpObject->Strength		= Struct[szVip].Tabulated[wdTabulated].Status;
						lpObject->Agility		= Struct[szVip].Tabulated[wdTabulated].Status;
						lpObject->Vitality		= Struct[szVip].Tabulated[wdTabulated].Status;
						lpObject->Energy		= Struct[szVip].Tabulated[wdTabulated].Status;
				
						if(Struct[szVip].Tabulated[wdTabulated].Price > 0)
						{
							lpObject->Money -= Struct[szVip].Tabulated[wdTabulated].Price;
							ServerMoneySend(lpObject->m_Index, lpObject->Money);
						}
					}break;
				default:
					{
						uiPoints				= (lpObject->LevelUpPoint + Struct[szVip].Accumulative.Points);
						lpObject->Level			= Struct[szVip].Accumulative.NextLevel;
						lpObject->LevelUpPoint	= uiPoints >= 4250000000 ? 4250000000 : uiPoints;

						if(Struct[szVip].Accumulative.Price > 0)
						{
							lpObject->Money -= Struct[szVip].Accumulative.Price;
							ServerMoneySend(lpObject->m_Index, lpObject->Money);
						}
					}break;
				}

				Connect::executeQuery(Query::Reset[szVip], lpObject->Name);
				ServerNpcTalkSend(lpNpc, (char*)Message::Reset.c_str(), lpObject->m_Index);
				ServerCloseClient(lpObject->m_Index, 1);
			}
		}
	}
}