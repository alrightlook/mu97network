#include "Library.h"

namespace Network
{
	FloodStruct Flood::Struct[500];
	unsigned long Flood::Count;

	bool Flood::initComponents()
	{
		for(int i = 0; i < 500; i++)
		{
			Struct[i].Address = "";
		}

		Count = 0;

		return true;
	}

	bool Flood::checkConnection(std::string szAddress)
	{
		WORD szIndex = Function::stringExplode(szAddress, (std::string)".");

		if(Count > 0)
		{
			for(int i = 0; i < (int)Count; i++)
			{
				if(Struct[i].Address.empty())
				{
					break;
				}

				if((boost::iequals(Struct[i].Address, szAddress)))
				{
					if(!Struct[szIndex].Check.Delete)
					{
						for(int i = 4800; i < 5800; i++)
						{
							if(Object[i].Connected <= 1)
							{
								if(boost::iequals(Object[i].IpAddress, szAddress.c_str()))
								{
									ServerDelete(i);
								}
							}
						}

						Struct[szIndex].Check.Delete++;
					}

					return false;
				}
			}
		}

		if(Struct[szIndex].Check.Timer <= 0)
		{
			Struct[szIndex].Check.Send	  = true;
			Struct[szIndex].Check.Delete  = false;
			Struct[szIndex].Check.Address = szAddress;
			Struct[szIndex].Check.Timer	  = GetTickCount();
			Struct[szIndex].Check.Count   = 0;
		}

		if(!Struct[szIndex].Check.Send)
		{
			if(boost::iequals(Struct[szIndex].Check.Address, szAddress))
			{
				return false;
			}
		}

		if(Struct[szIndex].Check.Count >= 2)
		{
			DWORD dwTimer = (GetTickCount() - Struct[szIndex].Check.Timer) / 1000;
			
			if(dwTimer <= 1)
			{
				Struct[szIndex].Check.Send	  = false;
				Struct[szIndex].Check.Delete  = false;
				Struct[szIndex].Check.Address = szAddress;

				bool szWriteProceed = false;
				
				if(Count < 500)
				{
					if(Count == 499)
					{
						if(Struct[499].Address.empty())
						{
							Struct[499].Check.Address = szAddress;
							szWriteProceed = true;
						}
					}
					else
					{
						BYTE szNum = (BYTE)Count;
						Struct[szNum].Address = szAddress;
						szWriteProceed = true;
						Count++;
					}
				}

				if(szWriteProceed)
				{
					std::fstream f(".\\Network\\Block\\IpAddress.txt", std::ios::app | std::ios::out);
					
					if(f.is_open() && f.good())
					{
						std::string Msg(255, ' ');
						
						sprintf_s(&Msg[0], 255, "\"%s\"\n", &szAddress[0]);

						f.write(Msg.c_str(), Msg.length());
						f.close();
					}
				}
			}
			else
			{
				if(!boost::iequals(Struct[szIndex].Check.Address, szAddress))
				{
					Struct[szIndex].Check.Send	  = true;
					Struct[szIndex].Check.Delete  = false;
					Struct[szIndex].Check.Address = szAddress;
				}

				Struct[szIndex].Check.Timer = GetTickCount();
				Struct[szIndex].Check.Count = 0;
			}
		}
		
		Struct[szIndex].Check.Count++;

		return true;
	}

	short Flood::initConnection(SOCKET szSocket, char* szAddress)
	{
		if(!checkConnection((std::string)szAddress))
		{
			return (-1);
		}

		return ServerConnect(szSocket, szAddress);
	}
}