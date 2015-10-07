#ifndef _QUICKSORTFUNC_H
#define _QUICKSORTFUNC_H


#include "SortFuncAbstra.h"

class QuickSortFunc : public SortFuncAbstra
{
	public://func
		QuickSortFunc();
		virtual ~QuickSortFunc();
		virtual bool sortFunc(vector<int> &vecInput);
		virtual void printSortFuncID();
	
	private://func
		void qSort(vector<int> &vecInput , int nLow , int nHigh);		
		int getPartition(vector<int> &vecInput , int nLow , int nHigh);

};

#endif
