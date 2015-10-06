#include "SortFuncAbstra.h"

SortFuncAbstra::SortFuncAbstra()
{
	
}

SortFuncAbstra::~SortFuncAbstra()
{

}

void SortFuncAbstra::swapTwoNum(int &nNum1 , int &nNum2)
{
	nNum1 ^= nNum2;
	nNum2 ^= nNum1;
	nNum1 ^= nNum2;
}

