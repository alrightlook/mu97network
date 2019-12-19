#pragma once

namespace Network
{
	class Message
	{
	public:
		static bool initComponents();
		static void sendUsers(std::string szMsg);

	public:
		static std::string Announce[2];
		static std::string Welcome[6];
		static std::string Default[3];
		static std::string Post[3];
		static std::string Status[2];
		static std::string Zen[3];
		static std::string Points[5];
		static std::string Website;
		static std::string Online[3];
		static std::string Data[5];
		static std::string Add[5];
		static std::string ReAdd[2];
		static std::string Select[3];
		static std::string Warehouse[6];
		static std::string Evo[3];
		static std::string Class[7];
		static std::string Repair[2];
		static std::string Clear[3];
		static std::string Name[8];
		static std::string Move[2];
		static std::string Reset;
		static std::string Master[2];
		static std::string Marry[17];
		static std::string Reload[4];
		static std::string Block[4];
		static std::string Teleport[7];
		static std::string Trade[2];
		static std::string HappyHour[4];
	};
}