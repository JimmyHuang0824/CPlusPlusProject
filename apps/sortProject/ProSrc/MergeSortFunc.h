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

	private://func
		bool mSort(vector<int> &vecInput);
		void merge(vector<int> &vecInput , vector<int> &vecOutput , int nMid);
		void mergeSort(vector<int> &vecInput , vector<int> &vecOutput
						, int nLow , int nMid , int nHigh);
};

#endif
