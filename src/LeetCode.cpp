//============================================================================
// Name        : LeetCode.cpp
// Author      : Martyn Ye
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <vector>

using namespace std;

#include "../include/TwoSum.h"
#include "../include/FindMedianSortedArrays.h"
#include "../include/LongestSubString.h"

#include "../include/AddNumbers.h"

#include "../include/ReverseInteger.h"

int main() {

	vector<int> inputSrc = {3, 2, 4};

	Solution_Two_Sum s;
	vector<int> retVec = s.twoSum(inputSrc, 6);

	for (unsigned int i = 0; i < retVec.size(); i++)
	{
		cout << retVec[i] << " " << endl;
	}


	int A[] = {2};
	int B[] = {1,3,4};
	Solution_MedianSortedArrays s2;
	double retval = s2.findMedianSortedArrays(A, 1, B, 3);

	cout << retval << endl;


	string inputStr = "xnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxz";
	Solution_LongestSubString s_substr;
	int len = s_substr.lengthOfLongestSubstring(inputStr);

	cout << "the len is : " << len << endl;

	Solution_Two_Sum s_twosum;

//	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output: 7 -> 0 -> 8

	ListNode * l1 = new ListNode(0);

	Solution_ReverseInteger s_reverse;
	int ret_val = s_reverse.reverse(1563847412);

	cout << "reverse integer return value is : " << ret_val << endl;

	return 0;
}
