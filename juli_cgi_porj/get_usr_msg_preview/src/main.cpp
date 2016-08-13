#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cpp_mysql_connect.h"
#include "json_read_write.h"
#include "string_deal_utils.h"
#include "print_error_log.h"

using namespace std;

int main()
{
		char *pRequestMethod = NULL;
		//char *pRequestMethod = "id=1";
		setvbuf(stdin, NULL, _IONBF, 0);
		pRequestMethod = getenv("REQUEST_METHOD");
		PrintErrorLog printErrorLogObj;
		string strErrorLogPath = "get_usr_msg_preview_error.log";
		StringDealUtils stringDealUtilsObj;

		if (strcmp(pRequestMethod , "GET") == 0)
		{
				//cout<<string(pRequestMethod);
				char *pGetParam = getenv("QUERY_STRING");
				//切割字符串
				vector<string> strRet = stringDealUtilsObj.splitString(string(pGetParam) , string("="));
				if (strRet.empty()
								|| strRet[0] != string("usr_name"))
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"get param error";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "get param error");
						return -1;
				}
				string strUsrName = stringDealUtilsObj.convFromHttpStringToUtf8(strRet[1]);

				//从数据库中拉取预览数据
				CppMysqlConn cppMysqlConnObj;
				bool bConnectRet = cppMysqlConnObj.connToDataBase(string("localhost") , string("usr")
								, string("123") , string("juli"));
				if (!bConnectRet)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"db connect failed";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "db connect failed");
					   	return -2;
				}

				string strQuery = string("select content_id , count(content_id) from j_tabhome_msg where from_usr='") 
									+ strUsrName + string("' or to_usr='") + strUsrName + string("' group by content_id");
				vector< vector<string> > vecQueryRet;
				int nQueryRet = cppMysqlConnObj.queryStringFromDataBase(strQuery , vecQueryRet);
				if (nQueryRet != 0)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"db query error";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "db query error");
					   	return -3;
				}
				else if (0 == nQueryRet && vecQueryRet.empty())
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"nothing";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "nothing query");
					   	return -4;
				}
				else
				{
						//将拉取的数据打包成json格式的数据
						vector<string> vecKeys;
						vecKeys.push_back("content_id");
						vecKeys.push_back("msg_count");

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


