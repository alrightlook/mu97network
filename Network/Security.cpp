#include "Library.h"

namespace Network
{
	bool Security::initComponents()
	{
		if(!Flood::initComponents())
		{
			return false;
		}
		else if(!Skill::initComponents())
		{
			return false;
		}
		else
		{
			std::fstream f(".\\Network\\Block\\IpAddress.txt", std::ios::in);
		
			if(f.is_open() && f.good())
			{
				BYTE szNum = 0;
				char szBuffer[1024];
				std::string szLine;

				while(!f.eof())
				{
					if(Flood::Count == 500)
					{
						MessageBox(NULL, "O limite de endereço IP de usuários foi excedido.", "Erro", MB_OK | MB_ICONERROR);
						break;
					}

					memset(&szBuffer[0], 0x00, 1024);
					f.getline(szBuffer, 1024);
					szLine.assign(&szBuffer[0]);

					if(szLine.length() > 9)
					{
						if(szLine.substr(0, 2) != "//" && szLine.substr(0, 1) != "#" && szLine.substr(0, 1) != ";")
						{
							szNum = (BYTE)Flood::Count;

							for(int i = 0; i < (int)szLine.length(); i++)
							{
								if(szLine[i] != ' ' && szLine[i] != '\t' && szLine[i] != '"')
								{
									if(isdigit(szLine.c_str()[i]) || szLine[i] == '.')
									{
										Flood::Struct[szNum].Address += szLine[i];
									}
									else
									{
										f.close();
										MessageBox(NULL, "O arquivo IpAddress.txt está configurado de forma inadequada.", "Erro", MB_OK | MB_ICONERROR);
										return false;
									}
								}
							}
					
							Flood::Count++;
						}
					}
				}

				f.close();

				return true;
			}
		}

		return false;
	}
}