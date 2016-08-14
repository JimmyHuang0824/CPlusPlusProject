#include "string_deal_utils.h"
#include <stdio.h>
#include <string.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost;  
using namespace boost::gregorian;  
using namespace boost::posix_time;

StringDealUtils::StringDealUtils()
{}

StringDealUtils::~StringDealUtils()
{}


vector<string> StringDealUtils::splitString(const string& strInput
				, const string& strPattern)
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


string StringDealUtils::convFromHttpStringToUtf8(const string& strInputHttpString)
{
		string strRet("");
		if (strInputHttpString.length() == 0) return strRet;

		vector<string> vecSplitStr = this->splitString(strInputHttpString , "%");
		char *pCharRet = new char[vecSplitStr.size() + 1];
		memset(pCharRet , 0x00 , (int)vecSplitStr.size() + 1);

		char *pCpy = pCharRet;
		for (int i = 0; i < (int)vecSplitStr.size(); ++i) 
		{
				string strTemp = string("0x") + vecSplitStr[i];
				int nStrTemp = 0;
				sscanf(strTemp.c_str() , "%x" , &nStrTemp);
				*pCharRet++ = nStrTemp;
		}

		strRet = string(pCpy);
		delete []pCpy;
		return strRet;
}

string StringDealUtils::getSystimeString()
{
		//string strSysTime;

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
		vector<string> vecSplit = this->splitString(strSysTime , "&&");
		if (vecSplit.size() == 2)
		{
			strSysTime = vecSplit[0] + string(" ") + vecSplit[1];
		}
		else
		{
			strSysTime = "";
		}
		return strSysTime;
}
