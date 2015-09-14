#include "GbDataPool.h"
#include "SortFuncAbstra.h"
#include "RandomVectorNumCreator.h"
#include <iostream>
#include <vector>
#include "FuncAbstraFactory.h"
#include "BubbleSortFuncFactory.h"
#include "SelectSortFuncFactory.h"
#include "InsertSortFuncFactory.h"
#include "HeapSortFuncFactory.h"

using namespace std;

int main()
{
	GbDataPool &gbDataPoolObj = GbDataPool::getGbDataPool();
	vector<int> vecTest = gbDataPoolObj.getGbVecUnorderedData();
	RandomVectorNumCreator &randomNumCreator = RandomVectorNumCreator::getRandomVectorNumCreatorObj();
	if (randomNumCreator.createRandomNum(vecTest) == true)
	{
		gbDataPoolObj.setGbVecUnorderedData(vecTest);
		//FuncAbstraFactory *pSortFactory = new BubbleSortFuncFactory();
		//FuncAbstraFactory *pSortFactory = new SelectSortFuncFactory();
		//FuncAbstraFactory *pSortFactory = new InsertSortFuncFactory();
		FuncAbstraFactory *pSortFactory = new HeapSortFuncFactory();
		SortFuncAbstra *pSortFuncObj = pSortFactory->createSortFuncObj();
		if (true == pSortFuncObj->sortFunc(vecTest))
		{
			pSortFuncObj->printSortFuncID();

			gbDataPoolObj.setGbVecOrderedData(vecTest);
			cout<<"Unordered Data List:"<<endl<<endl;
			gbDataPoolObj.displayUnorderedData();

			cout<<endl<<"Ordered Data List:"<<endl<<endl;
			gbDataPoolObj.displayOrderedData();
		}

		delete pSortFuncObj;
	}

	cout<<endl;
	return 0;
}

