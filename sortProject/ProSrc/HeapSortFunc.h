#ifndef _HEAPSORTFUNC_H
#define _HEAPSORTFUNC_H


#include "SortFuncAbstra.h"

class HeapSortFunc : public SortFuncAbstra
{
	public://func
		HeapSortFunc();
		virtual ~HeapSortFunc();
		virtual bool sortFunc(vector<int> &vecInput);

	private:
		void heapAdjust(vector<int> &vecInput , int nLow , int nHigh);
		virtual void printSortFuncID();
};

#endif
