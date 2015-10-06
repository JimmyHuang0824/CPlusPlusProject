#ifndef _MERGESORTFUNCFACTORY_H
#define _MERGESORTFUNCFACTORY_H

#include "SortFuncAbstra.h"
#include "FuncAbstraFactory.h"

class MergeSortFuncFactory : public FuncAbstraFactory
{
	public:
		virtual SortFuncAbstra* createSortFuncObj();
		virtual ~MergeSortFuncFactory(){}
};

#endif
