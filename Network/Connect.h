#pragma once

namespace Network
{
	class Connect
	{
	public:
		static bool initComponents();
		static bool initConnection();
		static void finishConnection();
		static bool executeQuery(std::string szQuery, ...);
		static void freeComponents();
		static int getInteger(int iColumn);
		static std::string getString(int iColumn);

	public:
		static std::string ArrayValues[5];

	private:
		static bool Connected;
		static std::string Data;
		static SQLHENV Environment;
		static SQLHDBC Connection;
		static SQLHSTMT Statement;
		static SQLINTEGER Row;
		static SQLSMALLINT Column;
	};
}