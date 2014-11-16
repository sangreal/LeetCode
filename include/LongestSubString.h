/*
 * LongestSubString.h
 *
 *  Created on: Nov 12, 2014
 *      Author: martyn
 */

#ifndef LONGESTSUBSTRING_H_
#define LONGESTSUBSTRING_H_

#include <string>
#include <unordered_map>

using namespace std;

class Solution_LongestSubString {
public:
    int lengthOfLongestSubstring(string s) {

    	if (s.length() == 0)
    	{
    		return 0;
    	}

    	if (s.length() == 1)
    	{
    		return 1;
    	}

    	int maxlen = 0;

    	std::unordered_map<char, int> numset;


    	numset.insert(std::pair<char, int>(s[0], 0));

    	for (unsigned int i = 0, j = 1; j < s.length(); )
    	{


    			if (numset.find(s[j]) != numset.end())
    			{
    	    		int tmplen = j-i;
    				if (tmplen > maxlen)
    				{
    					maxlen = tmplen;
    				}

    				if (tmplen > 9)
    				{
    					cout << "the len big than 12" << i << endl;
    				}

    				i = numset.find(s[j])->second + 1;

    				unordered_map<char, int>::iterator it = numset.find(s[j]);


    				numset.erase(it, numset.end());

    				for (auto x : numset)
    				{
    					 std::cout << x.first << ": " << x.second << std::endl;
    				}

    			}
    			else
    			{
    				numset.insert(std::pair<char, int>(s[j],j));
    				j++;
    			}

    	}

    	return maxlen;

    }
};



#endif /* LONGESTSUBSTRING_H_ */
