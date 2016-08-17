#include "print_error_log.h"
#include <stdio.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "string_deal_utils.h"

using namespace boost;  
using namespace boost::gregorian;  
using namespace boost::posix_time;

PrintErrorLog::PrintErrorLog()
{}

PrintErrorLog::~PrintErrorLog()
{}

bool PrintErrorLog::printErrorMsgToFile(const string& strFileName
				, const string& strErrorMsg)
{
		bool bRet = false;
		if (strFileName.empty()
						|| strErrorMsg.empty()) return bRet;

		FILE *pLogFile = fopen(strFileName.c_str() , "a");
		if (!pLogFile)
		{
				return bRet;
		}

		//获取系统格式化时间
		ptime tp = microsec_clock::local_time();
		time_facet *pTimeFacetObj = new time_facet("%Y-%m-%d&&%H:%M:%S");
		std::stringstream ss;
		ss.imbue(std::locale(ss.getloc() , pTimeFacetObj));
		ss<<tp;
		string strSysTime;
		ss>>strSysTime;
		//切割时间字符串
		StringDealUtils stringDealUtilsObj;
		vector<string> vecSplit = stringDealUtilsObj.splitString(strSysTime , "&&");
		strSysTime = vecSplit[0] + string(" ") + vecSplit[1];

		//生成最终的错误信息
		string strOutputErrorMsg = string("Time:") + strSysTime + string("   ") 
				+ string("ErrorMsg:") + strErrorMsg;

		fprintf(pLogFile , "%s\n" , strOutputErrorMsg.c_str());
		fclose(pLogFile);

		bRet = true;
		return bRet;
}
