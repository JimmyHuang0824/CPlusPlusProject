#include "MergeSortFuncFactory.h"
#include "MergeSortFunc.h"

SortFuncAbstra* MergeSortFuncFactory::createSortFuncObj()
{
	this->pSortFuncObj = new MergeSortFunc();
	return this->pSortFuncObj;	
}
