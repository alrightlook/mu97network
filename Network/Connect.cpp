#include "Library.h"

namespace Network
{
	bool Connect::Connected;
	std::string Connect::Data;
	SQLHENV Connect::Environment;
	SQLHDBC Connect::Connection;
	SQLHSTMT Connect::Statement;
	SQLINTEGER Connect::Row;
	SQLSMALLINT Connect::Column;
	std::string Connect::ArrayValues[5];

	bool Connect::initComponents()
	{
		Connected	= false;
		Connection	= SQL_NULL_HANDLE;
		Environment = SQL_NULL_HANDLE;
		Statement	= SQL_NULL_HANDLE;

		Tokenizer _connect(".\\Network\\Connect.ut");
		
		std::stringstream Msg;

		if(_connect.Loaded)
		{
			if(_connect.SectionExists(0))
			{
				std::stringstream Msg;

				for(int i = 0; i < (int)_connect[0].RowCount; i++)
				{
					Msg << "DRIVER={SQL Server}; SERVER=" << _connect[0][i][0].ToString() << "; UID=" << _connect[0][i][1].ToString() << "; PWD=" << _connect[0][i][2].ToString() << "; DATABASE=" << _connect[0][i][3].ToString() << ";";
					Data = Msg.str();

					if(initConnection())
					{
						return true;
					}
				}
			}
		}

		return false;
	}

	bool Connect::initConnection()
	{
		if((!Connected))
		{
			if(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &Environment)))
			{
				if(!SQL_SUCCEEDED(SQLSetEnvAttr(Environment, SQL_ATTR_ODBC_VERSION, (LPVOID)SQL_OV_ODBC3, 0)))
				{
					freeComponents();
					return false;
				}

				if(!SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC, Environment, &Connection)))
				{
					freeComponents();
					return false;
				}

				SQLCHAR szOut[1024];
				SQLSMALLINT szSize = 0;

				SQLSetConnectOption(Connection, SQL_LOGIN_TIMEOUT, 3);
				SQLSetConnectOption(Connection, SQL_CURSOR_TYPE, SQL_CURSOR_STATIC);

				if(!SQL_SUCCEEDED(SQLDriverConnect(Connection, NULL, (SQLCHAR*)Data.c_str(), SQL_NTS, szOut, 1024, &szSize, SQL_DRIVER_NOPROMPT)))
				{
					freeComponents();
					return false;
				}

				Connected = true;
				return true;
			}
		}

		freeComponents();
		return false;
	}

	void Connect::finishConnection()
	{
		if(Connected)
		{
			SQLDisconnect(Connection);
			freeComponents();
		}

		Connected = false;
	}

	void Connect::freeComponents()
	{
		if(Connection != SQL_NULL_HANDLE)
		{
			SQLFreeHandle(SQL_HANDLE_DBC, Connection);
			Connection = SQL_NULL_HANDLE;
		}

		if(Environment != SQL_NULL_HANDLE)
		{
			SQLFreeHandle(SQL_HANDLE_ENV, Environment);
			Environment = SQL_NULL_HANDLE;
		}

		if(Statement != SQL_NULL_HANDLE)
		{
			SQLFreeHandle(SQL_HANDLE_STMT, Statement);
			Statement = SQL_NULL_HANDLE;
		}
	}

	bool Connect::executeQuery(std::string szQuery, ...)
	{
		if(Connected)
		{
			if(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT, Connection, &Statement)))
			{
				std::string szBuffer(1024, ' ');

				va_list szList;
				va_start(szList, szQuery);
				vsprintf_s(&szBuffer[0], 1024, szQuery.c_str(), szList);
				va_end(szList);
								
				if(SQL_SUCCEEDED(SQLPrepare(Statement, (SQLCHAR*)&szBuffer.c_str()[0], szBuffer.length())))
				{
					SQLRETURN szReturn = 0;				
					szReturn = SQLExecute(Statement);

					if(szReturn == SQL_SUCCESS || szReturn == SQL_SUCCESS_WITH_INFO || szReturn == SQL_NO_DATA)
					{
						if(SQLRowCount(Statement, &Row) != SQL_SUCCESS)
						{
							Row = 0;
						}

						if(SQLNumResultCols(Statement, &Column) != SQL_SUCCESS)
						{
							Column = 0;
						}
					}

					return true;
				}
			}
		}

		return false;
	}

	int Connect::getInteger(int szColumn)
	{
		SQLINTEGER szResult = 0, szSize = 0;
	
		while(true)
		{
			if(!SQL_SUCCEEDED(SQLFetch(Statement)))
			{
				break;
			}

			if(!SQL_SUCCEEDED(SQLGetData(Statement, szColumn, SQL_C_LONG, &szResult, sizeof(long), &szSize)))
			{
				break;
			}

			return szResult;
		}

		return 0;
	}

	std::string Connect::getString(int szColumn)
	{
		if(szColumn == (-1))
		{
			for(int i = 0; i < 5; i++)
			{
				ArrayValues[i] = "";
			}

			return "";
		}

		bool szProceed = true;
		SQLCHAR szResult[1024];
		SQLINTEGER szSize = 0;
		std::string szValue = "";

		while(true)
		{
			if(!SQL_SUCCEEDED(SQLFetch(Statement)))
			{
				break;
			}
		
			for(int i = szColumn; i < (Column + 1); i++)
			{
				if(!SQL_SUCCEEDED(SQLGetData(Statement, i, SQL_C_CHAR, &szResult, 1024, &szSize)))
				{
					break;
				}

				szValue.assign((char*)&szResult[0]);
				ArrayValues[(i - 1)] = szValue;
			}

			szProceed = true;
		}

		if(szProceed)
		{
			return ArrayValues[0];
		}

		return "";
	}
}