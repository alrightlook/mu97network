#include "Library.h"

namespace Network
{
	int Ring::initDrop(PMSG_ITEMTHROW* lpMsg, DWORD dwIndex, int szDrop)
	{
		if(Object[dwIndex].Type == 1 && Object[dwIndex].Live == 0)
		{
			lpMsg->Pos = 80;
		}

		return ServerItemDrop(lpMsg, dwIndex, szDrop);
	}

	void Ring::initMove(PMSG_INVENTORYITEMMOVE* lpMsg, DWORD dwIndex)
	{
		if(Object[dwIndex].Type == 1 && Object[dwIndex].Live == 0)
		{
			BYTE szItem[4];
			ServerItemMoveResult(dwIndex, (-1), 0, szItem);
			return;
		}

		ServerItemMove(lpMsg, dwIndex);
	}
}