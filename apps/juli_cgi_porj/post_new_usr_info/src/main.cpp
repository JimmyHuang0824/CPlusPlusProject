#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cpp_mysql_connect.h"
#include "json_read_write.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "print_error_log.h"
#include "string_deal_utils.h"

using namespace std;
using namespace boost;  
using namespace boost::gregorian;  
using namespace boost::posix_time;

int main()
{
		char *pRequestMethod = NULL;
		setvbuf(stdin, NULL, _IONBF, 0);
		pRequestMethod = getenv("REQUEST_METHOD");

		string strErrorLogPath = "post_usr_info_error.log";
		PrintErrorLog printErrorLogObj;
		if (strcmp(pRequestMethod , "POST") == 0)
		{
				char *pPostStrLen = getenv("CONTENT_LENGTH");	
				if (!pPostStrLen)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Regis Error";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "None post data!");
						return -1;
				}

				int nStrLen = atoi(pPostStrLen);

				char *pPostStr = new char[nStrLen + 1];
				memset(pPostStr , 0x00 , nStrLen  + 1);
				fgets(pPostStr , nStrLen + 1 , stdin);

				//解析接收到的json数据
				vector< vector<string> > vecParseJsonStringList;
				JsonReadWrite jrwObj;
				vector<string> vecKeys(4);
				vecKeys[0] = "new_usr_name";
				vecKeys[1] = "md5_code";
				vecKeys[2] = "sex";
				vecKeys[3] = "conn_method";

				bool bParseRet = jrwObj.parseJsonStringToStringList(string(pPostStr) 
								, vecKeys , vecParseJsonStringList);
				if (!bParseRet
								|| vecParseJsonStringList.size() != 1) 
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Regis Error";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Post json data invalid!");
						return -2;
				}

				//连接数据库
				CppMysqlConn cppMysqlConnObj;
				bool bConnectRet = cppMysqlConnObj.connToDataBase(string("localhost") , string("usr")
								, string("123") , string("juli"));
				if (!bConnectRet) 
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Regis Error";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Mysql connect error!");
						return -3;
				}

				//验证用户信息表是否有新用户名
				string strCheckUsrNameQuery = string("select id from j_tabhome_usr_info where usr_name = '")
						+ vecParseJsonStringList[0][0] + string("'");
				vector< vector<string> > vecCheckRet;
				int nCheckRet = cppMysqlConnObj.queryStringFromDataBase(strCheckUsrNameQuery , vecCheckRet);
				if (0 == nCheckRet
								&& vecCheckRet.size() != 0)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"Usr Exist";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "New Usr Name Duplicate!");
						return -4;
				}

				//获取系统格式化时间
				ptime tp = microsec_clock::local_time();
				time_facet *pTimeFacetObj = new time_facet("%Y-%m-%d&&%H:%M:%S");
				std::stringstream ss;
				ss.imbue(std::locale(ss.getloc() , pTimeFacetObj));
				ss<<tp;
				string strSysTime;
				ss>>strSysTime;
				delete pTimeFacetObj;
				//切割时间字符串
				StringDealUtils stringDealUtilsObj;
				vector<string> vecSplit = stringDealUtilsObj.splitString(strSysTime , "&&");
				strSysTime = vecSplit[0] + string(" ") + vecSplit[1];

				//生成用户性别
				string strSex = "1";
				if (vecParseJsonStringList[0][2] 
								== string("female"))
				{
						strSex = "0";
				}

				//将用户信息插入数据库
				string strUsrInfoQuery = string("insert into j_tabhome_usr_info values(") + string("NULL,'")
						+ vecParseJsonStringList[0][0] + string("','") + vecParseJsonStringList[0][1]
						+ string("',") + strSex
						+ string(",'") + vecParseJsonStringList[0][3]
						+ string("',0,'") + strSysTime + string("',NULL)");

				bool bInsertRet = cppMysqlConnObj.insertDataToDataBase(strUsrInfoQuery);
				if (!bInsertRet)
				{ 
						cout<<"Content-Type:text/html\n\n";
						cout<<"Regis Error";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "insert usr data error!");
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , strUsrInfoQuery);
						return -5;
				}

				cout<<"Content-Type:text/html\n\n";
				cout<<"success";
				delete []pPostStr;
		}
		return 0;
}
