#include "Library.h"

namespace Network
{
	CommandStruct Command::Struct[6];

	std::string Command::Msg(255, ' ');
	unsigned long Command::Calcule;
	unsigned long Command::Delay;
	unsigned char Command::Count;

	bool Command::initComponents()
	{
		int i;
		Tokenizer _command(".\\Network\\Command.ut");

		if(_command.Loaded)
		{
			if(!_command.SectionExists(0))
			{
				return false;
			}
			else if(!_command.SectionExists(1))
			{
				return false;
			}
			else if(!_command.SectionExists(2))
			{
				return false;
			}
			else if(!_command.SectionExists(3))
			{
				return false;
			}
			else if(!_command.SectionExists(4))
			{
				return false;
			}
			else if(!_command.SectionExists(5))
			{
				return false;
			}
			else if(!_command.SectionExists(6))
			{
				return false;
			}
			else if(!_command.SectionExists(7))
			{
				return false;
			}
			else if(!_command.SectionExists(8))
			{
				return false;
			}
			else if(!_command.SectionExists(9))
			{
				return false;
			}
			else if(!_command.SectionExists(10))
			{
				return false;
			}
			else if(!_command.SectionExists(11))
			{
				return false;
			}
			else if(!_command.SectionExists(12))
			{
				return false;
			}
			else if(!_command.SectionExists(13))
			{
				return false;
			}
			else if(!_command.SectionExists(14))
			{
				return false;
			}
			else if(!_command.SectionExists(15))
			{
				return false;
			}
			else if(!_command.SectionExists(16))
			{
				return false;
			}
			else if(!_command.SectionExists(17))
			{
				return false;
			}
			else if(!_command.SectionExists(18))
			{
				return false;
			}
			else if(!_command.SectionExists(19))
			{
				return false;
			}
			else if(!_command.SectionExists(20))
			{
				return false;
			}
			else if(!_command.SectionExists(21))
			{
				return false;
			}
			else if(!_command.SectionExists(22))
			{
				return false;
			}
			else if(!Reset::initComponents())
			{
				return false;
			}
			else if(!Master::initComponents())
			{
				return false;
			}
			else if(!Marry::initComponents())
			{
				return false;
			}
			else
			{
				Struct[0].Post.String = _command[0][0][0].ToString();
				Struct[0].Post.Format = _command[0][0][1].ToString();
				Struct[0].Post.Color  = (unsigned char)_command[0][0][2].ToInteger();

				Struct[0].Status.String = _command[1][0][0].ToString();

				Struct[0].Zen.String = _command[2][0][0].ToString();

				Struct[0].Points.String = _command[3][0][0].ToString();

				Struct[0].Website.String = _command[4][0][0].ToString();

				Struct[0].Online.String = _command[5][0][0].ToString();

				Struct[0].Data.String = _command[6][0][0].ToString();

				Struct[0].Add.String = _command[7][0][0].ToString();
				Struct[1].Add.String = _command[7][0][1].ToString();
				Struct[2].Add.String = _command[7][0][2].ToString();
				Struct[3].Add.String = _command[7][0][3].ToString();
				
				Struct[0].ReAdd.String = _command[8][0][0].ToString();

				Struct[0].Select.String = _command[9][0][0].ToString();
				Struct[1].Select.String = _command[9][0][1].ToString();
				Struct[2].Select.String = _command[9][0][2].ToString();

				Struct[0].Warehouse.String = _command[10][0][0].ToString();

				Struct[0].Evo.String = _command[11][0][0].ToString();

				Struct[0].Class.String = _command[12][0][0].ToString();

				Struct[0].Repair.String = _command[13][0][0].ToString();
				Struct[1].Repair.String = _command[13][0][1].ToString();

				Struct[0].Clear.String = _command[14][0][0].ToString();
				Struct[1].Clear.String = _command[14][0][1].ToString();

				Struct[0].Name.String = _command[15][0][0].ToString();
				Struct[0].Name.Pattern = _command[15][0][1].ToString();

				for(i = 0; i < 6; i++)
				{
					Struct[i].Post.Enable		= (unsigned char)_command[0][(i + 1)][0].ToInteger();
					Struct[i].Post.Level		= (unsigned short)_command[0][(i + 1)][1].ToInteger();
					Struct[i].Post.Price		= (unsigned int)_command[0][(i + 1)][2].ToInteger();
					Struct[i].Post.Reset		= (unsigned long)_command[0][(i + 1)][3].ToInteger();
					Struct[i].Post.Delay		= (unsigned long)_command[0][(i + 1)][4].ToInteger();

					Struct[i].Status.Enable		= (unsigned char)_command[1][(i + 1)][0].ToInteger();
					Struct[i].Status.Level		= (unsigned short)_command[1][(i + 1)][1].ToInteger();
					Struct[i].Status.Price		= (unsigned int)_command[1][(i + 1)][2].ToInteger();
					Struct[i].Status.Reset		= (unsigned long)_command[1][(i + 1)][3].ToInteger();
					Struct[i].Status.Delay		= (unsigned long)_command[1][(i + 1)][4].ToInteger();

					Struct[i].Zen.Enable		= (unsigned char)_command[2][(i + 1)][0].ToInteger();
					Struct[i].Zen.Level			= (unsigned short)_command[2][(i + 1)][1].ToInteger();
					Struct[i].Zen.Reset			= (unsigned long)_command[2][(i + 1)][2].ToInteger();
					Struct[i].Zen.Delay			= (unsigned long)_command[2][(i + 1)][3].ToInteger();

					Struct[i].Points.Enable		= (unsigned char)_command[3][(i + 1)][0].ToInteger();
					Struct[i].Points.Level		= (unsigned short)_command[3][(i + 1)][1].ToInteger();
					Struct[i].Points.Price		= (unsigned int)_command[3][(i + 1)][2].ToInteger();
					Struct[i].Points.Reset		= (unsigned long)_command[3][(i + 1)][3].ToInteger();
					Struct[i].Points.Delay		= (unsigned long)_command[3][(i + 1)][4].ToInteger();

					Struct[i].Website.Enable	= (unsigned char)_command[4][(i + 1)][0].ToInteger();
					Struct[i].Website.Level		= (unsigned short)_command[4][(i + 1)][1].ToInteger();
					Struct[i].Website.Price		= (unsigned int)_command[4][(i + 1)][2].ToInteger();
					Struct[i].Website.Reset		= (unsigned long)_command[4][(i + 1)][3].ToInteger();
					Struct[i].Website.Delay		= (unsigned long)_command[4][(i + 1)][4].ToInteger();

					Struct[i].Online.Enable		= (unsigned char)_command[5][(i + 1)][0].ToInteger();
					Struct[i].Online.Level		= (unsigned short)_command[5][(i + 1)][1].ToInteger();
					Struct[i].Online.Price		= (unsigned int)_command[5][(i + 1)][2].ToInteger();
					Struct[i].Online.Reset		= (unsigned long)_command[5][(i + 1)][3].ToInteger();
					Struct[i].Online.Delay		= (unsigned long)_command[5][(i + 1)][4].ToInteger();

					Struct[i].Data.Enable		= (unsigned char)_command[6][(i + 1)][0].ToInteger();
					Struct[i].Data.Level		= (unsigned short)_command[6][(i + 1)][1].ToInteger();
					Struct[i].Data.Price		= (unsigned int)_command[6][(i + 1)][2].ToInteger();
					Struct[i].Data.Reset		= (unsigned long)_command[6][(i + 1)][3].ToInteger();
					Struct[i].Data.Delay		= (unsigned long)_command[6][(i + 1)][4].ToInteger();

					Struct[i].Add.Enable		= (unsigned char)_command[7][(i + 1)][0].ToInteger();
					Struct[i].Add.Level			= (unsigned short)_command[7][(i + 1)][1].ToInteger();
					Struct[i].Add.Price			= (unsigned int)_command[7][(i + 1)][2].ToInteger();
					Struct[i].Add.Reset			= (unsigned long)_command[7][(i + 1)][3].ToInteger();
					Struct[i].Add.Delay			= (unsigned long)_command[7][(i + 1)][4].ToInteger();

					Struct[i].ReAdd.Enable		= (unsigned char)_command[8][(i + 1)][0].ToInteger();
					Struct[i].ReAdd.Level		= (unsigned short)_command[8][(i + 1)][1].ToInteger();
					Struct[i].ReAdd.Price		= (unsigned int)_command[8][(i + 1)][2].ToInteger();
					Struct[i].ReAdd.Reset		= (unsigned long)_command[8][(i + 1)][3].ToInteger();
					Struct[i].ReAdd.Delay		= (unsigned long)_command[8][(i + 1)][4].ToInteger();

					Struct[i].Select.Enable		= (unsigned char)_command[9][(i + 1)][0].ToInteger();
					Struct[i].Select.Level		= (unsigned short)_command[9][(i + 1)][1].ToInteger();
					Struct[i].Select.Price		= (unsigned int)_command[9][(i + 1)][2].ToInteger();
					Struct[i].Select.Reset		= (unsigned long)_command[9][(i + 1)][3].ToInteger();
					Struct[i].Select.Delay		= (unsigned long)_command[9][(i + 1)][4].ToInteger();

					Struct[i].Warehouse.Enable	= (unsigned char)_command[10][(i + 1)][0].ToInteger();
					Struct[i].Warehouse.Level	= (unsigned short)_command[10][(i + 1)][1].ToInteger();
					Struct[i].Warehouse.Price	= (unsigned int)_command[10][(i + 1)][2].ToInteger();
					Struct[i].Warehouse.Reset	= (unsigned long)_command[10][(i + 1)][3].ToInteger();
					Struct[i].Warehouse.Delay	= (unsigned long)_command[10][(i + 1)][4].ToInteger();

					Struct[i].Evo.Enable		= (unsigned char)_command[11][(i + 1)][0].ToInteger();
					Struct[i].Evo.Level			= (unsigned short)_command[11][(i + 1)][1].ToInteger();
					Struct[i].Evo.Price			= (unsigned int)_command[11][(i + 1)][2].ToInteger();
					Struct[i].Evo.Reset			= (unsigned long)_command[11][(i + 1)][3].ToInteger();
					Struct[i].Evo.Delay			= (unsigned long)_command[11][(i + 1)][4].ToInteger();

					Struct[i].Class.Enable		= (unsigned char)_command[12][(i + 1)][0].ToInteger();
					Struct[i].Class.Level		= (unsigned short)_command[12][(i + 1)][1].ToInteger();
					Struct[i].Class.Price		= (unsigned int)_command[12][(i + 1)][2].ToInteger();
					Struct[i].Class.Reset		= (unsigned long)_command[12][(i + 1)][3].ToInteger();
					Struct[i].Class.Delay		= (unsigned long)_command[12][(i + 1)][4].ToInteger();

					Struct[i].Repair.Enable		= (unsigned char)_command[13][(i + 1)][0].ToInteger();
					Struct[i].Repair.Level		= (unsigned short)_command[13][(i + 1)][1].ToInteger();
					Struct[i].Repair.Price		= (unsigned int)_command[13][(i + 1)][2].ToInteger();
					Struct[i].Repair.Reset		= (unsigned long)_command[13][(i + 1)][3].ToInteger();
					Struct[i].Repair.Delay		= (unsigned long)_command[13][(i + 1)][4].ToInteger();

					Struct[i].Clear.Enable		= (unsigned char)_command[14][(i + 1)][0].ToInteger();
					Struct[i].Clear.Level		= (unsigned short)_command[14][(i + 1)][1].ToInteger();
					Struct[i].Clear.Price		= (unsigned int)_command[14][(i + 1)][2].ToInteger();
					Struct[i].Clear.Reset		= (unsigned long)_command[14][(i + 1)][3].ToInteger();
					Struct[i].Clear.Delay		= (unsigned long)_command[14][(i + 1)][4].ToInteger();

					Struct[i].Name.Enable		= (unsigned char)_command[15][(i + 1)][0].ToInteger();
					Struct[i].Name.Level		= (unsigned short)_command[15][(i + 1)][1].ToInteger();
					Struct[i].Name.Price		= (unsigned int)_command[15][(i + 1)][2].ToInteger();
					Struct[i].Name.Reset		= (unsigned long)_command[15][(i + 1)][3].ToInteger();
					Struct[i].Name.Delay		= (unsigned long)_command[15][(i + 1)][4].ToInteger();
				}

				Count = (_command[16].RowCount > 25) ? 25 : (BYTE)_command[11].RowCount;
				for(int n = 0; n < (int)Count; n++)
				{
					Struct[0].Move[n].String = _command[16][n][0].ToString();
					Struct[0].Move[n].Enable = (unsigned char)_command[16][n][1].ToInteger();
					Struct[0].Move[n].Level	 = (unsigned short)_command[16][n][2].ToInteger();
					Struct[0].Move[n].Price	 = (unsigned int)_command[16][n][3].ToInteger();
					Struct[0].Move[n].Reset	 = (unsigned long)_command[16][n][4].ToInteger();
					Struct[0].Move[n].Vip	 = (unsigned char)_command[16][n][5].ToInteger();
					Struct[0].Move[n].GM	 = (unsigned char)_command[16][n][6].ToInteger();
					Struct[0].Move[n].PK	 = (unsigned char)_command[16][n][7].ToInteger();
					Struct[0].Move[n].Map	 = (unsigned char)_command[16][n][8].ToInteger();
					Struct[0].Move[n].X		 = (unsigned char)_command[16][n][9].ToInteger();
					Struct[0].Move[n].Y		 = (unsigned char)_command[16][n][10].ToInteger();
				}

				Marry::String[0]	= _command[17][0][1].ToString();
				Marry::String[1]	= _command[17][0][2].ToString();
				Marry::Enable		= (_command[17][0][0].ToInteger() == 1) ? true : false;

				Struct[0].Reload.String = _command[18][0][2].ToString();
				Struct[0].Reload.Enable = (unsigned char)_command[18][0][0].ToInteger();
				Struct[0].Reload.Delay  = (unsigned long)_command[18][0][1].ToInteger();
				Struct[0].Reload.Index  = 0;
				
				Struct[0].Block.String = _command[19][0][2].ToString();
				Struct[1].Block.String = _command[19][0][3].ToString();
				Struct[2].Block.String = _command[19][0][4].ToString();
				Struct[3].Block.String = _command[19][0][5].ToString();
				Struct[0].Block.Enable = (unsigned char)_command[19][0][0].ToInteger();
				Struct[0].Block.Delay  = (unsigned long)_command[19][0][1].ToInteger();

				Struct[0].Teleport.String = _command[20][0][2].ToString();
				Struct[1].Teleport.String = _command[20][0][3].ToString();
				Struct[2].Teleport.String = _command[20][0][4].ToString();
				Struct[3].Teleport.String = _command[20][0][5].ToString();
				Struct[0].Teleport.Enable = (unsigned char)_command[20][0][0].ToInteger();
				Struct[0].Teleport.Delay  = (unsigned long)_command[20][0][1].ToInteger();

				Struct[0].Skin.String = _command[21][0][2].ToString();
				Struct[0].Skin.Enable = (unsigned char)_command[21][0][0].ToInteger();
				Struct[0].Skin.Delay  = (unsigned long)_command[21][0][1].ToInteger();

				Struct[0].Firework.String = _command[22][0][2].ToString();
				Struct[0].Firework.Enable = (unsigned char)_command[22][0][0].ToInteger();
				Struct[0].Firework.Delay  = (unsigned long)_command[22][0][1].ToInteger();
			}
		}

		return true;
	}

