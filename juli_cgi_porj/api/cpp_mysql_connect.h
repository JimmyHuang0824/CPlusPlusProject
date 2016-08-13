#ifndef _CPP_MYSQL_CONNECT_H
#define _CPP_MYSQL_CONNECT_H

#include <vector>
#include <string>
#include <mysql/mysql.h>

using namespace std;

class CppMysqlConn
{
	public:
	CppMysqlConn();
	~CppMysqlConn();
	bool connToDataBase(const string& strHostAddr
					, const string& strUsrName
					, const string& strPassWord
					, const string& strDataBaseName);
	
	int queryStringFromDataBase(const string& strQuery 
								, vector< vector<string> > &vecOutput);

	bool insertDataToDataBase(const string& strInsertQuery);

	private:
	MYSQL mObj;

};
#endif
