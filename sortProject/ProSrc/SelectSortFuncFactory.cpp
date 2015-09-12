#include "SelectSortFuncFactory.h"
#include "SelectSortFunc.h"

SelectSortFuncFactory::~SelectSortFuncFactory()
{
}

SortFuncAbstra* SelectSortFuncFactory::createSortFuncObj()
{
	this->pSortFuncObj = new SelectSortFunc();
	return this->pSortFuncObj;	
}
