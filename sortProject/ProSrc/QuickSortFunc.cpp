#include "QuickSortFunc.h"

QuickSortFunc::QuickSortFunc()
{
}

QuickSortFunc::~QuickSortFunc()
{
}

bool QuickSortFunc::sortFunc(vector<int> &vecInput)
{
	bool bRet = false;
	if (vecInput.empty()) return bRet;
	else if (vecInput.size() == 1)
	{
		bRet = true;
		return bRet;
	}
	else
	{
		this->qSort(vecInput , 0 , (int)vecInput.size() - 1);	
	}
}

void QuickSortFunc::printSortFuncID()
{
	cout<<"This is Quick Sort Proc...."<<endl;
}

void QuickSortFunc::qSort(vector<int> &vecInput , int nLow , int nHigh)
{
	//尾递归优化
	while (nLow < nHigh)
	{
		int nPivotIndex = this->getPartition(vecInput , nLow , nHigh);
		this->qSort(vecInput , nLow , nPivotIndex - 1);
		nLow = nPivotIndex + 1;
	}
}		


int QuickSortFunc::getPartition(vector<int> &vecInput , int nLow , int nHigh)
{
	//三数取中法
	int nMid = nLow + (nHigh - nLow) >> 1;
	if (vecInput[nLow] > vecInput[nHigh])
	{
		swapTwoNum(vecInput[nLow] , vecInput[nHigh]);
	}

	if (vecInput[nMid] > vecInput[nHigh])
	{
		swapTwoNum(vecInput[nMid] , vecInput[nHigh]);
	}

	if (vecInput[nLow] < vecInput[nMid])
	{
		swapTwoNum(vecInput[nLow] , vecInput[nMid]);
	}
	int nPivotKey = vecInput[nLow];

	while (nLow < nHigh)
	{
		while (nLow < nHigh && vecInput[nHigh] >= nPivotKey)
		{
			--nHigh;
		}
		vecInput[nLow] = vecInput[nHigh];

		while (nLow < nHigh && vecInput[nLow] <= nPivotKey)
		{
			++nLow;
		}
		vecInput[nHigh] = vecInput[nLow];
	}

	vecInput[nLow] = nPivotKey;
	return nLow;
}	
