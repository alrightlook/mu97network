#include "Library.h"

namespace Network
{
	MarryStruct Marry::Struct[1000];
	bool Marry::Enable;
	std::string Marry::String[2];
	std::string Marry::Msg(255, ' ');

	bool Marry::initComponents()
	{
		for(int i = 0; i < 1000; i++)
		{
			Struct[i].Married = false;
			Struct[i].Name = "";
			Struct[i].Target = 0;
			Struct[i].Timer = 0;
		}

		return true;
	}

	bool Marry::initCalculePosition(DWORD dwIndex, WORD szIndex)
	{
		szIndex += 4800;

		if(Object[szIndex].Map == Object[dwIndex].Map)
		{
			if(Object[szIndex].X >= (Object[dwIndex].X - 3) && Object[szIndex].X <= (Object[dwIndex].X + 3))
			{
				if(Object[szIndex].Y >= (Object[dwIndex].Y - 3) && Object[szIndex].Y <= (Object[dwIndex].Y + 3))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool Marry::initCheckSexuallity(DWORD dwIndex, WORD szIndex)
	{
		BYTE Sex[4] = {0, 0, 1, 0};
		BYTE UserClass, NextClass;
		
		szIndex += 4800;

		UserClass = Object[dwIndex].Class;
		NextClass = Object[szIndex].Class;

		if(Sex[UserClass] != Sex[NextClass])
		{
			return true;
		}

		return false;
	}

	void Marry::initFireworkMarry(DWORD dwIndex, DWORD dwTarget)
	{
		BYTE PacketIndex[7] = {0xC1, 0x07, 0xF3, 0x40, 0x00, (BYTE)Object[dwIndex].X, (BYTE)Object[dwIndex].Y};
		BYTE PacketTarget[7] = {0xC1, 0x07, 0xF3, 0x40, 0x00, (BYTE)Object[dwTarget].X, (BYTE)Object[dwTarget].Y};

		for(int i = 4800; i < 5800; i++)
		{
			if(Object[i].Connected > 2)
			{
				if(Object[i].Map == Object[dwIndex].Map)
				{
					ServerDataSend(i, PacketIndex, (DWORD)PacketIndex[1]);
					ServerDataSend(i, PacketIndex, (DWORD)PacketIndex[1]);
					ServerDataSend(i, PacketTarget, (DWORD)PacketTarget[1]);
					ServerDataSend(i, PacketTarget, (DWORD)PacketTarget[1]);
				}
			}
		}
	}

	void Marry::initPropose(DWORD dwIndex, std::string szMsg)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);
		
		if(Enable)
		{
			if(boost::iequals(szMsg, " aceitarpedido"))
			{
				initAccept(dwIndex);
				return;
			}

			boost::trim(szMsg);

			if(szMsg.empty() || szMsg.length() < 2 || szMsg.length() > 10)
			{
				ServerMessageSend((char*)Message::Marry[0].c_str(), dwIndex, 1);
			}
			else if(Struct[szIndex].Married)
			{
				ServerMessageSend((char*)Message::Marry[15].c_str(), dwIndex, 1);
			}
			else
			{
				WORD szIndexMarry = 1603;

				for(int i = 4800; i < 5800; i++)
				{
					if(Object[i].Connected > 2)
					{
						if(boost::iequals(szMsg.c_str(), Object[i].Name))
						{
							szIndexMarry = (WORD)(i - 4800);
							break;
						}
					}
				}

				if(szIndexMarry > 1000)
				{
					ServerMessageSend((char*)Message::Marry[1].c_str(), dwIndex, 1);
				}
				else if(Struct[szIndexMarry].Married)
				{
					ServerMessageSend((char*)Message::Marry[2].c_str(), dwIndex, 1);
				}
				else if(!initCalculePosition(dwIndex, szIndexMarry))
				{
					ServerMessageSend((char*)Message::Marry[4].c_str(), dwIndex, 1);
				}
				else if(!initCheckSexuallity(dwIndex, szIndexMarry))
				{
					ServerMessageSend((char*)Message::Marry[5].c_str(), dwIndex, 1);
				}
				else
				{
					if(Struct[szIndexMarry].Target > 0 && Struct[szIndexMarry].Timer > 0)
					{
						DWORD Delay = (GetTickCount() - Struct[szIndexMarry].Timer) / 1000;
					
						if(Delay < 30)
						{
							ServerMessageSend((char*)Message::Marry[3].c_str(), dwIndex, 1);
							return;
						}
					}

					Struct[szIndex].Timer = 60;
					Struct[szIndexMarry].Timer = 60;

					Struct[szIndexMarry].Target = dwIndex;

					sprintf_s(&Msg[0], 255, &Message::Marry[6][0], Object[dwIndex].Name);
					
					szIndexMarry += 4800;

					ServerMessageSend((char*)Msg.c_str(), szIndexMarry, 1);
					ServerMessageSend((char*)Message::Marry[7].c_str(), szIndexMarry, 1);

					ServerMessageSend((char*)Message::Marry[8].c_str(), dwIndex, 1);
				}
			}
		}
	}

	void Marry::initAccept(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);

		if(Struct[szIndex].Target > 0 && Struct[szIndex].Timer > 0)
		{
			WORD Target = (WORD)Struct[szIndex].Target;

			if(!initCalculePosition(dwIndex, (Target - 4800)))
			{
				ServerMessageSend((char*)Message::Marry[9].c_str(), dwIndex, 1);
			}
			else if(Object[Target].Connected < 2)
			{
				Struct[szIndex].Target = 0;
				Struct[szIndex].Timer = 0;
				ServerMessageSend((char*)Message::Marry[10].c_str(), dwIndex, 1);
			}
			else
			{
				Target -= 4800;

				Struct[szIndex].Married = true;
				Struct[Target].Married = true;

				Struct[szIndex].Timer = 0;
				Struct[Target].Timer = 0;

				Target += 4800;

				sprintf_s(&Msg[0], 255, &Message::Marry[11][0], Object[dwIndex].Name, Object[Target].Name);

				for(int i = 4800; i < 5800; i++)
				{
					if(Object[i].Connected > 2)
					{
						ServerMessageSend((char*)Msg.c_str(), i, 0);
						ServerMessageSend((char*)Message::Marry[12].c_str(), i, 0);
					}
				}

				initFireworkMarry(dwIndex, Target);
				
				std::string He, She;
				
				if(Object[dwIndex].Class != 2)
				{
					He = Object[dwIndex].Name;
					She = Struct[szIndex].Name;
				}
				else
				{
					He = Struct[szIndex].Name;
					She = Object[dwIndex].Name;
				}

				Connect::executeQuery(Query::Marry[0], He.c_str(), She.c_str());
			}
		}
	}

