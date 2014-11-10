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

int main() {

	vector<int> inputSrc = {3, 2, 4};

	Solution_Two_Sum s;
	vector<int> retVec = s.twoSum(inputSrc, 6);

	for (unsigned int i = 0; i < retVec.size(); i++)
	{
		cout << retVec[i] << " " << endl;
	}


	int A[] = {1,2,3};
	int B[] = {4,5,6};
	Solution_MedianSortedArrays s2;
	double retval = s2.findMedianSortedArrays(A, 3, B, 3);

	cout << retval << endl;

	return 0;
}
