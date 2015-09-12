#include "InsertSortFuncFactory.h"
#include "InsertSortFunc.h"


SortFuncAbstra* InsertSortFuncFactory::createSortFuncObj()
{
	
	this->pSortFuncObj = new InsertSortFunc();
	return this->pSortFuncObj;
}
