#pragma once

namespace Network
{
	struct FloodCheck
	{
		bool Send;
		bool Delete;
		unsigned long Timer;
		unsigned long Count;
		std::string Address;
	};

	struct FloodStruct
	{
		FloodCheck Check;
		std::string Address;
	};

	class Flood
	{
	public:
		static bool initComponents();
		static bool checkConnection(std::string szAddress);
		static short initConnection(SOCKET szSocket, char* szAddress);

	public:
		static FloodStruct Struct[500];

	public:
		static unsigned long Count;
	};
}