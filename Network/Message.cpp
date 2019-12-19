#include "Library.h"

namespace Network
{
	std::string Message::Announce[2];
	std::string Message::Welcome[6];
	std::string Message::Default[3];
	std::string Message::Post[3];
	std::string Message::Status[2];
	std::string Message::Zen[3];
	std::string Message::Points[5];
	std::string Message::Website;
	std::string Message::Online[3];
	std::string Message::Data[5];
	std::string Message::Add[5];
	std::string Message::ReAdd[2];
	std::string Message::Select[3];
	std::string Message::Warehouse[6];
	std::string Message::Evo[3];
	std::string Message::Class[7];
	std::string Message::Repair[2];
	std::string Message::Clear[3];
	std::string Message::Name[8];
	std::string Message::Move[2];
	std::string Message::Reset;
	std::string Message::Master[2];
	std::string Message::Marry[17];
	std::string Message::Reload[4];
	std::string Message::Block[4];
	std::string Message::Teleport[7];
	std::string Message::Trade[2];
	std::string Message::HappyHour[4];

	bool Message::initComponents()
	{
		Tokenizer _message(".\\Network\\Message.ut");

		if(_message.Loaded)
		{
			if(!_message.SectionExists(0))
			{
				return false;
			}
			else if(!_message.SectionExists(1))
			{
				return false;
			}
			else if(!_message.SectionExists(2))
			{
				return false;
			}
			else if(!_message.SectionExists(3))
			{
				return false;
			}
			else if(!_message.SectionExists(4))
			{
				return false;
			}
			else if(!_message.SectionExists(5))
			{
				return false;
			}
			else if(!_message.SectionExists(6))
			{
				return false;
			}
			else if(!_message.SectionExists(7))
			{
				return false;
			}
			else if(!_message.SectionExists(8))
			{
				return false;
			}
			else if(!_message.SectionExists(9))
			{
				return false;
			}
			else if(!_message.SectionExists(10))
			{
				return false;
			}
			else if(!_message.SectionExists(11))
			{
				return false;
			}
			else if(!_message.SectionExists(12))
			{
				return false;
			}
			else if(!_message.SectionExists(13))
			{
				return false;
			}
			else if(!_message.SectionExists(14))
			{
				return false;
			}
			else if(!_message.SectionExists(15))
			{
				return false;
			}
			else if(!_message.SectionExists(16))
			{
				return false;
			}
			else if(!_message.SectionExists(17))
			{
				return false;
			}
			else if(!_message.SectionExists(18))
			{
				return false;
			}
			else if(!_message.SectionExists(19))
			{
				return false;
			}
			else if(!_message.SectionExists(20))
			{
				return false;
			}
			else if(!_message.SectionExists(21))
			{
				return false;
			}
			else if(!_message.SectionExists(22))
			{
				return false;
			}
			else if(!_message.SectionExists(23))
			{
				return false;
			}
			else if(!_message.SectionExists(24))
			{
				return false;
			}
			else if(!_message.SectionExists(25))
			{
				return false;
			}
			else if(!_message.SectionExists(26))
			{
				return false;
			}
			else if(!_message.SectionExists(27))
			{
				return false;
			}
			else
			{
				Announce[0] = _message[0][0][0].ToString();
				Announce[1] = _message[0][1][0].ToString();

				Welcome[0] = _message[1][0][0].ToString();
				Welcome[1] = _message[1][1][0].ToString();
				Welcome[2] = _message[1][2][0].ToString();
				Welcome[3] = _message[1][3][0].ToString();
				Welcome[4] = _message[1][4][0].ToString();
				Welcome[5] = _message[1][5][0].ToString();

				Default[0] = _message[2][0][0].ToString();
				Default[1] = _message[2][1][0].ToString();
				Default[2] = _message[2][2][0].ToString();

				Post[0] = _message[3][0][0].ToString();
				Post[1] = _message[3][1][0].ToString();
				Post[2] = _message[3][2][0].ToString();

				Status[0] = _message[4][0][0].ToString();
				Status[1] = _message[4][1][0].ToString();

				Zen[0] = _message[5][0][0].ToString();
				Zen[1] = _message[5][1][0].ToString();
				Zen[2] = _message[5][2][0].ToString();

				Points[0] = _message[6][0][0].ToString();
				Points[1] = _message[6][1][0].ToString();
				Points[2] = _message[6][2][0].ToString();
				Points[3] = _message[6][3][0].ToString();
				Points[4] = _message[6][4][0].ToString();

				Website = _message[7][0][0].ToString();

				Online[0] = _message[8][0][0].ToString();
				Online[1] = _message[8][1][0].ToString();
				Online[2] = _message[8][2][0].ToString();

				Data[0] = _message[9][0][0].ToString();
				Data[1] = _message[9][1][0].ToString();
				Data[2] = _message[9][2][0].ToString();
				Data[3] = _message[9][3][0].ToString();
				Data[4] = _message[9][4][0].ToString();

				TokenizerRow _firstrow(Data[1]);
				TokenizerRow _secondrow(Data[2]);
				
				if(_firstrow.FieldCount < 7)
				{
					return false;
				}
				else if(_secondrow.FieldCount < 12)
				{
					return false;
				}
				else
				{
					for(int i = 0; i < 7; i++)
					{
						Command::Struct[0].Data.Day[i] = _firstrow[i].ToString();
					}

					for(int i = 0; i < 12; i++)
					{
						Command::Struct[0].Data.Month[i] = _secondrow[i].ToString();
					}
				}

				Add[0] = _message[10][0][0].ToString();
				Add[1] = _message[10][1][0].ToString();
				Add[2] = _message[10][2][0].ToString();
				Add[3] = _message[10][3][0].ToString();
				Add[4] = _message[10][4][0].ToString();

				ReAdd[0] = _message[11][0][0].ToString();
				ReAdd[1] = _message[11][1][0].ToString();

				Select[0] = _message[12][0][0].ToString();
				Select[1] = _message[12][1][0].ToString();
				Select[2] = _message[12][2][0].ToString();

				Warehouse[0] = _message[13][0][0].ToString();
				Warehouse[1] = _message[13][1][0].ToString();
				Warehouse[2] = _message[13][2][0].ToString();
				Warehouse[3] = _message[13][3][0].ToString();
				Warehouse[4] = _message[13][4][0].ToString();
				Warehouse[5] = _message[13][5][0].ToString();

				Evo[0] = _message[14][0][0].ToString();
				Evo[1] = _message[14][1][0].ToString();
				Evo[2] = _message[14][2][0].ToString();

				Class[0] = _message[15][0][0].ToString();
				Class[1] = _message[15][1][0].ToString();
				Class[2] = _message[15][2][0].ToString();
				Class[3] = _message[15][3][0].ToString();
				Class[4] = _message[15][4][0].ToString();
				Class[5] = _message[15][5][0].ToString();
				Class[6] = _message[15][6][0].ToString();

				Repair[0] = _message[16][0][0].ToString();
				Repair[1] = _message[16][1][0].ToString();

				Clear[0] = _message[17][0][0].ToString();
				Clear[1] = _message[17][1][0].ToString();
				Clear[2] = _message[17][2][0].ToString();

				Name[0] = _message[18][0][0].ToString();
				Name[1] = _message[18][1][0].ToString();
				Name[2] = _message[18][2][0].ToString();
				Name[3] = _message[18][3][0].ToString();
				Name[4] = _message[18][4][0].ToString();
				Name[5] = _message[18][5][0].ToString();
				Name[6] = _message[18][6][0].ToString();
				Name[7] = _message[18][7][0].ToString();

				Move[0] = _message[19][0][0].ToString();
				Move[1] = _message[19][1][0].ToString();

				Reset = _message[20][0][0].ToString();

				Master[0] = _message[21][0][0].ToString();
				Master[1] = _message[21][1][0].ToString();

				Marry[0] = _message[22][0][0].ToString();
				Marry[1] = _message[22][1][0].ToString();
				Marry[2] = _message[22][2][0].ToString();
				Marry[3] = _message[22][3][0].ToString();
				Marry[4] = _message[22][4][0].ToString();
				Marry[5] = _message[22][5][0].ToString();
				Marry[6] = _message[22][6][0].ToString();
				Marry[7] = _message[22][7][0].ToString();
				Marry[8] = _message[22][8][0].ToString();
				Marry[9] = _message[22][9][0].ToString();
				Marry[10] = _message[22][10][0].ToString();
				Marry[11] = _message[22][11][0].ToString();
				Marry[12] = _message[22][12][0].ToString();
				Marry[13] = _message[22][13][0].ToString();
				Marry[14] = _message[22][14][0].ToString();
				Marry[15] = _message[22][15][0].ToString();
				Marry[16] = _message[22][16][0].ToString();

				Reload[0] = _message[23][0][0].ToString();
				Reload[1] = _message[23][1][0].ToString();
				Reload[2] = _message[23][2][0].ToString();
				Reload[3] = _message[23][3][0].ToString();

				Block[0] = _message[24][0][0].ToString();
				Block[1] = _message[24][1][0].ToString();
				Block[2] = _message[24][2][0].ToString();
				Block[3] = _message[24][3][0].ToString();
			
				Teleport[0] = _message[25][0][0].ToString();
				Teleport[1] = _message[25][1][0].ToString();
				Teleport[2] = _message[25][2][0].ToString();
				Teleport[3] = _message[25][3][0].ToString();
				Teleport[4] = _message[25][4][0].ToString();
				Teleport[5] = _message[25][5][0].ToString();
				Teleport[6] = _message[25][6][0].ToString();

				Trade[0] = _message[26][0][0].ToString();
				Trade[1] = _message[26][1][0].ToString();

				HappyHour[0] = _message[27][0][0].ToString();
				HappyHour[1] = _message[27][1][0].ToString();
				HappyHour[2] = _message[27][2][0].ToString();
				HappyHour[3] = _message[27][3][0].ToString();
			}
		}

		return true;
	}

	void Message::sendUsers(std::string szMsg)
	{
		for(int i = 4800; i < 5800; i++)
		{
			if(Object[i].Connected > 2)
			{
				ServerMessageSend((char*)szMsg.c_str(), i, 0);
			}
		}
	}
}