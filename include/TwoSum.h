/*
 * TwoSum.h
 *
 *  Created on: Nov 8, 2014
 *      Author: martyn
 */

#ifndef TWOSUM_H_
#define TWOSUM_H_

#include <vector>
#include <unordered_map>

using namespace std;
class Solution_Two_Sum {
public:
        vector<int> twoSum(vector<int> &numbers, int target) {

    	std::unordered_multimap<int, int> srcMap(3);

    	for (unsigned int i = 0; i < numbers.size(); i++)
    	{
    		srcMap.insert(std::pair<int,int>(numbers[i], i+1));
    	}


    	vector<int> retVec;

    	bool isfirstSame = false;

        for(unsigned int i = 0; i < numbers.size(); i++)
        {
            int remainInt = target - numbers[i];

            unordered_map<int, int>::const_iterator it = srcMap.find(remainInt);

            if (it != srcMap.end())
            {
            	if (i+1 != (unsigned int)it->second)
            	{
            		retVec.push_back(i+1);
            		retVec.push_back(it->second);
            		return retVec;
            	}
            	else if (isfirstSame == false && srcMap.count(remainInt) >1)
            	{
            		retVec.push_back(i+1);
            		isfirstSame = true;
            	}
            	else if (isfirstSame == true)
            	{
            		retVec.push_back(i+1);
            		return retVec;
            	}


            }
        }

        return retVec;
    }
};


#endif /* TWOSUM_H_ */
