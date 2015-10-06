#ifndef _GBDATAPOOL_H
#define _GBDATAPOOL_H

#include <vector>
#include <iostream>
using namespace std;

#define VEC_SIZE 200

class GbDataPool
{
	public://func
		static GbDataPool& getGbDataPool()
		{
			static GbDataPool gbDataPoolObj;
			return gbDataPoolObj;
		}

		const vector<int>& getGbVecUnorderedData() const;
		bool setGbVecUnorderedData(const vector<int> &vecInput);

		const vector<int>& getGbVecOrderedData() const;
		bool setGbVecOrderedData(const vector<int> &vecInput);

		void displayUnorderedData();
		void displayOrderedData();
		~GbDataPool();

	private://func
		GbDataPool();
		GbDataPool(const GbDataPool&);
		GbDataPool& operator= (const GbDataPool&);
		void displayData(const vector<int> &vecInput);
		bool setVecData(const vector<int> &vecInput , vector<int> &vecOutput);

	private://var
		vector<int> vecUnorderedData;
		vector<int> vecOrderedData;


};

#endif
