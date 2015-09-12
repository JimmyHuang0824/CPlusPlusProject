#ifndef _RANDOMVECTORNUMCREATOR_H
#define _RANDOMVECTORNUMCREATOR_H

#include <vector>
#include <time.h>

class RandomVectorNumCreator
{
	public://func
		static RandomVectorNumCreator& getRandomVectorNumCreatorObj()
		{
			static RandomVectorNumCreator randomVectorNumCreatorObj;
			return randomVectorNumCreatorObj;
		}
		bool createRandomNum(std::vector<int> &vecInputNum);
		~RandomVectorNumCreator();

	private://func
		RandomVectorNumCreator();
		RandomVectorNumCreator(const RandomVectorNumCreator&);
		RandomVectorNumCreator& operator= (const RandomVectorNumCreator&);
};
#endif
 
