#include "Library.h"

namespace Network
{
	std::string Manager::Msg(255, ' ');

	void Manager::serverProtocol(BYTE btProtocol, LPBYTE lpRecv, DWORD dwLength, DWORD dwIndex, DWORD dwEncrypt, int iSerial)
	{
		bool szSend = true;

		switch(btProtocol)
		{
		case 0x00:
			{
				szSend = userChat(dwIndex, (std::string)((char*)&lpRecv[13]));
			}break;
		case 0x03:
			{
				if(Setting::Struct.Announce == 1)
				{
					if(Object[dwIndex].Authority > 1)
					{
						sprintf_s(&Msg[0], 255, &Message::Announce[0][0], Object[dwIndex].Name);
						
						Message::sendUsers(Msg);
					}
				}

				if(Setting::Struct.Welcome == 1)
				{
					WORD szIndex = (WORD)(dwIndex - 4800);
					BYTE szVip = Player[szIndex].Vip;
					ServerMessageSend((char*)Message::Welcome[szVip].c_str(), dwIndex, 0);
				}

				if(Marry::Enable)
				{
					std::string He, She;

					Connect::executeQuery(Query::Marry[2], Object[dwIndex].Name, Object[dwIndex].Name);
					He = Connect::getString(1);
					She = Connect::ArrayValues[1];
					Connect::getString((-1));

					if(!He.empty() && !She.empty())
					{
						bool isMale = false;
						WORD szIndex = (WORD)(dwIndex - 4800);
						
						Marry::Struct[szIndex].Married = true;

						if(boost::iequals(He.c_str(), Object[dwIndex].Name))
						{
							Marry::Struct[szIndex].Name = She;
						}
						else
						{
							Marry::Struct[szIndex].Name = He;
						}
					}
				}
			}break;
		}
		
		if(szSend)
		{
			ServerDataRecv(btProtocol, lpRecv, dwLength, dwIndex, dwEncrypt, iSerial);
		}
	}

