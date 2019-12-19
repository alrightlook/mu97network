#pragma once

namespace Network
{
	struct DropStruct
	{
		unsigned char Type;
		unsigned char Index;
		unsigned char Level;
		unsigned short MinLevel;
		unsigned short MaxLevel;
		unsigned char Optional;
		unsigned char Luck;
		unsigned char Skill;
		unsigned char Excellent;
		unsigned char Durability;
		unsigned short Rate;
	};

	class Drop
	{
	public:
		static bool initComponents();
		static int itemDrop(OBJECTSTRUCT* lpMonster, OBJECTSTRUCT* lpObject);

	public:
		static DropStruct Struct[1000];

	public:
		static unsigned short Count;
	};
}