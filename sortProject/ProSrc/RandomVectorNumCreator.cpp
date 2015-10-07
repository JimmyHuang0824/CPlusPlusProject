#include "RandomVectorNumCreator.h"
#include <cstdlib>

RandomVectorNumCreator::RandomVectorNumCreator()
{
}

RandomVectorNumCreator::~RandomVectorNumCreator()
{
}

bool RandomVectorNumCreator::createRandomNum(std::vector<int> &vecInputNum)
{
	bool bRet = false;
	if (0 == vecInputNum.size())
	{
		return bRet;
	}

	srand((unsigned)time(NULL));
	for (int i = 0 ; i < vecInputNum.size(); ++i)
	{
		int nTemp = rand() % 10000;
		vecInputNum[i] = nTemp;
	}
	bRet = true;
	return bRet;
}	