	bool Manager::userChat(DWORD dwIndex, std::string szMsg)
	{
		switch(szMsg.c_str()[0])
		{
		case '!':
			{
				if(Object[dwIndex].Authority > 1)
				{
					sprintf_s(&Msg[0], 255, &Message::Announce[1][0], Object[dwIndex].Name, &szMsg.c_str()[1]);
						
					Message::sendUsers(Msg);
					return false;
				}
			}break;
		case '/':
			{
				if(Object[dwIndex].Authority > 1)
				{
					if(boost::iequals(szMsg.substr(1, Command::Struct[0].Reload.String.length()), Command::Struct[0].Reload.String))
					{
						Command::initReload(dwIndex);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Block.String.length()), Command::Struct[0].Block.String))
					{
						Command::initBlock(dwIndex, szMsg.substr((Command::Struct[0].Block.String.length() + 1), (szMsg.length() - (Command::Struct[0].Block.String.length() + 1))), 0);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[1].Block.String.length()), Command::Struct[1].Block.String))
					{
						Command::initUnlock(dwIndex, szMsg.substr((Command::Struct[1].Block.String.length() + 1), (szMsg.length() - (Command::Struct[1].Block.String.length() + 1))), 0);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[2].Block.String.length()), Command::Struct[2].Block.String))
					{
						Command::initBlock(dwIndex, szMsg.substr((Command::Struct[2].Block.String.length() + 1), (szMsg.length() - (Command::Struct[2].Block.String.length() + 1))), 1);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[3].Block.String.length()), Command::Struct[3].Block.String))
					{
						Command::initUnlock(dwIndex, szMsg.substr((Command::Struct[3].Block.String.length() + 1), (szMsg.length() - (Command::Struct[3].Block.String.length() + 1))), 1);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Teleport.String.length()), Command::Struct[0].Teleport.String))
					{
						Command::initTeleport(dwIndex, szMsg.substr((Command::Struct[0].Teleport.String.length() + 1), (szMsg.length() - (Command::Struct[0].Teleport.String.length() + 1))), 0);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[1].Teleport.String.length()), Command::Struct[1].Teleport.String))
					{
						Command::initTeleport(dwIndex, szMsg.substr((Command::Struct[1].Teleport.String.length() + 1), (szMsg.length() - (Command::Struct[1].Teleport.String.length() + 1))), 1);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[2].Teleport.String.length()), Command::Struct[2].Teleport.String))
					{
						Command::initTeleport(dwIndex, szMsg.substr((Command::Struct[2].Teleport.String.length() + 1), (szMsg.length() - (Command::Struct[2].Teleport.String.length() + 1))), 2);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[3].Teleport.String.length()), Command::Struct[3].Teleport.String))
					{
						Command::initTeleport(dwIndex, szMsg.substr((Command::Struct[3].Teleport.String.length() + 1), (szMsg.length() - (Command::Struct[3].Teleport.String.length() + 1))), 3);
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Skin.String.length()), Command::Struct[0].Skin.String))
					{
						Command::initSkin(dwIndex, szMsg.substr((Command::Struct[0].Skin.String.length() + 1), (szMsg.length() - (Command::Struct[0].Skin.String.length() + 1))));
					}
					else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Firework.String.length()), Command::Struct[0].Firework.String))
					{
						Command::initFirework(dwIndex);
					}
				}

				if(boost::iequals(szMsg.substr(1, 4), "war "))
				{
					Command::initGuild(dwIndex, szMsg.substr(5, (szMsg.length() - 5)));
				}
				else if(boost::iequals(szMsg.substr(1, 9), "guildwar "))
				{
					Command::initGuild(dwIndex, szMsg.substr(10, (szMsg.length() - 10)));
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Post.String.length()), Command::Struct[0].Post.String))
				{
					Command::initPost(dwIndex, szMsg.substr((Command::Struct[0].Post.String.length() + 1), (szMsg.length() - (Command::Struct[0].Post.String.length() + 1))));
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Status.String.length()), Command::Struct[0].Status.String))
				{
					Command::initStatus(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Zen.String.length()), Command::Struct[0].Zen.String))
				{
					Command::initZen(dwIndex, szMsg.substr((Command::Struct[0].Zen.String.length() + 1), (szMsg.length() - (Command::Struct[0].Zen.String.length() + 1))));
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Points.String.length()), Command::Struct[0].Points.String))
				{
					Command::initPoints(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Website.String.length()), Command::Struct[0].Website.String))
				{
					Command::initWebsite(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Online.String.length()), Command::Struct[0].Online.String))
				{
					Command::initOnline(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Data.String.length()), Command::Struct[0].Data.String))
				{
					Command::initData(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Add.String.length()), Command::Struct[0].Add.String))
				{
					Command::initAdd(dwIndex, szMsg.substr((Command::Struct[0].Add.String.length() + 1), (szMsg.length() - (Command::Struct[0].Add.String.length() + 1))), 0);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[1].Add.String.length()), Command::Struct[1].Add.String))
				{
					Command::initAdd(dwIndex, szMsg.substr((Command::Struct[1].Add.String.length() + 1), (szMsg.length() - (Command::Struct[1].Add.String.length() + 1))), 1);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[2].Add.String.length()), Command::Struct[2].Add.String))
				{
					Command::initAdd(dwIndex, szMsg.substr((Command::Struct[2].Add.String.length() + 1), (szMsg.length() - (Command::Struct[2].Add.String.length() + 1))), 2);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[3].Add.String.length()), Command::Struct[3].Add.String))
				{
					Command::initAdd(dwIndex, szMsg.substr((Command::Struct[3].Add.String.length() + 1), (szMsg.length() - (Command::Struct[3].Add.String.length() + 1))), 3);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].ReAdd.String.length()), Command::Struct[0].ReAdd.String))
				{
					Command::initReAdd(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Select.String.length()), Command::Struct[0].Select.String))
				{
					Command::initSelect(dwIndex, 0);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[1].Select.String.length()), Command::Struct[1].Select.String))
				{
					Command::initSelect(dwIndex, 1);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[2].Select.String.length()), Command::Struct[2].Select.String))
				{
					Command::initSelect(dwIndex, 2);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Warehouse.String.length()), Command::Struct[0].Warehouse.String))
				{
					Command::initWarehouse(dwIndex, szMsg.substr((Command::Struct[0].Warehouse.String.length() + 1), (szMsg.length() - (Command::Struct[0].Warehouse.String.length() + 1))));
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Evo.String.length()), Command::Struct[0].Evo.String))
				{
					Command::initEvo(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Class.String.length()), Command::Struct[0].Class.String))
				{
					Command::initClass(dwIndex, szMsg.substr((Command::Struct[0].Class.String.length() + 1), (szMsg.length() - (Command::Struct[0].Class.String.length() + 1))));
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Repair.String.length()), Command::Struct[0].Repair.String))
				{
					Command::initRepair(dwIndex, 0);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[1].Repair.String.length()), Command::Struct[1].Repair.String))
				{
					Command::initRepair(dwIndex, 1);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Clear.String.length()), Command::Struct[0].Clear.String))
				{
					Command::initClear(dwIndex, szMsg.substr((Command::Struct[0].Clear.String.length() + 1), (szMsg.length() - (Command::Struct[0].Clear.String.length() + 1))), 0);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[1].Clear.String.length()), Command::Struct[1].Clear.String))
				{
					Command::initClear(dwIndex, szMsg.substr((Command::Struct[1].Clear.String.length() + 1), (szMsg.length() - (Command::Struct[1].Clear.String.length() + 1))), 1);
				}
				else if(boost::iequals(szMsg.substr(1, Command::Struct[0].Name.String.length()), Command::Struct[0].Name.String))
				{
					Command::initName(dwIndex, szMsg.substr((Command::Struct[0].Name.String.length() + 1), (szMsg.length() - (Command::Struct[0].Name.String.length() + 1))));
				}
				else if(boost::iequals(szMsg.substr(1, Reset::Struct[0].String.length()), Reset::Struct[0].String))
				{
					Reset::initReset(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Master::Struct[0].String.length()), Master::Struct[0].String))
				{
					Master::initMaster(dwIndex);
				}
				else if(boost::iequals(szMsg.substr(1, Marry::String[0].length()), Marry::String[0]))
				{
					Marry::initPropose(dwIndex, szMsg.substr((Marry::String[0].length() + 1), (szMsg.length() - (Marry::String[0].length() + 1))));
				}
				else if(boost::iequals(szMsg.substr(1, Marry::String[1].length()), Marry::String[1]))
				{
					Marry::initDivorce(dwIndex);
				}
				else
				{
					for(BYTE i = 0; i < Command::Count; i++)
					{
						if(boost::iequals(szMsg.substr(1, Command::Struct[0].Move[i].String.length()), Command::Struct[0].Move[i].String))
						{
							Command::initMove(dwIndex, i);
							break;
						}
					}
				}
			}break;
		}

		return true;
	}

	int Manager::npcTalk(OBJECTSTRUCT* lpNpc, OBJECTSTRUCT* lpObject)
	{
		switch(lpNpc->Class)
		{
		case 234:
			{
				Command::initNpcStatus(lpObject, lpNpc);
				return 1;
			}break;
		case 247:
			{
				Reset::initNpcReset(lpObject, lpNpc);
				return 1;
			}break;
		case 249:
			{
				Master::initNpcMaster(lpObject, lpNpc);
				return 1;
			}break;
		}

		return ServerNpcTalk(lpNpc, lpObject);
	}
}