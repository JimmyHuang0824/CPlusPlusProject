#ifndef _HEAPSORTFUNCFACTORY_H
#define _HEAPSORTFUNCFACTORY_H

#include "SortFuncAbstra.h"
#include "FuncAbstraFactory.h"

class HeapSortFuncFactory : public FuncAbstraFactory
{
	public:
		virtual SortFuncAbstra* createSortFuncObj();
		virtual ~HeapSortFuncFactory(){}
};

#endif
