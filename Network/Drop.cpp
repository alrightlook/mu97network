#include "Library.h"

namespace Network
{
	DropStruct Drop::Struct[1000];
	unsigned short Drop::Count;

	bool Drop::initComponents()
	{
		Tokenizer _drop(".\\Network\\Drop\\Drop.ut");

		if(_drop.Loaded)
		{
			if(!_drop.SectionExists(0))
			{
				return false;
			}
			else
			{
				Count = (_drop[0].RowCount > 1000) ? 100 : _drop[0].RowCount;

				for(int i = 0; i < Count; i++)
				{
					Struct[i].Type		 = (unsigned char)_drop[0][i][0].ToInteger();
					Struct[i].Index		 = (unsigned char)_drop[0][i][1].ToInteger();
					Struct[i].Level		 = (unsigned char)_drop[0][i][2].ToInteger();
					Struct[i].Luck		 = (unsigned char)_drop[0][i][3].ToInteger();
					Struct[i].Skill		 = (unsigned char)_drop[0][i][4].ToInteger();
					Struct[i].Optional	 = (unsigned char)_drop[0][i][5].ToInteger();
					Struct[i].Excellent  = (unsigned char)_drop[0][i][6].ToInteger();
					Struct[i].Durability = (unsigned char)_drop[0][i][7].ToInteger();
					Struct[i].MinLevel	 = (unsigned short)_drop[0][i][8].ToInteger();
					Struct[i].MaxLevel	 = (unsigned short)_drop[0][i][9].ToInteger();
					Struct[i].Rate		 = (_drop[0][i][10].ToInteger() > 65535) ? 65535 : (unsigned short)_drop[0][i][10].ToInteger();
				}
			}
		}

		return true;
	}

	int Drop::itemDrop(OBJECTSTRUCT* lpMonster, OBJECTSTRUCT* lpObject)
	{
		for(int i = 0; i < Count; i++)
		{
			if(lpMonster->Level >= Struct[i].MinLevel && lpMonster->Level <= Struct[i].MaxLevel)
			{
				WORD wdRand = (rand() % Struct[i].Rate);

				if(wdRand >= (10000 - Struct[i].Rate))
				{
					DWORD dwItem = ITEMGET(Struct[i].Type, Struct[i].Index);
					DWORD dwDamage = ServerTopHitDamage(lpMonster);

					ServerItemCreate(lpMonster->m_Index, (DWORD)lpMonster->Map, (DWORD)lpMonster->X, (DWORD)lpMonster->Y, dwItem, (DWORD)Struct[i].Level, (DWORD)Struct[i].Durability, (DWORD)Struct[i].Skill, (DWORD)Struct[i].Luck, (DWORD)Struct[i].Optional, dwDamage, (DWORD)Struct[i].Excellent);
					return 1;
				}
			}
		}

		return ServerMonsterItemDrop(lpMonster, lpObject);
	}
}