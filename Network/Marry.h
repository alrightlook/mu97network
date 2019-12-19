#pragma once

namespace Network
{
	struct MarryStruct
	{
		bool Married;
		std::string Name;
		unsigned long Target;
		unsigned long Timer;
	};

	class Marry
	{
	public:
		static bool initComponents();
		static bool initCalculePosition(DWORD dwIndex, WORD szIndex);
		static bool initCheckSexuallity(DWORD dwIndex, WORD szIndex);
		static void initFireworkMarry(DWORD dwIndex, DWORD dwTarget);
		static void initPropose(DWORD dwIndex, std::string szMsg);
		static void initAccept(DWORD dwIndex);
		static void initDivorce(DWORD dwIndex);
		static void initTrace(DWORD dwIndex);

	public:
		static MarryStruct Struct[1000];
	
	public:
		static bool Enable;
		static std::string String[2];
		static std::string Msg;
	};
}