#include "Library.h"

namespace Network
{
	bool Project::initComponents()
	{
		DWORD dwProtect1, dwProtect2;
		LPVOID lpAddress1, lpAddress2;

		lpAddress1 = (LPVOID)(0x401000);
		lpAddress2 = (LPVOID)(0x7311000);

		if(VirtualProtect(lpAddress1, 0x111000, PAGE_EXECUTE_READWRITE, &dwProtect1))
		{
			if(VirtualProtect(lpAddress2, 0x2000, PAGE_EXECUTE_READWRITE, &dwProtect2))
			{
				if(!checkComponents())
				{
					return false;
				}

				Function::hookStruct();
				Function::hookFunction((DWORD)&Setting::joinServer, 0x402865);
				Function::hookFunction((DWORD)&Setting::addPoints, 0x40245F);
				Function::hookFunction((DWORD)&Calcule::initCharacter, 0x4015AF);
				Function::hookFunction((DWORD)&Map::initAttack, 0x4014E2);
				Function::hookFunction((DWORD)&Map::initLevelUp, 0x401771);
				Function::hookFunction((DWORD)&Map::initMonsterExp, 0x402022);
				Function::hookFunction((DWORD)&Drop::itemDrop, 0x401AC8);
				Function::hookFunction((DWORD)&Flood::initConnection, 0x401834);
				Function::hookFunction((DWORD)&Disconnect::initAction, 0x401A1E);
				Function::hookFunction((DWORD)&Create::initCharacter, 0x401B8B);
				Function::hookFunction((DWORD)&Create::initGuild, 0x4017DF);
				Function::hookFunction((DWORD)&Trade::initRequest, 0x402216);
				Function::hookFunction((DWORD)&Trade::initResponse, 0x4018E3);
				Function::hookFunction((DWORD)&Trade::initCancel, 0x401ED8);
				Function::hookFunction((DWORD)&Shadow::initBless, 0x4016E0);
				Function::hookFunction((DWORD)&Shadow::initSoul, 0x4015A0);
				Function::hookFunction((DWORD)&Shadow::initLife, 0x401FAF);
				Function::hookFunction((DWORD)&Ring::initDrop, 0x4010FF);
				Function::hookFunction((DWORD)&Ring::initMove, 0x40272F);
				Function::hookFunction((DWORD)&Skill::initUse, 0x4012BC);
				Function::hookFunction((DWORD)&Manager::serverProtocol, 0x401D5C);
				Function::hookFunction((DWORD)&Manager::npcTalk, 0x401B27);
				//Function::hookFunction((DWORD)&closeComponents, 0x4906A9);
				//Function::hookFunction((DWORD)&closeComponents, 0x4906B5);

				_beginthread(Function::updateVip, 0, NULL);
				_beginthread(Function::showNotice, 0, NULL);

				VirtualProtect(lpAddress1, 0x111000, PAGE_EXECUTE_READ, &dwProtect1);
				VirtualProtect(lpAddress2, 0x2000, PAGE_EXECUTE_READ, &dwProtect2);

				return true;
			}
		}

		return false;
	}

	bool Project::checkComponents()
	{
		bool szCheck = true;
		std::string szComponent = "";

		if(!Function::checkFiles(".\\Network\\Connect.ut"))
		{
			szComponent = "Connect.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Setting.ut"))
		{
			szComponent = "Setting.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Command.ut"))
		{
			szComponent = "Command.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Message.ut"))
		{
			szComponent = "Message.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Query.ut"))
		{
			szComponent = "Query.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Trade.ut"))
		{
			szComponent = "Trade.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Notice.ut"))
		{
			szComponent = "Notice.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Reset.ut"))
		{
			szComponent = "Reset.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Master.ut"))
		{
			szComponent = "Master.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Map.ut"))
		{
			szComponent = "Map.ut";
		}
		else if(!Function::checkFiles(".\\Network\\Block\\IpAddress.txt"))
		{
			szComponent = "IpAddress.txt";
		}
		else if(!Function::checkFiles(".\\Network\\Calcule\\Character.ut"))
		{
			szComponent = "Character.ut";
		}
		else
		{
			if(!Connect::initComponents())
			{
				szCheck = false;
				szComponent = "Connect()";
			}
			else if(!Setting::initComponents())
			{
				szCheck = false;
				szComponent = "Setting()";
			}
			else if(!Command::initComponents())
			{
				szCheck = false;
				szComponent = "Command()";
			}
			else if(!Message::initComponents())
			{
				szCheck = false;
				szComponent = "Message()";
			}
			else if(!Query::initComponents())
			{
				szCheck = false;
				szComponent = "Query()";
			}
			else if(!Security::initComponents())
			{
				szCheck = false;
				szComponent = "Security()";
			}
			else if(!Trade::initComponents())
			{
				szCheck = false;
				szComponent = "Trade()";
			}
			else if(!Function::initComponents())
			{
				szCheck = false;
				szComponent = "Function()";
			}
			else
			{
				return true;
			}
		}

		std::string Msg(255, ' ');

		if(!szCheck)
		{
			sprintf_s(&Msg[0], 255, "Falha na inicialização da função %s.", &szComponent[0]);
		}
		else
		{
			sprintf_s(&Msg[0], 255, "O arquivo %s não foi localizado.", &szComponent[0]);
		}

		MessageBox(NULL, Msg.c_str(), "Erro", MB_OK | MB_ICONERROR);

		return false;
	}
}