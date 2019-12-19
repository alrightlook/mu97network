#pragma once

namespace Network
{
	struct ResetAccumulative
	{
		unsigned short Level;
		unsigned short NextLevel;
		unsigned int Price;
		unsigned long Points;
	};

	struct ResetScoring
	{
		unsigned short Level;
		unsigned short NextLevel;
		unsigned int Price;
		unsigned short Status;
		unsigned long Points;
		unsigned long Quantity;
	};

	struct ResetTabulated
	{
		unsigned long Initial;
		unsigned long Final;
		unsigned short Level;
		unsigned short NextLevel;
		unsigned int Price;
		unsigned short Status;
		unsigned long Points;
		unsigned long Quantity;
	};

	struct ResetStruct
	{
		unsigned char Enable;
		unsigned char NPC;
		unsigned char Type;
		unsigned long Delay;
		std::string String;
		ResetAccumulative Accumulative;
		ResetScoring Scoring;
		ResetTabulated Tabulated[10];
	};

	class Reset
	{
	public:
		static bool initComponents();
		static void initReset(DWORD dwIndex);
		static void initNpcReset(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpNpc);

	public:
		static ResetStruct Struct[6];

	public:
		static std::string Msg;
		static unsigned long Calcule;
		static unsigned long Delay;
		static unsigned char Count[6];
	};
}