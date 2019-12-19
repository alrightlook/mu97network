#include "Library.h"

namespace Network
{
	MapStruct Map::Struct[17];

	bool Map::initComponents()
	{
		Tokenizer _map(".\\Network\\Map.ut");

		if(_map.Loaded)
		{
			if(!_map.SectionExists(0))
			{
				return false;
			}
			else if(!_map.SectionExists(1))
			{
				return false;
			}
			else
			{
				Struct[0].Attack.Map = (BYTE)_map[0][0][0].ToInteger();
				Struct[1].Attack.Map = (BYTE)_map[0][0][1].ToInteger();
				Struct[2].Attack.Map = (BYTE)_map[0][0][2].ToInteger();
				Struct[3].Attack.Map = (BYTE)_map[0][0][3].ToInteger();
				Struct[4].Attack.Map = (BYTE)_map[0][0][4].ToInteger();
				Struct[5].Attack.Map = (BYTE)_map[0][0][5].ToInteger();
				Struct[6].Attack.Map = (BYTE)_map[0][0][6].ToInteger();
				Struct[7].Attack.Map = (BYTE)_map[0][0][7].ToInteger();
				Struct[8].Attack.Map = (BYTE)_map[0][0][8].ToInteger();
				Struct[9].Attack.Map = (BYTE)_map[0][0][9].ToInteger();
				Struct[10].Attack.Map = (BYTE)_map[0][0][10].ToInteger();
				Struct[11].Attack.Map = (BYTE)_map[0][0][11].ToInteger();
				Struct[12].Attack.Map = (BYTE)_map[0][0][11].ToInteger();
				Struct[13].Attack.Map = (BYTE)_map[0][0][11].ToInteger();
				Struct[14].Attack.Map = (BYTE)_map[0][0][11].ToInteger();
				Struct[15].Attack.Map = (BYTE)_map[0][0][11].ToInteger();
				Struct[16].Attack.Map = (BYTE)_map[0][0][11].ToInteger();

				Struct[0].LevelUp.Map = (BYTE)_map[1][0][0].ToInteger();
				Struct[1].LevelUp.Map = (BYTE)_map[1][0][1].ToInteger();
				Struct[2].LevelUp.Map = (BYTE)_map[1][0][2].ToInteger();
				Struct[3].LevelUp.Map = (BYTE)_map[1][0][3].ToInteger();
				Struct[4].LevelUp.Map = (BYTE)_map[1][0][4].ToInteger();
				Struct[5].LevelUp.Map = (BYTE)_map[1][0][5].ToInteger();
				Struct[6].LevelUp.Map = (BYTE)_map[1][0][6].ToInteger();
				Struct[7].LevelUp.Map = (BYTE)_map[1][0][7].ToInteger();
				Struct[8].LevelUp.Map = (BYTE)_map[1][0][8].ToInteger();
				Struct[9].LevelUp.Map = (BYTE)_map[1][0][9].ToInteger();
				Struct[10].LevelUp.Map = (BYTE)_map[1][0][10].ToInteger();
				Struct[11].LevelUp.Map = (BYTE)_map[1][0][11].ToInteger();
				Struct[12].LevelUp.Map = (BYTE)_map[1][0][11].ToInteger();
				Struct[13].LevelUp.Map = (BYTE)_map[1][0][11].ToInteger();
				Struct[14].LevelUp.Map = (BYTE)_map[1][0][11].ToInteger();
				Struct[15].LevelUp.Map = (BYTE)_map[1][0][11].ToInteger();
				Struct[16].LevelUp.Map = (BYTE)_map[1][0][11].ToInteger();

				return true;
			}
		}

		return false;
	}

	void Map::initAttack(PMSG_ATTACK* lpMsg, DWORD dwIndex)
	{
		BYTE szMap = (BYTE)Object[dwIndex].Map;
		
		if(Struct[szMap].Attack.Map == 0)
		{
			return;
		}
		
		ServerObjAttack(lpMsg, dwIndex);
	}

	bool Map::initLevelUp(OBJECTSTRUCT* lpObject, int AddExp, int MonsterType, int EventType)
	{
		BYTE szMap = (BYTE)lpObject->Map;
		
		if(Struct[szMap].LevelUp.Map == 0)
		{
			return false;
		}

		return ServerLevelUp(lpObject, AddExp, MonsterType, EventType);
	}

	int Map::initMonsterExp(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpTarget, int Damage, int TotalDamage, bool& SendExp)
	{
		BYTE szMap = (BYTE)lpObject->Map;
		
		if(Struct[szMap].LevelUp.Map == 0)
		{
			return 0;
		}

		return ServerMonsterExp(lpObject, lpTarget, Damage, TotalDamage, SendExp);
	}
}