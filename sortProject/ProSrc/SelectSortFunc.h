#ifndef _SELECTSORTFUNC_H
#define _SELECTSORTFUNC_H

#include "SortFuncAbstra.h"

class SelectSortFunc : public SortFuncAbstra
{
	public://func
		SelectSortFunc();
		virtual ~SelectSortFunc();
		virtual bool sortFunc(vector<int> &vecInput);
		
};
#endif


