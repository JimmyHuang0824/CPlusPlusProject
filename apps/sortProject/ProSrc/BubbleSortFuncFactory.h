#ifndef _BUBBLESORTFUNCFACTORY_H
#define _BUBBLESORTFUNCFACTORY_H

#include "SortFuncAbstra.h"
#include "FuncAbstraFactory.h"

class BubbleSortFuncFactory : public FuncAbstraFactory
{
	public:
		virtual SortFuncAbstra* createSortFuncObj();
		virtual ~BubbleSortFuncFactory(){}
};

#endif
