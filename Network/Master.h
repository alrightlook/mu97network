#pragma once

namespace Network
{
	struct MasterStruct 
	{
		unsigned char Enable;
		unsigned short Level;
		unsigned short NextLevel;
		unsigned int Price;
		unsigned long Status;
		unsigned long NextStatus;
		unsigned char ZeroPoints;
		unsigned char ZeroResets;
		unsigned long Delay;
		std::string String;
	};

	class Master
	{
	public:
		static bool initComponents();
		static void initMaster(DWORD dwIndex);
		static void initNpcMaster(OBJECTSTRUCT* lpObject, OBJECTSTRUCT* lpNpc);

	public:
		static MasterStruct Struct[6];

	public:
		static std::string Msg;
		static unsigned long Calcule;
		static unsigned long Delay;
	};
}