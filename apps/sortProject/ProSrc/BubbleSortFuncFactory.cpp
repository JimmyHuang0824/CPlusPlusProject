#include "BubbleSortFuncFactory.h"
#include "BubbleSortFunc.h"

SortFuncAbstra* BubbleSortFuncFactory::createSortFuncObj()
{
	this->pSortFuncObj = new BubbleSortFunc();
	return this->pSortFuncObj;
}

