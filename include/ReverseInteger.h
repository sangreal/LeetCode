/*
 * ReverseInteger.h
 *
 *  Created on: Nov 16, 2014
 *      Author: martyn
 */

#ifndef REVERSEINTEGER_H_
#define REVERSEINTEGER_H_

#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

class Solution_ReverseInteger {
public:

	int checkOverflowMultiply(signed int sa, signed int sb)
	{
		if (sa > 0 && sb > 0)
		{
			if (sa > INT_MAX/sb)
			{
				cout << "The multiply of : " << sa << "*" << sb << "overflow." << endl;
				return 0;
			}
			else
			{
				return sa * sb;
			}
		}
		else if (sa < 0 && sb > 0)
		{
			if (sa < INT_MIN/sb)
			{
				cout << "The multiply of : " << sa << "*" << sb << "overflow." << endl;
				return 0;
			}
			else
			{
				return sa * sb;
			}
		}
		else
		{
			cout << "unhandled scenario " << endl;
			return 0;
		}
	}

	int checkOverflowAdd(signed int sa, signed int sb)
	{
		if (sa > 0 && sb > 0)
		{
		if (sa > INT_MAX - sb)
		{
			return 0;
		}
		else
			return sa + sb;
		}
		else if (sa < 0 && sb < 0)
		{
			if (sa < INT_MIN - sb)
			{
				return 0;
			}
			else
			{
				return sa + sb;
			}
		}
	}


	bool singleInteger(int x)
	{
		if ((x < 10 && x >0) || (x > -10 && x < 0))
			return true;
		else
			 return false;
	}

//2147483412
    int reverse(int x) {
	int divnum = 10, multinum = 1;

	int retVal = 0;

	bool reserveZero = false;

		stack<int> stack;

		if (x == 0)
			return 0;

		if (singleInteger(x))
			return x;

		while (x%divnum || x/divnum)
		{
			int posnum = x%divnum;

			if (posnum && posnum%divnum)
			{
				stack.push(posnum/ (divnum/10));
				reserveZero = true;
			}

			if (posnum == x)
			{

				break;
			}
			else if (x%divnum == 0)
			{
				if (singleInteger(x))
				{
					stack.push(x);
					break;
				}
				else if (reserveZero)
				{
					stack.push(0);
				}
			}
			else
			{
				x -= posnum;
			}

			if (checkOverflowMultiply(divnum, 10))
			{
				divnum*=10;
			}
			else
			{
				int tmpnum = x/divnum;
				stack.push(tmpnum);
				break;
			}

		}

		while (!stack.empty())
		{
			int num = stack.top();
			if (num != 0)
			{
			  if (checkOverflowMultiply(num, multinum))
			  {
				  if (checkOverflowAdd(retVal, num*multinum))
					  retVal += num*multinum;
				  else
					  return 0;
			  }
			  else
			  {
				return 0;
			  }
			}
			multinum *= 10;
			stack.pop();
		}

		return retVal;
    }
};


#endif /* REVERSEINTEGER_H_ */
