#include "QuickSortFuncFactory.h"
#include "QuickSortFunc.h"

SortFuncAbstra* QuickSortFuncFactory::createSortFuncObj()
{
	this->pSortFuncObj = new QuickSortFunc();
	return this->pSortFuncObj;	
}
