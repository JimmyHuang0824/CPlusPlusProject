#ifndef _SELECTSORTFUNCFACTORY_H
#define _SELECTSORTFUNCFACTORY_H

#include "SortFuncAbstra.h"
#include "FuncAbstraFactory.h"

class SelectSortFuncFactory : public FuncAbstraFactory
{
	public:
		virtual SortFuncAbstra* createSortFuncObj();
		virtual ~SelectSortFuncFactory();
};
#endif

