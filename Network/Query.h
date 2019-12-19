#pragma once

namespace Network
{
	class Query
	{
	public:
		static bool initComponents();

	public:
		static std::string Vip;
		static std::string Data[2];
		static std::string Status[2];
		static std::string Warehouse[2];
		static std::string Name[4];
		static std::string Reset[6];
		static std::string Master[13];
		static std::string Marry[3];
		static std::string Block[6];
	};
}