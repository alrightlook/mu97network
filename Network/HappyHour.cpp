#include "Library.h"

namespace Network
{
	HappyHourStruct HappyHour::Struct;

	bool HappyHour::initComponents()
	{
		Tokenizer _happyhour(".\\Networ\\Event\\HappyHour.ut");

		if(_happyhour.Loaded)
		{
			if(!_happyhour.SectionExists(0))
			{
				return false;
			}
			else
			{
				Struct.Enable		 = (_happyhour[0][0][0].ToInteger() == 1) ? true : false;
				Struct.Enable		 = false;
				Struct.Count[0]		 = 5;
				Struct.Count[1]		 = 5;
				Struct.Duration		 = (unsigned long)_happyhour[0][0][1].ToInteger();
				Struct.Delay		 = (unsigned long)_happyhour[0][0][2].ToInteger();
				Struct.NewExperience = (float)_happyhour[0][0][3].ToInteger();
				Struct.NewDrop		 = (unsigned long)_happyhour[0][0][4].ToInteger();

				if(Struct.Enable)
				{
					_beginthread(initEvent, 0, NULL);
				}

				return true;
			}
		}

		return false;
	}

	void HappyHour::initPrepare()
	{
		std::string Msg(255, ' ');
	
		if(!Struct.Start)
		{
			sprintf_s(&Msg[0], 255, &Message::HappyHour[0][0], Struct.Count[0]);
			
			Message::sendUsers(Msg);

			Struct.Count[0]--;
		}	
		else
		{
			sprintf_s(&Msg[0], 255, &Message::HappyHour[0][0], Struct.Count[1]);
			
			Message::sendUsers(Msg);
	
			Struct.Count[1]--;
		}
	
		Sleep(60000);
	
		if(!Struct.Start)
		{
			initEvent(NULL);
		}
		else
		{
			initFinish();
		}
	}

	void HappyHour::initEvent(LPVOID lpParam)
	{
		if(Struct.Enable)
		{
			if(!Struct.Start)
			{
				if(Struct.Count[0] == 0)
				{
					float szExperience = *(float*)(ServerExperience);
					DWORD dwDrop = *(DWORD*)(ServerDrop);

					Struct.OldExperience = szExperience;
					Struct.OldDrop		 = dwDrop;

					*(float*)(ServerExperience) = Struct.NewExperience;
					*(DWORD*)(ServerDrop)		= Struct.NewDrop;

					Struct.Start = true;

					Message::sendUsers(Message::HappyHour[2]);

					Sleep(60000 * Struct.Duration);

					initFinish();
				}
				else
				{
					initPrepare();
				}
			}
		}
	}

	void HappyHour::initFinish()
	{
		if(Struct.Start)
		{
			if(Struct.Count[1] == 0)
			{
				*(float*)(ServerExperience) = Struct.OldExperience;
				*(DWORD*)(ServerDrop)		= Struct.OldDrop;

				Struct.Start = false;

				Message::sendUsers(Message::HappyHour[3]);

				Sleep(60000 * Struct.Delay);

				initEvent(NULL);
			}
			else
			{
				initPrepare();
			}
		}
	}
}