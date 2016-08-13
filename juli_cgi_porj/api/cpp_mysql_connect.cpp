#include "cpp_mysql_connect.h"

CppMysqlConn::CppMysqlConn()
{
		mysql_init(&this->mObj);
}

CppMysqlConn::~CppMysqlConn()
{
		mysql_close(&this->mObj);
}


bool CppMysqlConn::connToDataBase(const string& strHostAddr
				, const string& strUsrName
				, const string& strPassWord
				, const string& strDataBaseName)
{
		bool bRet = false;

		if (strHostAddr.empty()
						|| strUsrName.empty()
						|| strPassWord.empty())
		{
				return bRet;
		}

		MYSQL *pRet = mysql_real_connect(&this->mObj , strHostAddr.c_str()
						, strUsrName.c_str() , strPassWord.c_str()
						, strDataBaseName.c_str() , 0 , NULL , 0);
		if (!pRet) return bRet;

		bRet = true;
		return bRet;
}

int CppMysqlConn::queryStringFromDataBase(const string& strQuery 
				, vector< vector<string> > &vecOutput)
{
		int nRet = -1;
		if (strQuery.empty()) return nRet;

		string strChaSet = "set character set 'utf8'";
		string strNames = "set names 'utf8'";
		mysql_real_query(&this->mObj , strChaSet.c_str() , strChaSet.length());
		mysql_real_query(&this->mObj , strNames.c_str() , strNames.length());
		nRet = mysql_real_query(&this->mObj , strQuery.c_str() , strQuery.length());
		if (nRet != 0) return nRet;

		MYSQL_RES *pRes = NULL;
		MYSQL_ROW mrRow;
		pRes = mysql_store_result(&this->mObj);
		while (mrRow = mysql_fetch_row(pRes))
		{
				vector<string> vecTemp;
				for (int i = 0; i < mysql_num_fields(pRes); ++i)
				{
						vecTemp.push_back(mrRow[i]);
				}
				vecOutput.push_back(vecTemp);
		}

		return nRet;
}


bool CppMysqlConn::insertDataToDataBase(const string& strInsertQuery)
{
		bool bRet = false;

		if (strInsertQuery.empty())
		{
				return bRet;
		}

		string strChaSet = "set character set 'utf8'";
		string strNames = "set names 'utf8'";
		mysql_real_query(&this->mObj , strChaSet.c_str() , strChaSet.length());
		mysql_real_query(&this->mObj , strNames.c_str() , strNames.length());

		int nQueryRet = mysql_query(&this->mObj , strInsertQuery.c_str());
		if (0 != nQueryRet) return bRet;

		bRet = true;
		return bRet;
}
