#ifndef _BUBBLESORTFUNC_H
#define _BUBBLESORTFUNC_H

#include "SortFuncAbstra.h"

class BubbleSortFunc : public SortFuncAbstra
{
	public://func
		BubbleSortFunc();
		virtual ~BubbleSortFunc();
		virtual bool sortFunc(vector<int> &vecInput);

};

#endif
