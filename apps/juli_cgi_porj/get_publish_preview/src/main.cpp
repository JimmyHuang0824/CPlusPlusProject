#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cpp_mysql_connect.h"
#include "json_read_write.h"
#include <boost/locale.hpp>

using namespace std;

bool stringToUnicode(const string& strInput , string& strOutput);

int main()
{
		char *pRequestMethod = NULL;
		setvbuf(stdin, NULL, _IONBF, 0);
		pRequestMethod = getenv("REQUEST_METHOD");

		if (strcmp(pRequestMethod , "GET") == 0)
		{
				//从数据库中拉取预览数据
				CppMysqlConn cppMysqlConnObj;
				bool bConnectRet = cppMysqlConnObj.connToDataBase(string("localhost") , string("usr")
								, string("123") , string("juli"));
				if (!bConnectRet) return -1;
				string strQuery = "select id , user_name , title from j_tabhome_data order by id desc";
				vector< vector<string> > vecQueryRet;
				//cout<<vecQueryRet[0][0]<<endl;
				int nQueryRet = cppMysqlConnObj.queryStringFromDataBase(strQuery , vecQueryRet);
				if (0 == nQueryRet)
				{
						//将拉取的数据打包成json格式的数据
						vector<string> vecKeys;
						vecKeys.push_back("id");
						vecKeys.push_back("user_name");
						vecKeys.push_back("title");

						JsonReadWrite jrwObj;
						string strJsonOutput;
						bool bPackRet = jrwObj.packStringListToJsonString(vecQueryRet , vecKeys , strJsonOutput);
						if (bPackRet)
						{
								//发送回客户端
								cout<<"Content-Type:text/html\n\n";
								cout<<strJsonOutput;
						}
				}
		}
		return 0;
}