	bool Command::initGuild(DWORD dwIndex, std::string szMsg)
	{
		int szLength = strlen(Object[dwIndex].GuildName);

		if(szMsg.empty() || szMsg.length() < 2)
		{
			return false;
		}

		for(int i = 0; i < (int)(szMsg.length() - 1); i++)
		{
			if(boost::iequals(&szMsg.c_str()[i], Object[dwIndex].GuildName))
			{
				return false;
			}
		}

		return true;
	}

	void Command::initPost(DWORD dwIndex, std::string szMsg)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Post.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Post) / 1000;

			if(Struct[szVip].Post.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Post.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Post.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Post.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Post.Delay > Delay)
			{
				Calcule = Struct[szVip].Post.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(szMsg.empty())
			{
				ServerMessageSend((char*)Message::Post[0].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Post.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Post.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Post.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Post = GetTickCount();

				if(boost::iequals(szMsg, "ativar"))
				{
					Player[szIndex].Post = true;
					ServerMessageSend((char*)Message::Post[1].c_str(), dwIndex, 1);
				}
				else if(boost::iequals(szMsg, "desativar"))
				{
					Player[szIndex].Post = false;
					ServerMessageSend((char*)Message::Post[2].c_str(), dwIndex, 1);
				}
				else
				{
					if(Player[szIndex].Post)
					{
						char MsgEx[255];
						memset(&MsgEx[0], 0x00, 255);
						sprintf_s(MsgEx, 255, Struct[0].Post.Format.c_str(), Object[dwIndex].Name, szMsg.c_str());
						
						BYTE btBuffer[255] = {0};
						BYTE btLength = (BYTE)strlen(MsgEx);
						memset(&btBuffer[0], 0x00, 255);

						btBuffer[0] = 0xC1;

						if(Struct[0].Post.Color == 0)
						{
							btBuffer[1] = (btLength + 0x0E);
							btBuffer[2] = 0x02;
							strncpy_s((char*)&btBuffer[13], 241, MsgEx, btLength);
						}
						else
						{
							btBuffer[1] = (btLength + 0x0F);
							btBuffer[2] = 0x00;
							btBuffer[13] = (Struct[0].Post.Color == 1) ? 0x40 : 0x7E;
							strncpy_s((char*)&btBuffer[14], 240, MsgEx, btLength);
						}
						
						for(int i = 4800; i < 5800; i++)
						{
							if(Object[i].Connected > 2)
							{
								WORD Count = (i - 4800);

								if(Player[Count].Post == 1)
								{
									ServerDataSend(i, (unsigned char*)btBuffer, (DWORD)btBuffer[1]);
								}
							}
						}

						if(Struct[szVip].Post.Price > 0)
						{
							Object[dwIndex].Money -= Struct[szVip].Post.Price;
							ServerMoneySend(dwIndex, Object[dwIndex].Money);
						}
					}
				}
			}
		}
	}

	void Command::initStatus(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Status.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Status) / 1000;

			if(Struct[szVip].Status.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Status.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Status.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Status.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Status.Delay > Delay)
			{
				Calcule = Struct[szVip].Status.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Object[dwIndex].PkLevel == 3)
			{
				ServerMessageSend((char*)Message::Status[0].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Status.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Status.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Status.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Status = GetTickCount();

				if(Object[dwIndex].PkCount != 0)
				{
					BYTE btNum = (Object[dwIndex].PkLevel < 3) ? 0 : 1;
					DWORD dwKills = ((Object[dwIndex].PkCount * (-1)) < 0) ?  Object[dwIndex].PkCount : (Object[dwIndex].PkCount * (-1));
					
					Connect::executeQuery(Query::Status[btNum], dwKills, dwKills, dwKills, dwKills, Object[dwIndex].Name);
				}

				Object[dwIndex].PkLevel = 3;
				Object[dwIndex].PkCount = 0;
				Object[dwIndex].PkTime  = 0;

				if(Struct[szIndex].Status.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szIndex].Status.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				ServerPkSend(dwIndex, Object[dwIndex].PkLevel);
				ServerMessageSend((char*)Message::Status[1].c_str(), dwIndex, 1);
			}
		}
	}

	void Command::initNpcStatus(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpNpc)
	{
		WORD szIndex = (WORD)(lpObject->m_Index - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Status.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Status) / 1000;

			if(Struct[szVip].Status.Level > lpObject->Level)
			{
				Calcule = Struct[szVip].Status.Level - lpObject->Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else if(Struct[szVip].Status.Price > lpObject->Money)
			{
				Calcule = Struct[szVip].Status.Price - lpObject->Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else if(Struct[szVip].Status.Delay > Delay)
			{
				Calcule = Struct[szVip].Status.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
			}
			else if(lpObject->PkLevel == 3)
			{
				ServerNpcTalkSend(lpNpc, (char*)Message::Status[0].c_str(), lpObject->m_Index);
			}
			else
			{
				if(Struct[szVip].Status.Reset > 0)
				{
					Function::updateReset(lpObject->m_Index);
					
					if(Struct[szVip].Status.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Status.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerNpcTalkSend(lpNpc, (char*)Msg.c_str(), lpObject->m_Index);
						return;
					}
				}

				Player[szIndex].Delay.Status = GetTickCount();

				if(lpObject->PkCount != 0)
				{
					BYTE btNum = (lpObject->PkLevel < 3) ? 0 : 1;
					DWORD dwKills = ((lpObject->PkCount * (-1)) < 0) ?  lpObject->PkCount : (lpObject->PkCount * (-1));
					
					Connect::executeQuery(Query::Status[btNum], dwKills, dwKills, dwKills, dwKills, lpObject->Name);
				}

				lpObject->PkLevel = 3;
				lpObject->PkCount = 0;
				lpObject->PkTime  = 0;

				if(Struct[szIndex].Status.Price > 0)
				{
					lpObject->Money -= Struct[szIndex].Status.Price;
					ServerMoneySend(lpObject->m_Index, lpObject->Money);
				}

				ServerPkSend(lpObject->m_Index, lpObject->PkLevel);
				ServerNpcTalkSend(lpNpc, (char*)Message::Status[1].c_str(), lpObject->m_Index);
			}
		}
	}

	void Command::initZen(DWORD dwIndex, std::string szMsg)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Zen.Enable == 1)
		{
			if(Object[dwIndex].Money > 2147000000)
			{
				Object[dwIndex].Money = 0;
			}

			Delay = (GetTickCount() - Player[szIndex].Delay.Zen) / 1000;

			if(Struct[szVip].Zen.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Zen.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Zen.Delay > Delay)
			{
				Calcule = Struct[szVip].Zen.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(szMsg.empty())
			{
				ServerMessageSend((char*)Message::Zen[0].c_str(), dwIndex, 1);
			}
			else if(Object[dwIndex].Money >= 2100000000)
			{
				ServerMessageSend((char*)Message::Zen[1].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Zen.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Zen.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Zen.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Zen = GetTickCount();

				DWORD dwZen = atoi(szMsg.c_str());

				if(dwZen > 0)
				{
					if((Object[dwIndex].Money + dwZen) >= 2100000000)
					{
						Object[dwIndex].Money = 2100000000;
						
						if(dwZen > 2100000000)
						{
							dwZen = 2100000000;
						}
						else
						{
							dwZen = (2100000000 - dwZen);
						}
					}
					else
					{
						Object[dwIndex].Money += (unsigned int)dwZen;
					}

					ServerMoneySend(dwIndex, Object[dwIndex].Money);

					sprintf_s(&Msg[0], 255, &Message::Zen[2][0], dwZen);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
			}
		}
	}

	void Command::initPoints(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Points.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Points) / 1000;

			if(Struct[szVip].Points.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Points.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Points.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Points.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Points.Delay > Delay)
			{
				Calcule = Struct[szVip].Points.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Points.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Points.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Points.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Points = GetTickCount();

				sprintf_s(&Msg[0], 255, &Message::Points[0][0], Object[dwIndex].Strength);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

				sprintf_s(&Msg[0], 255, &Message::Points[1][0], Object[dwIndex].Agility);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

				sprintf_s(&Msg[0], 255, &Message::Points[2][0], Object[dwIndex].Vitality);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

				sprintf_s(&Msg[0], 255, &Message::Points[3][0], Object[dwIndex].Energy);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

				sprintf_s(&Msg[0], 255, &Message::Points[4][0], Object[dwIndex].LevelUpPoint);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				
				if(Struct[szVip].Points.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Points.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}
			}
		}
	}

	void Command::initWebsite(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Website.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Website) / 1000;

			if(Struct[szVip].Website.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Website.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Website.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Website.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Website.Delay > Delay)
			{
				Calcule = Struct[szVip].Website.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Website.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Website.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Website.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Website = GetTickCount();

				ServerMessageSend((char*)Message::Website.c_str(), dwIndex, 0);
				
				if(Struct[szVip].Website.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Website.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}
			}
		}
	}

	void Command::initOnline(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Online.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Online) / 1000;

			if(Struct[szVip].Online.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Online.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Online.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Online.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Online.Delay > Delay)
			{
				Calcule = Struct[szVip].Online.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Online.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Online.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Online.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Online = GetTickCount();

				WORD wdPlayer = 0, wdGM = 0;

				for(int i = 4800; i < 5800; i++)
				{
					if(Object[i].Connected > 2)
					{
						if(Object[i].Authority > 1)
						{
							wdGM++;
						}
						else
						{
							wdPlayer++;
						}
					}
				}

				sprintf_s(&Msg[0], 255, &Message::Online[0][0], wdPlayer);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

				sprintf_s(&Msg[0], 255, &Message::Online[1][0], wdGM);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
					
				sprintf_s(&Msg[0], 255, &Message::Online[2][0], (wdPlayer + wdGM));
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				
				if(Struct[szVip].Online.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Online.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}
			}
		}
	}

	void Command::initData(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Data.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Data) / 1000;

			if(Struct[szVip].Data.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Data.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Data.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Data.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Data.Delay > Delay)
			{
				Calcule = Struct[szVip].Data.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Data.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Data.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Data.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Data = GetTickCount();

				struct tm szSystem;
				time_t szTime = time(NULL);
				errno_t szError;
				szError = localtime_s(&szSystem, &szTime);

				if(!szError)
				{
					sprintf_s(&Msg[0], 255, &Message::Data[3][0], &Struct[0].Data.Day[szSystem.tm_wday][0], szSystem.tm_mday, &Struct[0].Data.Month[szSystem.tm_mon][0], (szSystem.tm_year + 1900));
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

					BYTE btTime = (szSystem.tm_hour > 11) ? (BYTE)(szSystem.tm_hour - 12) : (BYTE)szSystem.tm_hour;
					sprintf_s(&Msg[0], 255, &Message::Data[4][0], btTime, szSystem.tm_min, (btTime > 11) ? "PM" : "AM");
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

					if(Struct[szVip].Data.Price > 0)
					{
						Object[dwIndex].Money -= Struct[szVip].Data.Price;
						ServerMoneySend(dwIndex, Object[dwIndex].Money);
					}
				}
				else
				{
					ServerMessageSend((char*)Message::Data[0].c_str(), dwIndex, 1);
				}
			}
		}
	}

	void Command::initAdd(DWORD dwIndex, std::string szMsg, BYTE btStatus)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Add.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Add) / 1000;

			if(Struct[szVip].Add.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Add.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Add.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Add.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Add.Delay > Delay)
			{
				Calcule = Struct[szVip].Add.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(szMsg.empty())
			{
				ServerMessageSend((char*)Message::Add[0].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Add.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Add.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Add.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				UINT itPoints = atoi(szMsg.c_str());

				if(itPoints > 0)
				{
					if(itPoints > Object[dwIndex].LevelUpPoint)
					{
						ServerMessageSend((char*)Message::Add[1].c_str(), dwIndex, 1);
						return;
					}

					WORD wdStatus = (Setting::Struct.Status == 1) ? 65534 : 32766;

					switch(btStatus)
					{
					case 0:
						{
							if((unsigned int)(Object[dwIndex].Strength + itPoints) > (unsigned int)(wdStatus + 1))
							{
								ServerMessageSend((char*)Message::Add[2].c_str(), dwIndex, 1);
								return;
							}
						}break;
					case 1:
						{
							if((unsigned int)(Object[dwIndex].Agility + itPoints) > (unsigned int)(wdStatus + 1))
							{
								ServerMessageSend((char*)Message::Add[2].c_str(), dwIndex, 1);
								return;
							}
						}break;
					case 2:
						{
							if((unsigned int)(Object[dwIndex].Vitality + itPoints) > (unsigned int)(wdStatus + 1))
							{
								ServerMessageSend((char*)Message::Add[2].c_str(), dwIndex, 1);
								return;
							}
						}break;
					case 3:
						{
							if((unsigned int)(Object[dwIndex].Energy + itPoints) > (unsigned int)(wdStatus + 1))
							{
								ServerMessageSend((char*)Message::Add[2].c_str(), dwIndex, 1);
								return;
							}
						}break;
					}

					Player[szIndex].Delay.Add = GetTickCount();

					if(itPoints > 100)
					{
						Object[dwIndex].LevelUpPoint -= itPoints;

						switch(btStatus)
						{
						case 0:
							{
								Object[dwIndex].Strength += (unsigned short)itPoints;
							}break;
						case 1:
							{
								Object[dwIndex].Agility += (unsigned short)itPoints;
							}break;
						case 2:
							{
								Object[dwIndex].Vitality += (unsigned short)itPoints;
							}break;
						case 3:
							{
								Object[dwIndex].Energy += (unsigned short)itPoints;
							}break;
						}

						Calcule::initCharacter(dwIndex);
						ServerMessageSend((char*)Message::Add[4].c_str(), dwIndex, 1);
					}
					else
					{
						PMSG_LVPOINTADD lpMsg;
						lpMsg.h.c		= 0xC1;
						lpMsg.h.head	= 0xF3;
						lpMsg.h.size	= 0x05;
						lpMsg.Sub		= 0x06;
						lpMsg.Type		= (BYTE)btStatus;

						for(int i = 0; i < (int)itPoints; i++)
						{
							ServerLevelUpPointAdd(&lpMsg, dwIndex);
						}

						ServerMessageSend((char*)Message::Add[3].c_str(), dwIndex, 1);								
					}

					if(Struct[szVip].Add.Price > 0)
					{
						Object[dwIndex].Money -= Struct[szVip].Add.Price;
						ServerMoneySend(dwIndex, Object[dwIndex].Money);
					}
				}
			}
		}
	}

	void Command::initReAdd(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].ReAdd.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.ReAdd) / 1000;

			if(Struct[szVip].ReAdd.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].ReAdd.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].ReAdd.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].ReAdd.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].ReAdd.Delay > Delay)
			{
				Calcule = Struct[szVip].ReAdd.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Add.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Add.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Add.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				UINT uiPoints;

				uiPoints = ((Object[dwIndex].Strength + Object[dwIndex].Agility) + (Object[dwIndex].Vitality + Object[dwIndex].Energy)) - 100;

				if(uiPoints <= 0)
				{
					ServerMessageSend((char*)Message::ReAdd[0].c_str(), dwIndex, 1);
					return;
				}
				
				Player[szIndex].Delay.ReAdd = GetTickCount();

				uiPoints += Object[dwIndex].LevelUpPoint;

				Object[dwIndex].LevelUpPoint = uiPoints >= 4294967290 ? 4294967290 : uiPoints;
				Object[dwIndex].Strength = 25;
				Object[dwIndex].Agility = 25;
				Object[dwIndex].Vitality = 25;
				Object[dwIndex].Energy = 25;

				if(Struct[szVip].ReAdd.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].ReAdd.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				ServerMessageSend((char*)Message::ReAdd[1].c_str(), dwIndex, 1);
			
				ServerCloseClient(dwIndex, 1);
			}
		}
	}

	void Command::initSelect(DWORD dwIndex, BYTE btSelect)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Select.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Select) / 1000;

			if(Struct[szVip].Select.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Select.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Select.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Select.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Select.Delay > Delay)
			{
				Calcule = Struct[szVip].Select.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Select.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Select.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Select.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Select = GetTickCount();

				ServerMessageSend((char*)Message::Select[btSelect].c_str(), dwIndex, 1);

				if(Struct[szVip].Select.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Select.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				ServerCloseClient(dwIndex, (DWORD)btSelect);
			}
		}
	}

	void Command::initWarehouse(DWORD dwIndex, std::string szMsg)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Warehouse.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Warehouse) / 1000;

			if(Struct[szVip].Warehouse.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Warehouse.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Warehouse.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Warehouse.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Warehouse.Delay > Delay)
			{
				Calcule = Struct[szVip].Warehouse.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(szMsg.empty())
			{
				ServerMessageSend((char*)Message::Warehouse[0].c_str(), dwIndex, 1);
			}
			else if(Object[dwIndex].WarehouseSave == 1)
			{
				ServerMessageSend((char*)Message::Warehouse[4].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Warehouse.Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[szVip].Warehouse.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Warehouse.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				DWORD dwWarehouse = (DWORD)atoi(szMsg.c_str());

				if(dwWarehouse == 0)
				{
					return;
				}

				Connect::executeQuery(Query::Warehouse[0], Object[dwIndex].AccountID, dwWarehouse);
				Connect::executeQuery(Query::Warehouse[1], Object[dwIndex].AccountID);
				BYTE btResult = (BYTE)Connect::getInteger(1);

				switch(btResult)
				{
				case 1:
					{
						sprintf_s(&Msg[0], 255, &Message::Warehouse[1][0], dwWarehouse);
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
					}break;
				case 2:
					{
						sprintf_s(&Msg[0], 255, &Message::Warehouse[2][0], dwWarehouse);
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
					}break;
				case 3:
					{
						Player[szIndex].Delay.Warehouse = GetTickCount();

						sprintf_s(&Msg[0], 255, &Message::Warehouse[5][0], dwWarehouse);
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

						if(Struct[szVip].Warehouse.Price > 0)
						{
							Object[dwIndex].Money -= Struct[szVip].Warehouse.Price;
							ServerMoneySend(dwIndex, Object[dwIndex].Money);
						}
					}break;
				default:
					{
						ServerMessageSend((char*)Message::Warehouse[3].c_str(), dwIndex, 1);
					}break;
				}
			}
		}
	}

	void Command::initEvo(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Evo.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Evo) / 1000;

			if(Struct[szVip].Evo.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Evo.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Evo.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Evo.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Evo.Delay > Delay)
			{
				Calcule = Struct[szVip].Evo.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Evo.Reset > 0)
				{
					Function::updateReset(dwIndex);

					if(Struct[szVip].Evo.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Evo.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				switch(Object[dwIndex].Class)
				{
					case 0:
						{
							if(Object[dwIndex].DbClass == 1)
							{
								ServerMessageSend((char*)Message::Evo[0].c_str(), dwIndex, 1);
								return;
							}

							Object[dwIndex].DbClass = 1;
							
							sprintf_s(&Msg[0], 255, &Message::Evo[2][0], "Soul Master");
							ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						}break;
					case 1:
						{
							if(Object[dwIndex].DbClass == 17)
							{
								ServerMessageSend((char*)Message::Evo[0].c_str(), dwIndex, 1);
								return;
							}

							Object[dwIndex].DbClass = 17;

							sprintf_s(&Msg[0], 255, &Message::Evo[2][0], "Blade Knight");
							ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						}break;
					case 2:
						{
							if(Object[dwIndex].DbClass == 33)
							{
								ServerMessageSend((char*)Message::Evo[0].c_str(), dwIndex, 1);
								return;
							}
						
							Object[dwIndex].DbClass = 33;

							sprintf_s(&Msg[0], 255, &Message::Evo[2][0], "Muse Elf");
							ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						}break;
					case 3:
						{
							ServerMessageSend((char*)Message::Evo[1].c_str(), dwIndex, 1);
							return;
						}break;
				}
			
				if(Struct[szVip].Evo.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Evo.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				Object[dwIndex].m_Quest[0] = 0xFA;

				ServerCloseClient(dwIndex, 1);
			}
		}
	}

	void Command::initClass(DWORD dwIndex, std::string szMsg)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Class.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Class) / 1000;

			if(Struct[szVip].Class.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Class.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Class.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Class.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Class.Delay > Delay)
			{
				Calcule = Struct[szVip].Class.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(szMsg.empty())
			{
				ServerMessageSend((char*)Message::Class[0].c_str(), dwIndex, 1);
				ServerMessageSend((char*)Message::Class[1].c_str(), dwIndex, 1);
				ServerMessageSend((char*)Message::Class[2].c_str(), dwIndex, 1);
				ServerMessageSend((char*)Message::Class[3].c_str(), dwIndex, 1);
				ServerMessageSend((char*)Message::Class[4].c_str(), dwIndex, 1);
			}
			else if(Marry::Struct[szIndex].Married)
			{
				ServerMessageSend((char*)Message::Default[2].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Class.Reset > 0)
				{
					Function::updateReset(dwIndex);

					if(Struct[szVip].Class.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Class.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}
				
				bool szProceed = true;

				for(int i = 0; i < 12; i++)
				{
					if(Object[dwIndex].pInventory[i].m_Number != 0 || Object[dwIndex].pInventory[i].m_Level != 0 || (char)Object[dwIndex].pInventory[i].m_Type != (-1))
					{
						szProceed = false;
						break;
					}
				}

				if(!szProceed)
				{
					ServerMessageSend((char*)Message::Class[5].c_str(), dwIndex, 1);
					return;
				}

				int szClass[2] = {0};
				std::string szClassName = "";

				if(boost::iequals(szMsg, "DW") || boost::iequals(szMsg, "SM"))
				{
					szClass[0] = (boost::iequals(szMsg, "DW")) ? 0 : 1;
					szClass[1] = 0;
					szClassName = (szClass[0] == 0) ? "Dark Wizard" : "Soul Master";
				}
				else if(boost::iequals(szMsg, "DK") || boost::iequals(szMsg, "BK"))
				{
					szClass[0] = (boost::iequals(szMsg, "DK")) ? 16 : 17;
					szClass[1] = 1;
					szClassName = (szClass[0] == 16) ? "Dark Knight" : "Blade Knight";
				}
				else if(boost::iequals(szMsg, "FE") || boost::iequals(szMsg, "ME"))
				{
					szClass[0] = (boost::iequals(szMsg, "FE")) ? 32 : 33;
					szClass[1] = 2;
					szClassName = (szClass[0] == 0) ? "Fairy Elf" : "Muse Elf";
				}
				else if(boost::iequals(szMsg, "MG"))
				{
					szClass[0] = 48;
					szClass[1] = 3;
					szClassName = "Magic Gladiator";
				}
				else
				{
					ServerMessageSend((char*)Message::Class[0].c_str(), dwIndex, 1);
					ServerMessageSend((char*)Message::Class[1].c_str(), dwIndex, 1);
					ServerMessageSend((char*)Message::Class[2].c_str(), dwIndex, 1);
					ServerMessageSend((char*)Message::Class[3].c_str(), dwIndex, 1);
					ServerMessageSend((char*)Message::Class[4].c_str(), dwIndex, 1);
					return;
				}

				Player[szIndex].Delay.Class = GetTickCount();

				Object[dwIndex].Class = szClass[1];
				Object[dwIndex].DbClass = szClass[0];

				if(Struct[szVip].Class.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Class.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				if(szClass[0] == 0 || szClass[0] == 16 || szClass[0] == 32)
				{
					Object[dwIndex].m_Quest[0] = 0xFF;
				}
				else
				{
					if(szClass[0] != 48)
					{
						Object[dwIndex].m_Quest[0] = 0xFA;
					}
				}

				sprintf_s(&Msg[0], 255, &Message::Class[6][0], &szClassName[0]);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);

				ServerCloseClient(dwIndex, 1);
			}
		}
		else
		{
			return;
		}
	}

	void Command::initRepair(DWORD dwIndex, BYTE btLocal)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Repair.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Repair) / 1000;

			if(Struct[szVip].Repair.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Repair.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Repair.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Repair.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Repair.Delay > Delay)
			{
				Calcule = Struct[szVip].Repair.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Repair.Reset > 0)
				{
					Function::updateReset(dwIndex);

					if(Struct[szVip].Repair.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Repair.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Repair = GetTickCount();

				std::string szLocal = "";

				switch(btLocal)
				{
				case 1:
					{
						if(Object[dwIndex].WarehouseSave == 1 && Object[dwIndex].m_IfState.use == 1 && Object[dwIndex].m_IfState.state == 1 && Object[dwIndex].m_IfState.type == 6)
						{
							for(int i = 0; i < 120; i++)
							{
								ServerRepairItems(&Object[dwIndex], &Object[dwIndex].pWarehouse[i], i, 1);
							}

							szLocal = "Baú";
							Object[dwIndex].m_IfState.state = 0;
							ServerWarehouseSend(&Object[dwIndex]);
						}
						else
						{
							ServerMessageSend((char*)Message::Repair[0].c_str(), dwIndex, 1);
							return;
						}
					}break;
				default:
					{
						for(int i = 0; i < 76; i++)
						{
							ServerRepairItems(&Object[dwIndex], &Object[dwIndex].pInventory[i], i, 1);
						}

						szLocal = "Inventário";
						Calcule::initCharacter(dwIndex);
					}break;
				}

				if(Struct[szVip].Repair.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Repair.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				sprintf_s(&Msg[0], 255, &Message::Repair[1][0], &szLocal[0]);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
		}
	}

	void Command::initClear(DWORD dwIndex, std::string szMsg, BYTE btLocal)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Clear.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Clear) / 1000;

			if(boost::iequals(szMsg, " prosseguir"))
			{
				Player[szIndex].Clear = true;
			}

			if(Struct[szVip].Clear.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Clear.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Clear.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Clear.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Clear.Delay > Delay)
			{
				Calcule = Struct[szVip].Clear.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(!Player[szIndex].Clear)
			{
				ServerMessageSend((char*)Message::Clear[0].c_str(), dwIndex, 1);
				ServerMessageSend((char*)Message::Clear[1].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Clear.Reset > 0)
				{
					Function::updateReset(dwIndex);

					if(Struct[szVip].Clear.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Clear.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				Player[szIndex].Delay.Clear = GetTickCount();

				std::string szLocal = "";

				switch(btLocal)
				{
				case 1:
					{
						if(Object[dwIndex].WarehouseSave == 1 && Object[dwIndex].m_IfState.use == 1 && Object[dwIndex].m_IfState.state == 1 && Object[dwIndex].m_IfState.type == 6)
						{
							for(BYTE i = 0; i < 120; i++)
							{
								Function::clearItem(dwIndex, i);
							}

							szLocal = "Baú";
							Object[dwIndex].m_IfState.state = 0;
							ServerWarehouseSend(&Object[dwIndex]);
						}
						else
						{
							ServerMessageSend((char*)Message::Repair[0].c_str(), dwIndex, 1);
							return;
						}
					}break;
				default:
					{
						for(int i = 0; i < 76; i++)
						{
							ServerInventoryDelete(dwIndex, i);
						}

						szLocal = "Inventário";
						ServerInventorySend(dwIndex);
						
						Calcule::initCharacter(dwIndex);
					}break;
				}

				if(Struct[szVip].Clear.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Clear.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				Player[szIndex].Clear = false;

				sprintf_s(&Msg[0], 255, &Message::Clear[2][0], &szLocal[0]);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
		}
	}

	void Command::initName(DWORD dwIndex, std::string szMsg)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[szVip].Name.Enable == 1)
		{
			Delay = (GetTickCount() - Player[szIndex].Delay.Name) / 1000;
			
			if(Struct[szVip].Name.Level > Object[dwIndex].Level)
			{
				Calcule = Struct[szVip].Name.Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Name.Price > Object[dwIndex].Money)
			{
				Calcule = Struct[szVip].Name.Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[szVip].Name.Delay > Delay)
			{
				Calcule = Struct[szVip].Name.Delay - Delay;
				sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(szMsg.empty() || szMsg.length() < 2)
			{
				ServerMessageSend((char*)Message::Name[0].c_str(), dwIndex, 1);
			}
			else if(szMsg.length() > 10)
			{
				ServerMessageSend((char*)Message::Name[1].c_str(), dwIndex, 1);
			}
			else if(Object[dwIndex].GuildNumber > 0)
			{
				ServerMessageSend((char*)Message::Name[2].c_str(), dwIndex, 1);
			}
			else if(!Function::checkString(szMsg, Struct[0].Name.Pattern, false))
			{
				ServerMessageSend((char*)Message::Name[3].c_str(), dwIndex, 1);
			}
			else if(Marry::Struct[szIndex].Married)
			{
				ServerMessageSend((char*)Message::Default[2].c_str(), dwIndex, 1);
			}
			else
			{
				if(Struct[szVip].Name.Reset > 0)
				{
					Function::updateReset(dwIndex);

					if(Struct[szVip].Name.Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[szVip].Name.Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				int szCount;

				Connect::executeQuery(Query::Name[0], Object[dwIndex].Name);
				szCount = Connect::getInteger(1);
				if(szCount > 0)
				{
					sprintf_s(&Msg[0], 255, &Message::Name[4][0], szCount);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
					return;
				}
				
				Connect::executeQuery(Query::Name[1], szMsg.c_str());
				szCount = Connect::getInteger(1);
				if(szCount > 0)
				{
					ServerMessageSend((char*)Message::Name[5].c_str(), dwIndex, 1);
					return;
				}

				Player[szIndex].Delay.Name = GetTickCount();

				std::string szCharacter[5];
				Connect::executeQuery(Query::Data[0], Object[dwIndex].AccountID);
				szCharacter[0] = Connect::getString(1);
				szCharacter[1] = Connect::ArrayValues[1];
				szCharacter[2] = Connect::ArrayValues[2];
				szCharacter[3] = Connect::ArrayValues[3];
				szCharacter[4] = Connect::ArrayValues[4];
				Connect::getString((-1));

				for(int i = 0; i < 5; i++)
				{
					if(szCharacter[i].empty())
					{
						continue;
					}

					if(boost::iequals(szCharacter[i].c_str(), Object[dwIndex].Name))
					{
						szCount = (i + 1);
						break;
					}

					if(i == 4)
					{
						ServerMessageSend((char*)Message::Name[6].c_str(), dwIndex, 1);
						return;
					}
				}

				sprintf_s(&Msg[0], 255, "GameID%d", szCount);
				Connect::executeQuery(Query::Name[2], Msg.c_str(), szMsg.c_str(), Object[dwIndex].AccountID);
				Connect::executeQuery(Query::Name[3], szMsg.c_str(), Object[dwIndex].Name, Object[dwIndex].AccountID);

				memcpy_s(Object[dwIndex].Name, 11, szMsg.c_str(), 11);

				if(Struct[szVip].Name.Price > 0)
				{
					Object[dwIndex].Money -= Struct[szVip].Name.Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				sprintf_s(&Msg[0], 255, &Message::Name[7][0], &szMsg[0]);
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			
				ServerCloseClient(dwIndex, 1);
			}
		}
	}

	void Command::initMove(DWORD dwIndex, BYTE btMove)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		BYTE szVip = Player[szIndex].Vip;

		if(Struct[0].Move[btMove].Enable == 1)
		{
			if(Struct[0].Move[btMove].Level > Object[dwIndex].Level)
			{
				Calcule = Struct[0].Move[btMove].Level - Object[dwIndex].Level;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "level" : "leveis");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[0].Move[btMove].Price > Object[dwIndex].Money)
			{
				Calcule = Struct[0].Move[btMove].Price - Object[dwIndex].Money;
				sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, "zen");
				ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
			}
			else if(Struct[0].Move[btMove].Vip > szVip)
			{
				return;
			}
			else
			{
				if(Struct[0].Move[btMove].Reset > 0)
				{
					Function::updateReset(dwIndex);
					
					if(Struct[0].Move[btMove].Reset > Player[szIndex].Reset)
					{
						Calcule = Struct[0].Move[btMove].Reset - Player[szIndex].Reset;
						sprintf_s(&Msg[0], 255, &Message::Default[0][0], Calcule, (Calcule == 1) ? "reset" : "resets");
						ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
						return;
					}
				}

				if(Struct[0].Move[btMove].PK == 0)
				{
					if(Object[dwIndex].PkLevel > 3)
					{
						ServerMessageSend((char*)Message::Move[0].c_str(), dwIndex, 1);
						return;
					}
				}

				if(Struct[0].Move[btMove].GM == 1)
				{
					if((Object[dwIndex].Authority < 2))
					{
						ServerMessageSend((char*)Message::Move[1].c_str(), dwIndex, 1);
						return;
					}
				}

				if(Struct[0].Move[btMove].Price > 0)
				{
					Object[dwIndex].Money -= Struct[0].Move[btMove].Price;
					ServerMoneySend(dwIndex, Object[dwIndex].Money);
				}

				ServerTeleportSend(dwIndex, (int)Struct[0].Move[btMove].Map, (int)Struct[0].Move[btMove].X, (int)Struct[0].Move[btMove].Y);
			}
		}
	}

	void Command::initReload(DWORD dwIndex)
	{
		if(Struct[0].Reload.Enable == 1)
		{
			if(Object[dwIndex].Authority > 1)
			{
				WORD szIndex = (WORD)(dwIndex - 4800);
				
				Delay = (GetTickCount() - Player[szIndex].Delay.Reload) / 1000;

				if(Struct[0].Reload.Delay > Delay)
				{
					Calcule = Struct[0].Reload.Delay - Delay;
					sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
				else
				{
					Player[szIndex].Delay.Reload = GetTickCount();

					_beginthread(initThreadReload, 0, NULL);

					Struct[0].Reload.Index = dwIndex;
				}
			}
		}
	}

	void Command::initThreadReload(LPVOID lpParam)
	{
		ServerReloadConfig();
		ServerMessageSend((char*)Message::Reload[0].c_str(), Struct[0].Reload.Index, 1);
		Sleep(2000);

		ServerReloadShop();
		ServerMessageSend((char*)Message::Reload[1].c_str(), Struct[0].Reload.Index, 1);
		Sleep(2000);

		ServerReloadMonster();
		ServerMessageSend((char*)Message::Reload[2].c_str(), Struct[0].Reload.Index, 1);
		Sleep(2000);

		//Command::initComponents();
		//Sleep(1500);
		Message::initComponents();
		Sleep(600);
		Query::initComponents();
		Sleep(600);
		Security::initComponents();
		Sleep(600);
		Trade::initComponents();
		Sleep(600);
		Function::initComponents();
		ServerMessageSend((char*)Message::Reload[3].c_str(), Struct[0].Reload.Index, 1);
		Sleep(1000);

		_endthread();
	}
	
	void Command::initBlock(DWORD dwIndex, std::string szMsg, BYTE btBlock)
	{
		if(Struct[0].Block.Enable == 1)
		{
			if(Object[dwIndex].Authority > 1)
			{
				WORD szIndex = (WORD)(dwIndex - 4800);
			
				Delay = (GetTickCount() - Player[szIndex].Delay.Block) / 1000;
				
				if(Struct[0].Block.Delay > Delay)
				{
					Calcule = Struct[0].Block.Delay - Delay;
					sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
				else if(szMsg.empty())
				{
					ServerMessageSend((char*)Message::Block[0].c_str(), dwIndex, 1);
				}
				else
				{
					TokenizerRow _block(szMsg);

					if(_block.FieldCount < 2)
					{
						ServerMessageSend((char*)Message::Block[0].c_str(), dwIndex, 1);
						return;
					}
					
					WORD wdIndex = 0;
					WORD wdDays  = (WORD)_block[1].ToInteger();
					std::string szUser = _block[0].ToString();
					
					if(wdDays <= 0)
					{
						ServerMessageSend((char*)Message::Block[1].c_str(), dwIndex, 1);
						return;
					}
					
					if(btBlock == 0)
					{
						Connect::executeQuery(Query::Block[0], szUser.c_str());
					}
					else
					{
						Connect::executeQuery(Query::Block[1], szUser.c_str());
					}
					
					wdIndex = (WORD)Connect::getInteger(1);
					
					if(wdIndex <= 0)
					{
						ServerMessageSend((char*)Message::Block[2].c_str(), dwIndex, 1);
						return;
					}
					
					wdIndex = 0;
					
					for(int i = 4800; i < 5800; i++)
					{
						if(Object[i].Connected > 2)
						{
							if(btBlock == 0)
							{
								if(boost::iequals(Object[i].Name, szUser.c_str()))
								{
									wdIndex = (WORD)i;
									break;
								}
							}
							else
							{
								if(boost::iequals(Object[i].AccountID, szUser.c_str()))
								{
									wdIndex = (WORD)i;
									break;
								}
							}
						}
					}
					
					Player[szIndex].Delay.Block = GetTickCount();
					
					if(btBlock == 0)
					{
						Connect::executeQuery(Query::Block[2], wdDays, szUser.c_str());
					
						sprintf_s(&Msg[0], 255, &Message::Block[3][0], "Personagem", "bloqueado");
					}
					else
					{
						Connect::executeQuery(Query::Block[4], wdDays, szUser.c_str());
						
						sprintf_s(&Msg[0], 255, &Message::Block[3][0], "Conta", "bloqueada");
					}

					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
					
					if(wdIndex != 0)
					{
						ServerCloseClient((DWORD)wdIndex, 0);
					}
				}
			}
		}
	}

	void Command::initUnlock(DWORD dwIndex, std::string szMsg, BYTE btUnlock)
	{
		if(Struct[0].Block.Enable == 1)
		{
			if(Object[dwIndex].Authority > 1)
			{
				WORD szIndex = (WORD)(dwIndex - 4800);
			
				Delay = (GetTickCount() - Player[szIndex].Delay.Block) / 1000;
				
				if(Struct[0].Block.Delay > Delay)
				{
					Calcule = Struct[0].Block.Delay - Delay;
					sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
				else if(szMsg.empty())
				{
					ServerMessageSend((char*)Message::Block[0].c_str(), dwIndex, 1);
				}
				else
				{
					TokenizerRow _block(szMsg);

					if(_block.FieldCount < 1)
					{
						ServerMessageSend((char*)Message::Block[0].c_str(), dwIndex, 1);
						return;
					}
					
					WORD wdIndex = 0;
					std::string szUser = _block[0].ToString();

					if(btUnlock == 0)
					{
						Connect::executeQuery(Query::Block[0], szUser.c_str());
					}
					else
					{
						Connect::executeQuery(Query::Block[1], szUser.c_str());
					}
					
					wdIndex = (WORD)Connect::getInteger(1);
					
					if(wdIndex <= 0)
					{
						ServerMessageSend((char*)Message::Block[2].c_str(), dwIndex, 1);
						return;
					}
					
					wdIndex = 0;
					
					for(int i = 4800; i < 5800; i++)
					{
						if(Object[i].Connected > 2)
						{
							if(btUnlock == 0)
							{
								if(boost::iequals(Object[i].Name, szUser.c_str()))
								{
									wdIndex = (WORD)i;
									break;
								}
							}
							else
							{
								if(boost::iequals(Object[i].AccountID, szUser.c_str()))
								{
									wdIndex = (WORD)i;
									break;
								}
							}
						}
					}
					
					Player[szIndex].Delay.Block = GetTickCount();
					
					if(btUnlock == 0)
					{
						Connect::executeQuery(Query::Block[3], szUser.c_str());
						
						sprintf_s(&Msg[0], 255, &Message::Block[3][0], "Personagem", "desbloqueado");
					}
					else
					{
						Connect::executeQuery(Query::Block[5], szUser.c_str());
						
						sprintf_s(&Msg[0], 255, &Message::Block[3][0], "Conta", "desbloqueada");
					}
					
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
					
					if(wdIndex != 0)
					{
						ServerCloseClient((DWORD)wdIndex, 0);
					}
				}
			}
		}
	}

	void Command::initTeleport(DWORD dwIndex, std::string szMsg, BYTE btTeleport)
	{
		if(Struct[0].Teleport.Enable == 1)
		{
			if(Object[dwIndex].Authority > 1)
			{
				WORD szIndex = (WORD)(dwIndex - 4800);
			
				Delay = (GetTickCount() - Player[szIndex].Delay.Teleport) / 1000;
				
				if(Struct[0].Teleport.Delay > Delay)
				{
					Calcule = Struct[0].Teleport.Delay - Delay;
					sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
				else if(szMsg.empty())
				{
					if(btTeleport < 2)
					{
						ServerMessageSend((char*)Message::Teleport[0].c_str(), dwIndex, 1);
					}
					else
					{
						ServerMessageSend((char*)Message::Teleport[1].c_str(), dwIndex, 1);
					}
				}
				else
				{
					TokenizerRow _teleport(szMsg);

					if(btTeleport < 2)
					{
						if(_teleport.FieldCount < 4)
						{
							ServerMessageSend((char*)Message::Teleport[0].c_str(), dwIndex, 1);
							return;
						}
					}
					else
					{
						if(_teleport.FieldCount < 3)
						{
							ServerMessageSend((char*)Message::Teleport[1].c_str(), dwIndex, 1);
							return;
						}
					}

					std::string szUser;
					BYTE btMap = 0, btX = 0, btY = 0;
					WORD wdIndex = 0;

					if(btTeleport < 2)
					{
						szUser  = _teleport[0].ToString();
						btMap	= (BYTE)_teleport[1].ToInteger();
						btX		= (BYTE)_teleport[2].ToInteger();
						btY		= (BYTE)_teleport[3].ToInteger();

						if(btTeleport == 0)
						{
							for(int i = 4800; i < 5800; i++)
							{
								if(Object[i].Connected > 2)
								{
									if(boost::iequals(Object[i].Name, szUser.c_str()))
									{
										wdIndex = (WORD)i;
										break;
									}
								}
							}

							if(wdIndex == 0)
							{
								ServerMessageSend((char*)Message::Teleport[2].c_str(), dwIndex, 1);
								return;
							}

							ServerTeleportSend((DWORD)wdIndex, (int)btMap, (int)btX, (int)btY);
							ServerMessageSend((char*)Message::Teleport[3].c_str(), dwIndex, 1);
						}
						else
						{
							for(int i = 4800; i < 5800; i++)
							{
								if(Object[i].Connected > 2)
								{
									if(boost::iequals(Object[i].GuildName, szUser.c_str()))
									{
										ServerTeleportSend((DWORD)i, (int)btMap, (int)btX, (int)btY);
									}
								}
							}

							ServerMessageSend((char*)Message::Teleport[4].c_str(), dwIndex, 1);
						}
					}
					else
					{
						btMap	= (BYTE)_teleport[0].ToInteger();
						btX		= (BYTE)_teleport[1].ToInteger();
						btY		= (BYTE)_teleport[2].ToInteger();

						if(btTeleport == 2)
						{
							for(int i = 4800; i < 5800; i++)
							{
								if(Object[i].Connected > 2)
								{
									if(Object[i].Map == Object[dwIndex].Map)
									{
										ServerTeleportSend((DWORD)i, (int)btMap, (int)btX, (int)btY);
									}
								}	
							}

							ServerMessageSend((char*)Message::Teleport[5].c_str(), dwIndex, 1);
						}
						else
						{
							for(int i = 4800; i < 5800; i++)
							{
								if(Object[i].Connected > 2)
								{
									ServerTeleportSend((DWORD)i, (int)btMap, (int)btX, (int)btY);
								}	
							}

							ServerMessageSend((char*)Message::Teleport[6].c_str(), dwIndex, 1);
						}
					}

					Player[szIndex].Delay.Teleport = GetTickCount();
				}
			}
		}
	}

	void Command::initSkin(DWORD dwIndex, std::string szMsg)
	{
		if(Struct[0].Skin.Enable == 1)
		{
			if(Object[dwIndex].Authority > 1)
			{
				WORD szIndex = (WORD)(dwIndex - 4800);
			
				Delay = (GetTickCount() - Player[szIndex].Delay.Skin) / 1000;
				
				if(Struct[0].Skin.Delay > Delay)
				{
					Calcule = Struct[0].Skin.Delay - Delay;
					sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
				else
				{
					Player[szIndex].Delay.Skin = GetTickCount();

					int szNumber = atoi(szMsg.c_str());
					Object[dwIndex].m_Change = szNumber;
					ServerProtocolCreate(&Object[dwIndex]);
				}
			}
		}
	}

	void Command::initFirework(DWORD dwIndex)
	{
		if(Struct[0].Firework.Enable == 1)
		{
			if(Object[dwIndex].Authority > 1)
			{
				WORD szIndex = (WORD)(dwIndex - 4800);
			
				Delay = (GetTickCount() - Player[szIndex].Delay.Firework) / 1000;

				if(Struct[0].Firework.Delay > Delay)
				{
					Calcule = Struct[0].Firework.Delay - Delay;
					sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
				else
				{
					Player[szIndex].Delay.Firework = GetTickCount();

					Function::useFirework(dwIndex);
				}
			}
		}
	}

	/*void Command::initSet(DWORD dwIndex, std::string szMsg, BYTE btMode)
	{
		if(Struct[0].Set.Enable == 1)
		{
			if(Object[dwIndex].Authority > 1)
			{
				WORD szIndex = (WORD)(dwIndex - 4800);
			
				Delay = (GetTickCount() - Player[szIndex].Delay.Set) / 1000;

				if(Struct[0].Set.Delay > Delay)
				{
					Calcule = Struct[0].Set.Delay - Delay;
					sprintf_s(&Msg[0], 255, &Message::Default[1][0], Calcule);
					ServerMessageSend((char*)Msg.c_str(), dwIndex, 1);
				}
				else if(szMsg.empty())
				{
					ServerMessageSend((char*)Message::Set[0].c_str(), dwIndex, 1);
				}
				else
				{
					Player[szIndex].Delay.Set = GetTickCount();

					TokenizerRow _set(szMsg);

					if(_set.FieldCount < 2)
					{
						ServerMessageSend((char*)Message::Set[0].c_str(), dwIndex, 1);
						return;
					}

					std::string szCharacter = _set[0].ToString();
					int szValue = _set[1].ToInteger();
					int UserId = 0;

					for(int i = 4800; i < 5800; i++)
					{
						if(Object[i].Connected > 2)
						{
							if(boost::iequals(szCharacter.c_str(), Object[dwIndex].Name))
							{
								UserId = i;
								break;
							}
						}
					}

					if(UserId == 0)
					{
						ServerMessageSend((char*)Message::Set[1].c_str(), dwIndex, 1);
						return;
					}

					switch(btMode)
					{
					case 0:
						{
							short MaxLevel = GetPrivateProfileInt("Max", "Level", 350, ".\\Network\\Setting.ut");

							if(szValue > MaxLevel)
							{
								Object[dwIndex].Level = (MaxLevel - 1);
							}
							else
							{
								Object[dwIndex].Level = (szValue - 1);
							}

							//ServerLevelUp(

						}break;
					}
				}
			}
		}
	}*/
}