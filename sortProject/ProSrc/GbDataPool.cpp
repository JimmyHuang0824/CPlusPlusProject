#include "GbDataPool.h"

GbDataPool::GbDataPool()
			:vecUnorderedData(vector<int>(VEC_SIZE))
			 , vecOrderedData(vector<int>(VEC_SIZE))
{
}

GbDataPool::~GbDataPool()
{
}

const vector<int>& GbDataPool::getGbVecUnorderedData() const
{
	return this->vecUnorderedData;
}

bool GbDataPool::setGbVecUnorderedData(const vector<int> &vecInput)
{
	return this->setVecData(vecInput , this->vecUnorderedData);
}

const vector<int>& GbDataPool::getGbVecOrderedData() const
{
	return this->vecOrderedData;
}

bool GbDataPool::setGbVecOrderedData(const vector<int> &vecInput)
{
	return this->setVecData(vecInput , this->vecOrderedData);	
}

void GbDataPool::displayUnorderedData()
{
	this->displayData(this->vecUnorderedData);	
}

void GbDataPool::displayOrderedData()
{
	this->displayData(this->vecOrderedData);
}

void GbDataPool::displayData(const vector<int> &vecInput)
{
	for (int i = 0 ; i < VEC_SIZE; ++i)
	{
		cout<<vecInput[i]<<",";
		if ((i + 1) % 5 == 0)
		{
			cout<<endl;
		}
	}

}

bool GbDataPool::setVecData(const vector<int> &vecInput
							, vector<int> &vecOutput)
{
	bool bRet = false;
	if (0 == vecInput.size())
	{
		return bRet;
	}
	vecOutput = vecInput;
	bRet = true;
	return bRet;
}
