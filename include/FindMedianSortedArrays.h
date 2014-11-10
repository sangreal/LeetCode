/*
 * FindMedianSortedArrays.h
 *
 *  Created on: Nov 9, 2014
 *      Author: martyn
 */

#ifndef FINDMEDIANSORTEDARRAYS_H_
#define FINDMEDIANSORTEDARRAYS_H_


class Solution_MedianSortedArrays {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {

    	bool bhasMedian = false;

		int aLen = 0, bLen = 0, totalnum = 1;

		int prevNum = 0;

		if ((m+n)%2 != 0)
			bhasMedian = true;

		if (m == 0 && n == 0)
		{
			return 0;
		}
		else if (m == 0)
		{
			if (n == 1)
			{
				return B[0];
			}

			if (bhasMedian == true)
			{
				return B[n/2];
			}
			else
			{
				return ((double)B[n/2-1]+ B[n/2])/2;
			}

		}
		else if (n == 0)
		{
			if (m == 1)
			{
				return A[0];
			}

			if (bhasMedian == true)
			{
				return A[m/2];
			}
			else
			{
				return ((double)A[m/2-1]+ A[m/2])/2;
			}
		}

		for (; aLen < m && bLen < n; totalnum++)
		{
			if (bhasMedian)
			{
				if (A[aLen] <= B[bLen])
				{
					if (totalnum == ((m+n)/2+1))
					{
						return (double)A[aLen];
					}
					aLen++;
				}
				else
				{
					if (totalnum == ((m+n)/2+1))
					{
						return (double)B[bLen];;
					}
					bLen++;
				}
			}
			else
			{
				if (A[aLen] <= B[bLen])
				{
					if (totalnum == (m+n)/2)
					{
						prevNum = A[aLen++];
					}
					else if (totalnum == ((m+n)/2+1))
					{
						return ((double)prevNum+A[aLen])/2;
					}
					else
					{
						aLen++;
					}
				}
				else
				{
					if (totalnum == (m+n)/2)
					{
						prevNum = B[bLen++];
					}
					else if (totalnum == ((m+n)/2+1))
					{
						return ((double)prevNum+B[bLen])/2;
					}
					else
					{
						bLen++;
					}
				}
			}
		}

		if (aLen < m)
		{
			if (bhasMedian)
			{
				int index = (m+n)/2+1 - n;
				return (double)(A[index-1]);
			}
			else
			{
				int index = (m+n)/2 - n;
				if (index == 0)
				{
					return (double)(prevNum+A[index])/2;
				}
				else
					return ((double)A[index-1]+A[index])/2;
			}
		}
		else
		{
			if (bhasMedian)
			{
				int index = (m+n)/2+1 - m;
				return (double)(B[index-1]);
			}
			else
			{
				int index = (m+n)/2 - m;

				if (index == 0)
				{
					return (double)(prevNum+B[index])/2;
				}
				else
					return ((double)B[index-1]+B[index])/2;
			}
		}

    }
};


#endif /* FINDMEDIANSORTEDARRAYS_H_ */
