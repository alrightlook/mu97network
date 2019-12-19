#pragma once

namespace Network
{
	struct NoticeStruct
	{
		unsigned char Enable;
		unsigned char Use;
		unsigned long Delay;
		std::string Header;
		std::string Body;
		std::string Footer;
		std::string Address;
	};

	class Function
	{
	public:
		static bool checkFiles(std::string szFile);
		static bool initComponents();
		static short stringExplode(std::string szAddress, std::string szExplode);
		static void hookStruct();
		static void hookFunction(DWORD dwFunction, DWORD dwOffset);
		static void showNotice(LPVOID lpParam);
		static void updateVip(LPVOID lpParam);
		static void updateReset(DWORD dwIndex);
		static bool checkString(std::string szString, std::string szPattern, bool szIgnoreSpace);
		static void clearItem(DWORD dwIndex, BYTE btNumber);
		static void useFirework(DWORD dwIndex);

	public:
		static NoticeStruct Struct[10];

	public:
		static unsigned char Id;
	};
}