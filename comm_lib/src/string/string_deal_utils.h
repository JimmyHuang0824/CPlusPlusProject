#ifndef _STRING_DEAL_UTILS_H
#define _STRING_DEAL_UTILS_H
#include <string>
#include <vector>

using namespace std;

class StringDealUtils
{
		public:
				StringDealUtils();
				~StringDealUtils();
				vector<string> splitString(const string& strInput
											 , const string& strPattern);
				string convFromHttpStringToUtf8(const string& strInputHttpString);
				string getSystimeString();
};
#endif
