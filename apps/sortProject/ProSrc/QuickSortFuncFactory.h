#ifndef _QUICKSORTFUNCFACTORY_H
#define _QUICKSORTFUNCFACTORY_H

#include "SortFuncAbstra.h"
#include "FuncAbstraFactory.h"

class QuickSortFuncFactory : public FuncAbstraFactory
{
	public:
		virtual SortFuncAbstra* createSortFuncObj();
		virtual ~QuickSortFuncFactory(){}
};

#endif
