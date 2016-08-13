#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cpp_mysql_connect.h"
#include "json_read_write.h"

#include <boost/locale.hpp>

using namespace std;


vector<string> splitString(const string& strInput , const string& strPattern);

int main()
{
		char *pRequestMethod = NULL;
		//char *pRequestMethod = "id=1";
		setvbuf(stdin, NULL, _IONBF, 0);
		pRequestMethod = getenv("REQUEST_METHOD");

		if (strcmp(pRequestMethod , "GET") == 0)
		{
				//cout<<string(pRequestMethod);
				char *pGetParam = getenv("QUERY_STRING");
				//切割字符串
				vector<string> strRet = splitString(string(pGetParam) , string("="));
				if (strRet.empty()) return -1;

				//从数据库中拉取预览数据
				CppMysqlConn cppMysqlConnObj;
				bool bConnectRet = cppMysqlConnObj.connToDataBase(string("localhost") , string("usr")
								, string("123") , string("juli"));
				if (!bConnectRet) return -1;

				string strQuery = string("select id , content from j_tabhome_detail where id = ") + strRet[1];
				vector< vector<string> > vecQueryRet;
				int nQueryRet = cppMysqlConnObj.queryStringFromDataBase(strQuery , vecQueryRet);
				if (0 == nQueryRet)
				{
						//将拉取的数据打包成json格式的数据
						vector<string> vecKeys;
						vecKeys.push_back("id");
						vecKeys.push_back("content");

						string strJsonOutput;
						JsonReadWrite jrwObj;
						bool bPackRet = jrwObj.packStringListToJsonString(vecQueryRet , vecKeys , strJsonOutput);
						
						if (bPackRet)
						{
								////发送回客户端
								cout<<"Content-Type:text/html\n\n";
								cout<<strJsonOutput;
						}
				}
		}
		return 0;
}


vector<string> splitString(const string& strInput , const string& strPattern)
{
	vector<string> strRet;
	if(strPattern.empty()) return strRet;
	size_t szStart = 0;
	size_t szIndex = strInput.find_first_of(strPattern , 0);

	while(szIndex != strInput.npos)
	{
			if(szStart != szIndex)
			{
				strRet.push_back(strInput.substr(szStart,szIndex - szStart));
			}
			szStart = szIndex+1;
			szIndex = strInput.find_first_of(strPattern , szStart);
	}
	if(!strInput.substr(szStart).empty())
	{
		strRet.push_back(strInput.substr(szStart));
	}
	return strRet;
}
