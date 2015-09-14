#include "HeapSortFuncFactory.h"
#include "HeapSortFunc.h"

SortFuncAbstra* HeapSortFuncFactory::createSortFuncObj()
{
	this->pSortFuncObj = new HeapSortFunc();
	return this->pSortFuncObj;	
}
