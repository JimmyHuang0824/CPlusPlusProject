#ifndef _SORTFUNCABSTRA_H
#define _SORTFUNCABSTRA_H

#include <vector>
#include <iostream>

using namespace std;

class SortFuncAbstra
{
	public://func
		SortFuncAbstra();
		~SortFuncAbstra();
		virtual bool sortFunc(vector<int> &vecInput) = 0;
		virtual void printSortFuncID() = 0;

	protected://func
		void swapTwoNum(int &nNum1 , int &nNum2);
};
#endif 
 
