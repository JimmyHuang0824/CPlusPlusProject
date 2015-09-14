#include "BubbleSortFunc.h"

BubbleSortFunc::BubbleSortFunc()
					:SortFuncAbstra()
{
}

BubbleSortFunc::~BubbleSortFunc()
{
}


bool BubbleSortFunc::sortFunc(vector<int> &vecInput)
{
	bool bRet = false;
	
	if (0 == vecInput.size())
	{
		return bRet;
	}
	else if (1 == vecInput.size())
	{
		bRet = true;
		return bRet;
	}
	else
	{
		int nTotalSize = vecInput.size();
		bool bChangeFlag = true;
		for (int i = 1; i < nTotalSize && bChangeFlag; ++i)
		{
			bChangeFlag = false;
			for (int j = nTotalSize - 1
					; j >= i; --j)
			{
				if (vecInput[j] < vecInput[j - 1])
				{
					bChangeFlag = true;
					swapTwoNum(vecInput[j - 1] , vecInput[j]);
				}
			}
		}
	}

	bRet = true;
	return bRet;
}

void BubbleSortFunc::printSortFuncID()
{
	cout<<"This is Bubble Sort Proc..."<<endl;	
}
