#pragma once

namespace Network
{
	struct PMSG_USEITEM
	{
		PBMSG_HEAD h;
		unsigned char Pos;
		unsigned char Target;
		unsigned char Type;
	};

	struct SkillStruct
	{
		unsigned short	Item;
		unsigned short	Level;
		unsigned short	Strength;
		unsigned short	Dexterity;
		unsigned short	Energy;
		 unsigned char	Class[4];
	};

	class Skill
	{
	public:
		static bool initComponents();
		static void initUse(PMSG_USEITEM* lpMsg, DWORD dwIndex);
	
	public:
		static SkillStruct Struct[30];
	};
}