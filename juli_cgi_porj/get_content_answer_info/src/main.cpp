#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "cpp_mysql_connect.h"
#include "json_read_write.h"
#include "string_deal_utils.h"
#include "print_error_log.h"
#include "boost/locale.hpp"

using namespace std;

bool stringToUnicode(const string& strInput , string& strOutput);

int main()
{
		char *pRequestMethod = NULL;
		setvbuf(stdin, NULL, _IONBF, 0);
		pRequestMethod = getenv("REQUEST_METHOD");

		string strErrorLogPath = "get_content_answer_error.log";
		PrintErrorLog printErrorLogObj;
		if (strcmp(pRequestMethod , "GET") == 0)
		{
				//cout<<string(pRequestMethod);
				char *pGetParam = getenv("QUERY_STRING");

				//切割字符串
				StringDealUtils stringDealUtilsObj;
				//第一次切割
				//vector<string> vecSplitId = stringDealUtilsObj.splitString(string(pGetParam) 
				//				, string("="));
				//if (vecSplitId[0] != string("content_id"))
				//{
				//		cout<<"Content-Type:text/html\n\n";
				//		cout<<"Get param invalid!";
				//		return -1;
				//}
				//string strContentId = vecSplitId[1];
				vector<string> vecSplitAll = stringDealUtilsObj.splitString(string(pGetParam) , string("&"));
				if (vecSplitAll.size() != 2)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Get param invalid!";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Get param all invalid!");
						return -1;
				}
				//第二次切割
				vector<string> vecSplitId = stringDealUtilsObj.splitString(vecSplitAll[0] , string("="));
				if (vecSplitId[0] != string("content_id"))
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Get param invalid!";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Get param content_id invalid!");
						return -1;
				}
				string strContentId = vecSplitId[1];
					
				vector<string> vecSplitFromUsr = stringDealUtilsObj.splitString(vecSplitAll[1] , string("="));
				if (vecSplitFromUsr[0] != string("from_usr"))
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Get param invalid!";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Get param from usr invalid!");
						return -1;
				}
				string strFromUsr = stringDealUtilsObj.convFromHttpStringToUtf8(vecSplitFromUsr[1]);

				//连接数据库
				CppMysqlConn cppMysqlConnObj;
				bool bConnectRet = cppMysqlConnObj.connToDataBase(string("localhost") , string("usr")
								, string("123") , string("juli"));
				if (!bConnectRet)
				{
						cout<<"Content-Type:text/html\n\n";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Connect to db failed!");
						return -2;
				}


				//查询数据
				string strCheckToUsrQuery = string("select user_name from j_tabhome_data where id=")
											+ strContentId;
				vector< vector<string> > vecQueryRet;
				int nQueryRet = cppMysqlConnObj.queryStringFromDataBase(strCheckToUsrQuery , vecQueryRet);
				if (0 == nQueryRet && vecQueryRet.empty())
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Nothing!";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "None to_usr Query!");	
						return -3;
				}
				else if (0 != nQueryRet
								|| (int)vecQueryRet.size() > 1)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Nothing!";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Query Error!"); 
						return -4;
				}

				string strQuery;
				if (vecQueryRet[0][0] == strFromUsr)
				{
						strQuery = string("select content_id, create_time, from_usr, to_usr, msg_text from j_tabhome_msg where content_id=")
									+ strContentId + string(" order by create_time");
				}
				else
				{
						strQuery = string("select content_id, create_time, from_usr, to_usr, msg_text from j_tabhome_msg where content_id=")
									+ strContentId + string(" and (from_usr='") + strFromUsr + string("' or to_usr='")
									+ strFromUsr + string("') order by create_time");
				}

				vector< vector<string> > vecMsgQueryRet;
				//vecQueryRet.clear();
				nQueryRet = cppMysqlConnObj.queryStringFromDataBase(strQuery , vecMsgQueryRet);
				if (nQueryRet == 0 && vecMsgQueryRet.empty())
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Nothing!";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Nothing msg Query!");	
						return -3;
				}

				if (0 == nQueryRet)
				{
						//将拉取的数据打包成json格式的数据
						vector<string> vecKeys;
						vecKeys.push_back("content_id");
						vecKeys.push_back("create_time");
						vecKeys.push_back("from_usr");
						vecKeys.push_back("to_usr");
						vecKeys.push_back("msg_text");

						JsonReadWrite jrwObj;
						string strJsonOutput;
						bool bPackRet = jrwObj.packStringListToJsonString(vecMsgQueryRet , vecKeys , strJsonOutput);

						if (bPackRet)
						{
								//发送回客户端
								cout<<"Content-Type:text/html\n\n";
								cout<<strJsonOutput;
						}
						else
						{
								cout<<"Content-Type:text/html\n\n";
								printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Pack data to json failed!");	
						}
				}
				else
				{
						cout<<"Content-Type:text/html\n\n";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Query db failed!");	

				}
		}
		return 0;
}

