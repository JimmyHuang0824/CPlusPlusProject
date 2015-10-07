#include "SelectSortFunc.h"

SelectSortFunc::SelectSortFunc()
				:SortFuncAbstra()
{
}

SelectSortFunc::~SelectSortFunc()
{
}

bool SelectSortFunc::sortFunc(vector<int> &vecInput)
{
	bool bRet = false;
	if (vecInput.empty()) return bRet;

	if (vecInput.size() == 1)
	{
		bRet = true;
		return bRet;
	}
	else
	{
		int nTotalSize = vecInput.size();
		for (int i = 0; i < nTotalSize; ++i)
		{
			int nMinIndex = i;
			for (int j = i; j < nTotalSize;++j)
			{
				if (vecInput[j] < vecInput[nMinIndex])
				{
					nMinIndex = j;
				}
			}

			if (nMinIndex != i)
			{
				swapTwoNum(vecInput[i] , vecInput[nMinIndex]);
			}
		}
	}
	
	bRet = true;
	return bRet;	
}

void SelectSortFunc::printSortFuncID()
{
	cout<<"This is Select Sort Proc...."<<endl;
}
