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

		string strErrorLogPath = "post_content_answer_error.log";
		PrintErrorLog printErrorLogObj;
		if (strcmp(pRequestMethod , "POST") == 0)
		{
				char *pPostStrLen = getenv("CONTENT_LENGTH");	
				if (!pPostStrLen)
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"<P>Post form error\n";
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
				vecKeys[0] = "content_id";
				vecKeys[1] = "from_usr";
				vecKeys[2] = "to_usr";
				vecKeys[3] = "msg_text";

				bool bParseRet = jrwObj.parseJsonStringToStringList(string(pPostStr) 
								, vecKeys , vecParseJsonStringList);

				if (!bParseRet
								|| vecParseJsonStringList.size() != 1) 
				{
						cout<<"Content-Type:text/html\n\n";
						cout<<"<P>Post form success!\n";
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
						cout<<"<P>Post form success!\n";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "Mysql connect error!");
						return -3;
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

				//将回答信息插入数据库
				string strAnswerQuery = string("insert into j_tabhome_msg values(") + string("NULL,'")
						+ vecParseJsonStringList[0][1] + string("','") + vecParseJsonStringList[0][2]
						+ string("',") + vecParseJsonStringList[0][0] + string(",'")
						+ strSysTime + string("','") + vecParseJsonStringList[0][3] + string("',NULL)");
				bool bInsertRet = cppMysqlConnObj.insertDataToDataBase(strAnswerQuery);
				if (!bInsertRet)
				{ 
						cout<<"Content-Type:text/html\n\n";
						cout<<"<P>Post form success!\n";
						printErrorLogObj.printErrorMsgToFile(strErrorLogPath , "insert preview data error!");
						return -5;
				}

				cout<<"Content-Type:text/html\n\n";
				cout<<"<html><title>post success!</title>\n</html>\n";
				delete []pPostStr;
		}
		return 0;
}
