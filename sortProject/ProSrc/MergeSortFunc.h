#ifndef _MERGESORTFUNC_H
#define _MERGESORTFUNC_H


#include "SortFuncAbstra.h"

class MergeSortFunc : public SortFuncAbstra
{
	public://func
		MergeSortFunc();
		virtual ~MergeSortFunc();
		virtual bool sortFunc(vector<int> &vecInput);
		virtual void printSortFuncID();
};

#endif
