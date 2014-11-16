/*
 * AddNumbers.h
 *
 *  Created on: Nov 15, 2014
 *      Author: martyn
 */

#ifndef ADDNUMBERS_H_
#define ADDNUMBERS_H_

#include <stdio.h>
#include <iostream>

using namespace std;

//Definition for singly-linked list.
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution_AddNumbers {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    	if (!l1)
    	{
    		return l2;
    	}
    	else if (!l2)
    	{
    		return l1;
    	}

    	bool hasExceed = false;

    	ListNode * head = new ListNode(0);

    	ListNode * newList = head;

    	while (l1 && l2)
    	{
    		int sum = 0;

    		if (hasExceed)
    		{
    			sum = l1->val + l2->val + 1;
    		}
    		else
    		{
    			sum = l1->val + l2->val;
    		}

    		if (sum > 9)
    		{
    			newList->val = sum - 10;
    			hasExceed = true;
    		}
    		else
    		{
    			newList->val = sum;
    			hasExceed = false;
    		}

    		if (l1->next || l2->next)
			{
				ListNode * nextnode = new ListNode(0);
				newList->next = nextnode;
				newList = nextnode;
			}

    		l1 = l1->next;
    		l2 = l2->next;
    	}

    	while (l1)
    	{
    		int sum = 0;

    		if (hasExceed)
    		{
    			sum = l1->val + 1;
    		}
    		else
    		{
    			sum = l1->val;
    		}

    		if (sum > 9)
    		{
    			newList->val = sum-10;
    			hasExceed = true;
    		}
    		else
    		{
    			newList->val = sum;
    			hasExceed = false;
    		}

    		if (l1->next)
			{
				ListNode * nextnode = new ListNode(0);
				newList->next = nextnode;
				newList = nextnode;
			}

    		l1 = l1->next;
    	}

    	while (l2)
		{
			int sum = 0;

			if (hasExceed)
			{
				sum = l2->val + 1;
			}
			else
			{
				sum = l2->val;
			}

			if (sum > 9)
			{
				newList->val = sum-10;
				hasExceed = true;
			}
			else
			{
				newList->val = sum;
				hasExceed = false;
			}

			if (l2->next)
			{
				ListNode * nextnode = new ListNode(0);
				newList->next = nextnode;
				newList = nextnode;
			}

			l2 = l2->next;
		}

    	if (hasExceed)
    	{
    		ListNode * nextnode = new ListNode(1);
			newList->next = nextnode;
    	}

    	return head;
    }
};


#endif /* ADDNUMBERS_H_ */
