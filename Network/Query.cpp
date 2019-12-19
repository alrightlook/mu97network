#include "Library.h"

namespace Network
{
	std::string Query::Vip;
	std::string Query::Data[2];
	std::string Query::Status[2];
	std::string Query::Warehouse[2];
	std::string Query::Name[4];
	std::string Query::Reset[6];
	std::string Query::Master[13];
	std::string Query::Marry[3];
	std::string Query::Block[6];

	bool Query::initComponents()
	{
		Tokenizer _query(".\\Network\\Query.ut");

		if(_query.Loaded)
		{
			if(!_query.SectionExists(0))
			{
				return false;
			}
			else if(!_query.SectionExists(1))
			{
				return false;
			}
			else if(!_query.SectionExists(2))
			{
				return false;
			}
			else if(!_query.SectionExists(3))
			{
				return false;
			}
			else if(!_query.SectionExists(4))
			{
				return false;
			}
			else if(!_query.SectionExists(5))
			{
				return false;
			}
			else if(!_query.SectionExists(6))
			{
				return false;
			}
			else if(!_query.SectionExists(7))
			{
				return false;
			}
			else
			{
				Vip		= _query[0][0][0].ToString();
				Data[0] = _query[0][1][0].ToString();
				Data[1] = _query[0][2][0].ToString();

				Status[0] = _query[1][0][0].ToString();
				Status[1] = _query[1][1][0].ToString();

				Warehouse[0] = _query[2][0][0].ToString();
				Warehouse[1] = _query[2][1][0].ToString();

				Name[0] = _query[3][0][0].ToString();
				Name[1] = _query[3][1][0].ToString();
				Name[2] = _query[3][2][0].ToString();
				Name[3] = _query[3][3][0].ToString();

				Reset[0] = _query[4][0][0].ToString();
				Reset[1] = _query[4][1][0].ToString();
				Reset[2] = _query[4][2][0].ToString();
				Reset[3] = _query[4][3][0].ToString();
				Reset[4] = _query[4][4][0].ToString();
				Reset[5] = _query[4][5][0].ToString();

				Master[0] = _query[5][0][0].ToString();
				Master[1] = _query[5][1][0].ToString();
				Master[2] = _query[5][2][0].ToString();
				Master[3] = _query[5][3][0].ToString();
				Master[4] = _query[5][4][0].ToString();
				Master[5] = _query[5][5][0].ToString();
				Master[6] = _query[5][6][0].ToString();
				Master[7] = _query[5][7][0].ToString();
				Master[8] = _query[5][8][0].ToString();
				Master[9] = _query[5][9][0].ToString();
				Master[10] = _query[5][10][0].ToString();
				Master[11] = _query[5][11][0].ToString();
				Master[12] = _query[5][12][0].ToString();
				
				Marry[0] = _query[6][0][0].ToString();
				Marry[1] = _query[6][1][0].ToString();
				Marry[1] = _query[6][2][0].ToString();

				Block[0] = _query[7][0][0].ToString();
				Block[1] = _query[7][1][0].ToString();
				Block[2] = _query[7][2][0].ToString();
				Block[3] = _query[7][3][0].ToString();
				Block[4] = _query[7][4][0].ToString();
				Block[5] = _query[7][5][0].ToString();
			}
		}

		return true;
	}
}