#include "HeapSortFunc.h"

HeapSortFunc::HeapSortFunc()
				:SortFuncAbstra()
{
}

HeapSortFunc::~HeapSortFunc()
{
}

bool HeapSortFunc::sortFunc(vector<int> &vecInput)
{	
	bool bRet = false;
	if (vecInput.empty()) return bRet;
	if (vecInput.size() == 1) return (bRet = true);

	for (int nIndex = vecInput.size() / 2 - 1; nIndex >= 0; --nIndex)
	{
		this->heapAdjust(vecInput , nIndex , vecInput.size() - 1);
	}	

	for (int nIndex = vecInput.size() - 1; nIndex >= 1; --nIndex)
	{
		this->swapTwoNum(vecInput[nIndex] , vecInput[0]);
		this->heapAdjust(vecInput , 0 , nIndex - 1);
	}

	return (bRet = true);
}

void HeapSortFunc::heapAdjust(vector<int> &vecInput 
								, int nLow , int nHigh)
{
	int nTemp = vecInput[nLow];
	
	for (int nIndex = nLow << 1; nIndex <= nHigh; nIndex = nIndex << 1)
	{
		if (nIndex < nHigh 
			&& vecInput[nIndex] < vecInput[nIndex + 1])
		{
			++nIndex;
		}
		
		if (nTemp >= vecInput[nIndex])
		{
			break;
		}

		vecInput[nLow] = vecInput[nIndex];
		nLow = nIndex;
	}

	vecInput[nLow] = nTemp;
}

void HeapSortFunc::printSortFuncID()
{
	cout<<"This is Heap Sort Proc...."<<endl;
}
