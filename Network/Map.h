#pragma once

namespace Network
{
	struct PMSG_ATTACK
	{
		PBMSG_HEAD h;
		BYTE NumberH;
		BYTE NumberL;
		BYTE AttackAction;
		BYTE DirDis;
	};

	struct AttackStruct
	{
		unsigned char Map;
	};

	struct LevelUpStruct
	{
		unsigned char Map;
	};

	struct MapStruct
	{
		AttackStruct Attack;
		LevelUpStruct LevelUp;
	};

	class Map
	{
	public:
		static bool initComponents();
		static void initAttack(PMSG_ATTACK* lpMsg, DWORD dwIndex);
		static bool initLevelUp(OBJECTSTRUCT* lpObject, int AddExp, int MonsterType, int EventType);
		static int initMonsterExp(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpTarget, int Damage, int TotalDamage, bool& SendExp);

	public:
		static MapStruct Struct[17];
	};
}