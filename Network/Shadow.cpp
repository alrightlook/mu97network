#include "Library.h"

namespace Network
{
	int Shadow::initBless(OBJECTSTRUCT* lpObj, int szSource, int szTarget)
	{
		if(lpObj->pInventory[szTarget].m_Type >= ITEMGET(12, 7))
		{
			return 0;
		}

		return ServerItemBlessUp(lpObj, szSource, szTarget);
	}

	int Shadow::initSoul(OBJECTSTRUCT* lpObj, int szSource, int szTarget)
	{
		if(lpObj->pInventory[szTarget].m_Type >= ITEMGET(12, 7))
		{
			return 0;
		}

		return ServerItemSoulUp(lpObj, szSource, szTarget);
	}

	int Shadow::initLife(OBJECTSTRUCT* lpObj, int szSource, int szTarget)
	{
		if(lpObj->pInventory[szTarget].m_Type >= ITEMGET(12, 7))
		{
			return 0;
		}

		return ServerItemLifeUp(lpObj, szSource, szTarget);
	}
}