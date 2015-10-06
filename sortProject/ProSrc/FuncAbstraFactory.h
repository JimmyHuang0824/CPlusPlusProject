#ifndef _FUNCABSTRAFACTORY_H
#define _FUNCABSTRAFACTORY_H

#include "SortFuncAbstra.h"
#include <stddef.h>

class FuncAbstraFactory
{
	public:
		FuncAbstraFactory();
		virtual SortFuncAbstra* createSortFuncObj() = 0;
		virtual ~FuncAbstraFactory();
	
	protected:
		SortFuncAbstra *pSortFuncObj;
};
#endif
