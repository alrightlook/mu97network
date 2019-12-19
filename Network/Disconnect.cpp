#include "Library.h"

namespace Network
{
	DisconnectCheck Disconnect::Check[1000];

	void Disconnect::initAction(PMSG_ACTION* lpMsg, DWORD dwIndex)
	{
		if(!checkAction(dwIndex))
		{
			return;
		}

		ServerActionPlayer(lpMsg, dwIndex);
	}

	bool Disconnect::checkAction(DWORD dwIndex)
	{
		WORD szIndex = (WORD)(dwIndex - 4800);

		if(!Check[szIndex].Send)
		{
			return false;
		}

		if(Check[szIndex].Timer <= 0)
		{
			Check[szIndex].Timer = GetTickCount();
		}
	
		if(Check[szIndex].Count >= 15)
		{
			DWORD dwTimer = (GetTickCount() - Check[szIndex].Timer) / 1000;
		
			if(dwTimer <= 1)
			{
				Check[szIndex].Send = false;
				ServerCloseClient(dwIndex, 0);
			}
			else
			{
				Check[szIndex].Count = 0;
				Check[szIndex].Timer = GetTickCount();
			}
		}

		Check[szIndex].Count++;

		return true;
	}
}