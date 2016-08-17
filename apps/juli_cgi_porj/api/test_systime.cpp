#include <iostream>
#include <string>
#include "string_deal_utils.h"

using namespace std;

int main()
{
		string strTime;
		StringDealUtils stringDealUtilsObj;
		strTime = stringDealUtilsObj.getSystimeString();
		cout<<strTime<<endl;
	return 0;	
}
