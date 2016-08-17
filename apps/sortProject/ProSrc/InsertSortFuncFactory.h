#ifndef _INSERTSORTFUNCFACTORY_H
#define _INSERTSORTFUNCFACTORY_H

#include "SortFuncAbstra.h"
#include "FuncAbstraFactory.h"

class InsertSortFuncFactory : public FuncAbstraFactory
{
	public:
		virtual SortFuncAbstra* createSortFuncObj();
		virtual ~InsertSortFuncFactory(){}
};

#endif
