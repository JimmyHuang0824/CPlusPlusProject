#include "FuncAbstraFactory.h"

FuncAbstraFactory::FuncAbstraFactory()
				: pSortFuncObj(NULL)
{
}

FuncAbstraFactory::~FuncAbstraFactory()
{
	if (this->pSortFuncObj)
	{
		delete this->pSortFuncObj;
		this->pSortFuncObj = NULL;
	}
}
