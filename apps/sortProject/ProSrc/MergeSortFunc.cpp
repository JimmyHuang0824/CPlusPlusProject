#include "MergeSortFunc.h"

MergeSortFunc::MergeSortFunc()
			  :SortFuncAbstra()
{
}

MergeSortFunc::~MergeSortFunc()
{
}

bool MergeSortFunc::sortFunc(vector<int> &vecInput)
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
		this->mSort(vecInput);		
		bRet = true;
		return bRet;
	}
}

void MergeSortFunc::printSortFuncID()
{
	cout<<"This is Merge Sort Proc...."<<endl;
}


bool MergeSortFunc::mSort(vector<int> &vecInput)
{
	bool bRet = false;
	if (vecInput.empty()) return bRet;

	vector<int> vecTemp(vecInput.size());
	int i = 1;
	while (i < (int)vecInput.size())
	{
		this->merge(vecInput , vecTemp , i);
		i <<= 1;
	}

	bRet = true;
	return bRet;
}


void MergeSortFunc::merge(vector<int> &vecInput , vector<int> &vecOutput 
							, int nMid)
{
	int i = 0;
	while (i <= (int)vecInput.size() - (nMid << 1))
	{
		this->mergeSort(vecInput , vecOutput , i 
						, i + nMid - 1 , i + (nMid << 1) - 1);
		i += (nMid << 1);
	}

	if (i < (int)vecInput.size() - nMid + 1)
	{
		this->mergeSort(vecInput , vecOutput , i
						, i + nMid - 1 , (int)vecInput.size() - 1);
	}
	else
	{
		for (int j = i; j < (int)vecInput.size(); ++j)
		{
			vecOutput[j] = vecInput[j];
		}
	}

	for (i = 0; i < (int)vecInput.size(); ++i)
	{
		vecInput[i] = vecOutput[i];
	}
}

void MergeSortFunc::mergeSort(vector<int> &vecInput , vector<int> &vecOutput
								, int nLow , int nMid , int nHigh)
{
	int nLowIndex = nLow;
	int nHighIndex = nMid + 1;
	int nOutputIndex = nLow;

	for (;nLowIndex <= nMid && nHighIndex <= nHigh;++nOutputIndex)
	{
		if (vecInput[nLowIndex] < vecInput[nHighIndex])
		{
			vecOutput[nOutputIndex] = vecInput[nLowIndex++];
		}
		else
		{
			vecOutput[nOutputIndex] = vecInput[nHighIndex++];
		}
	}

	if (nLowIndex <= nMid)
	{
		for (int nTemp = 0; nTemp <= nMid - nLowIndex; ++nTemp)
		{
			vecOutput[nOutputIndex + nTemp] = vecInput[nLowIndex + nTemp];
		}
	}
	else
	{
		for (int nTemp = 0; nTemp <= nHigh - nHighIndex; ++nTemp)
		{
			vecOutput[nOutputIndex + nTemp] = vecInput[nHighIndex + nTemp];
		}
	}
}
