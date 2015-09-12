#include "InsertSortFunc.h"

InsertSortFunc::InsertSortFunc()
{
}

InsertSortFunc::~InsertSortFunc()
{
}

bool InsertSortFunc::sortFunc(vector<int> &vecInput)
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
		for (int i = 1;i < nTotalSize; ++i)
		{
			int nTemp = vecInput[i];
			int j;
			for (j = i - 1; j >= 0 && nTemp < vecInput[j]; --j)
			{
				vecInput[j + 1] = vecInput[j];
			}
			vecInput[j + 1] = nTemp;
		}
	}

	bRet = true;
	return bRet;
}