	void Marry::initDivorce(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);

		if(Struct[szIndex].Married)
		{
			for(int i = 4800; i < 5800; i++)
			{
				if(Object[i].Connected > 2)
				{
					if(boost::iequals(Struct[szIndex].Name.c_str(), Object[i].Name))
					{
						WORD Target = (i - 4800);

						Struct[Target].Married = false;
						Struct[Target].Name = "";
						Struct[Target].Target = 0;
						Struct[Target].Timer = 0;

						ServerMessageSend((char*)Message::Marry[13].c_str(), i, 1);
						break;
					}
				}
			}

			std::string He, She;
				
			if(Object[dwIndex].Class != 2)
			{
				He = Object[dwIndex].Name;
				She = Struct[szIndex].Name;
			}
			else
			{
				He = Struct[szIndex].Name;
				She = Object[dwIndex].Name;
			}
	
			Connect::executeQuery(Query::Marry[1], He.c_str(), She.c_str());

			Struct[szIndex].Married = false;
			Struct[szIndex].Name = "";
			Struct[szIndex].Target = 0;
			Struct[szIndex].Timer = 0;
			
			ServerMessageSend((char*)Message::Marry[13].c_str(), dwIndex, 1);
		}
		else
		{
			ServerMessageSend((char*)Message::Marry[14].c_str(), dwIndex, 1);
		}
	}

	void Marry::initTrace(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);

		if(Struct[szIndex].Married)
		{
			bool szTeleported = false;

			for(int i = 4800; i < 5800; i++)
			{
				if(Object[i].Connected > 2)
				{
					if(boost::iequals(Struct[szIndex].Name.c_str(), Object[i].Name))
					{
						ServerTeleportSend(dwIndex, (int)Object[i].Map, (int)Object[i].X, (int)Object[i].Y);
						szTeleported = true;
						break;
					}
				}
			}

			if(szTeleported)
			{
				ServerMessageSend((char*)Message::Marry[16].c_str(), dwIndex, 1);
			}
			else
			{
				ServerMessageSend((char*)Message::Marry[1].c_str(), dwIndex, 1);
			}
		}
		else
		{
			ServerMessageSend((char*)Message::Marry[14].c_str(), dwIndex, 1);
		}
	}
}