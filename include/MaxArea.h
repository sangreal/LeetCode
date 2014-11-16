/*
 * MaxArea.h
 *
 *  Created on: Nov 16, 2014
 *      Author: martyn
 */

#ifndef MAXAREA_H_
#define MAXAREA_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution_MaxArea {
public:
    int maxArea(vector<int> &height) {

    	int maxsum = 0;

    	vector<int>::iterator it = height.begin();

    	if (height.size() == 0)
    	{
    		return 0;
    	}

    	while ((it+1) != height.end())
    	{
    		int sum = (*it + *(it+1))/2;
    		if (sum > maxsum)
    			maxsum = sum;
    	}

    	return maxsum;
    }
};



#endif /* MAXAREA_H_ */
