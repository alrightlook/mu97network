#include "Library.h"

namespace Network
{
	TradeStruct Trade::Struct[15];

	bool Trade::initComponents()
	{
		Tokenizer _trade(".\\Network\\Trade.ut");

		if(_trade.Loaded)
		{
			if(!_trade.SectionExists(0))
			{
				return false;
			}
			else if(!_trade.SectionExists(1))
			{
				return false;
			}
			else
			{
				Struct[0].Enable = (unsigned char)_trade[0][0][0].ToInteger();
				Struct[1].Enable = (unsigned char)_trade[1][0][0].ToInteger();
				
				for(int i = 0; i < 15; i++)
				{
					if(i < 12)
					{
						Struct[i].Map = (unsigned char)_trade[0][1][i].ToInteger();
					}

					if(i < _trade[1].RowCount)
					{
						Struct[i].SafeMap = (unsigned char)_trade[1][i][0].ToInteger();
						Struct[i].SafeX   = (unsigned char)_trade[1][i][1].ToInteger();
						Struct[i].SafeY	  = (unsigned char)_trade[1][i][2].ToInteger();
					}
				}
			}
		}

		return true;
	}

	bool Trade::initMap(DWORD dwIndex)
	{
		if(Struct[0].Enable == 0)
		{
			return true;
		}

		BYTE szMap = (Object[dwIndex].Map > 11) ? 11 : Object[dwIndex].Map;

		if(Struct[szMap].Map == 0)
		{
			ServerMessageSend((char*)Message::Trade[0].c_str(), dwIndex, 1);
			return false;
		}

		return true;
	}

	bool Trade::initSafe(DWORD dwIndex)
	{
		if(Struct[1].Enable == 0)
		{
			return true;
		}

		bool szProceed;

		for(int i = 0; i < 10; i++)
		{
			int X[11] = {(-5), (-4), (-3), (-2), (-1), 0, 1, 2, 3, 4, 5};
			int Y[11] = {(-5), (-4), (-3), (-2), (-1), 0, 1, 2, 3, 4, 5};

			if(Object[dwIndex].Map == Struct[i].SafeMap)
			{
				X[0] += Struct[i].SafeX;
				X[1] += Struct[i].SafeX;
				X[2] += Struct[i].SafeX;
				X[3] += Struct[i].SafeX;
				X[4] += Struct[i].SafeX;
				X[5] += Struct[i].SafeX;
				X[6] += Struct[i].SafeX;
				X[7] += Struct[i].SafeX;
				X[8] += Struct[i].SafeX;
				X[9] += Struct[i].SafeX;
				X[10] += Struct[i].SafeX;

				Y[0] += Struct[i].SafeY;
				Y[1] += Struct[i].SafeY;
				Y[2] += Struct[i].SafeY;
				Y[3] += Struct[i].SafeY;
				Y[4] += Struct[i].SafeY;
				Y[5] += Struct[i].SafeY;
				Y[6] += Struct[i].SafeY;
				Y[7] += Struct[i].SafeY;
				Y[8] += Struct[i].SafeY;
				Y[9] += Struct[i].SafeY;
				Y[10] += Struct[i].SafeY;

				if(Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[0] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[1] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[2] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[3] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[4] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[5] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[6] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[7] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[8] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[9] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else if(Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[0] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[1] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[2] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[3] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[4] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[5] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[6] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[7] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[8] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[9] || Object[dwIndex].X == X[10] && Object[dwIndex].Y == Y[10])
				{
					szProceed = false;
				}
				else 
				{
					szProceed = true;
				}

				if(!szProceed)
				{
					ServerMessageSend((char*)Message::Trade[1].c_str(), dwIndex, 1);
					return false;
				}
			}
		}

		return true;
	}

	void Trade::initRequest(PMSG_TRADE_REQUEST* lpMsg, DWORD dwIndex)
	{
		if(Object[dwIndex].Live == 1)
		{
			WORD szTarget = (WORD)Object[dwIndex].TargetNumber;

			if(Object[dwIndex].m_IfState.use == 1 && Object[dwIndex].m_IfState.type == 1 && Object[dwIndex].pTransaction == 1)
			{
				if(Object[szTarget].Type == 1)
				{
					ServerCancelTrade(dwIndex);
					return;
				}
			}

			if(!initMap(dwIndex))
			{
				return;
			}
			else if(!initSafe(dwIndex))
			{
				return;
			}
			else
			{
				ServerRequestTrade(lpMsg, dwIndex);
			}
		}
	}

	void Trade::initResponse(PMSG_TRADE_RESPONSE* lpMsg, DWORD dwIndex)
	{
		if(Object[dwIndex].Live == 1)
		{
			WORD szTarget = (WORD)Object[dwIndex].TargetNumber;

			if(Object[dwIndex].m_IfState.use == 1 && Object[dwIndex].m_IfState.type == 1 && Object[dwIndex].pTransaction == 1)
			{
				if(Object[szTarget].Type == 1)
				{
					ServerCancelTrade(dwIndex);
					return;
				}
			}

			if(!initMap(dwIndex))
			{
				return;
			}
			else if(!initSafe(dwIndex))
			{
				return;
			}
			else
			{
				ServerResponseTrade(lpMsg, dwIndex);
			}
		}
	}

	void Trade::initCancel(DWORD dwIndex)
	{
		if(Object[dwIndex].Live == 1)
		{
			ServerCancelTrade(dwIndex);
		}
	}
}