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
		string strErrorFilePath = "get_usr_login_info_error.log";

		if (strcmp(pRequestMethod , "GET") == 0)
		{
				//cout<<string(pRequestMethod);
				char *pGetParam = getenv("QUERY_STRING");
				//切割字符串
				StringDealUtils stringDealUtilsObj;
				vector<string> vecSplitAll;
				vecSplitAll = stringDealUtilsObj.splitString(string(pGetParam) , string("&"));
				if ((int)vecSplitAll.size() != 2)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Get Param Error";
						printErrorLogObj.printErrorMsgToFile(strErrorFilePath , "Get Param Error");
				}
				//将用户名和密码分别切出
				vector<string> vecSplitUsrName = stringDealUtilsObj.splitString(vecSplitAll[0]
								, string("="));
				if (vecSplitUsrName.size() != 2)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Get Param Usr Name Error";
						printErrorLogObj.printErrorMsgToFile(strErrorFilePath , "Get Param Usr Name Error");

				}
				string strUtf8UsrName = stringDealUtilsObj.convFromHttpStringToUtf8(vecSplitUsrName[1]);

				vector<string> vecSplitCode = stringDealUtilsObj.splitString(vecSplitAll[1]
								, string("="));
				if (vecSplitCode.size() != 2)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Get Param Code Error";
						printErrorLogObj.printErrorMsgToFile(strErrorFilePath , "Get Param Code Error");

				}
				string strCode = vecSplitCode[1];

				//连接数据库
				CppMysqlConn cppMysqlConnObj;
				bool bConnectRet = cppMysqlConnObj.connToDataBase(string("localhost") , string("usr")
								, string("123") , string("juli"));
				if (!bConnectRet) return -1;

				//从数据库中拉取用户信息
				string strCheckQuery = string("select id , code , sex , connect_method from j_tabhome_usr_info where usr_name='")
						+ strUtf8UsrName + string("'");
				vector< vector<string> > vecCheckRet;
				int nCheckQueryRet = cppMysqlConnObj.queryStringFromDataBase(strCheckQuery , vecCheckRet);
				if (nCheckQueryRet != 0)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"query error!";
						printErrorLogObj.printErrorMsgToFile(strErrorFilePath , "Usr Name Not Exist");
						return -2;
				}

				if (nCheckQueryRet == 0
								&& vecCheckRet.size() == 0)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Usr Name Not Exist";
						printErrorLogObj.printErrorMsgToFile(strErrorFilePath , "usr name not exist");
						return -3;
				}

				//校验密码
				if (strCode != vecCheckRet[0][1])
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Usr Code Error";
						printErrorLogObj.printErrorMsgToFile(strErrorFilePath , "Usr Code Error");
						return -4;
				}

				////密码验证通过，向客户端发送用户信息以及cookie
				//将拉取的数据打包成json格式的数据
				vector<string> vecKeys;
				vecKeys.push_back("usr_name");
				vecKeys.push_back("usr_sex");
				vecKeys.push_back("usr_conn_method");

				vector< vector<string> > vecValues(1);
				vecValues[0].push_back(strUtf8UsrName);
				vecValues[0].push_back(vecCheckRet[0][2]);
				vecValues[0].push_back(vecCheckRet[0][3]);

				string strJsonOutput;
				JsonReadWrite jrwObj;
				bool bPackRet = jrwObj.packStringListToJsonString(vecValues , vecKeys , strJsonOutput);

				if (bPackRet)
				{
						//设置cookie
						cout<<"Set-Cookie:usr_name=" + strUtf8UsrName + string("\r\n");
						///发送回客户端
						cout<<"Content-Type:text/html\n\n";
						cout<<strJsonOutput;
				}
				else
				{
						printErrorLogObj.printErrorMsgToFile(strErrorFilePath , "Json pack error");
						return -5;
				}
				//cout<<"Content-Type:text/html\n\n";
				//cout<<"success";
		}
		return 0;
}
