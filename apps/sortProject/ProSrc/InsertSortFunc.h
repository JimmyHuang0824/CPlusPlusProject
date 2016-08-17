#ifndef _INSERTSORTFUNC_H
#define _INSERTSORTFUNC_H


#include "SortFuncAbstra.h"

class InsertSortFunc : public SortFuncAbstra
{
	public://func
		InsertSortFunc();
		virtual ~InsertSortFunc();
		virtual bool sortFunc(vector<int> &vecInput);
		virtual void printSortFuncID();

};

#endif
