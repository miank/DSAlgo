// TwoStackInArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class stack
{
	int top1, top2, n;
	int *arr;
	int size;
public:
	stack(int n)
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	void push1(int ele)
	{
		if (top1 < top2 - 1)
		{
			++top1;
			arr[top1] = ele;
		}
		else
		{
			cout << "Stack overflow " << endl;
			exit(1);
		}
	}

	void push2(int ele)
	{
		if (top1 < top2 - 1)
		{
			top2--;
			arr[top2] = ele;
		}
		else
		{
			cout << "Stack overflow " << endl;
			exit(1);
		}
	}

	int pop1()
	{
		if (top1 > 0)
		{
			int ele = arr[top1];
			top1--;
			return ele;
		}
		else
		{
			cout << "Stack underflow " << endl;
			exit(1);
		}
	}
	int pop2()
	{
		if (top2 < size)
		{
			int ele = arr[top2];
			top2++;
			return ele;
		}
		else
		{
			cout << "Stack underflow " << endl;
			exit(1);
		}
	}
};

int main()
{
	stack s1(6);
	s1.push1(5);
	s1.push2(10);
	s1.push2(15);
	s1.push1(11);
	s1.push2(7);
	cout << "Popped element from stack1 is " << s1.pop1() << endl;
	s1.push2(40);
	cout << "\n Popped element from stack2 is " << s1.pop2() << endl;

    return 0;
}

