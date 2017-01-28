// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MAX 10
using namespace std;

class Stack
{
	int top = -1;
	int arr[MAX];
public:
	void Push(int item);
	int Pop();
	int IsEmpty();
	int IsFull();
	void Display();
	int Peek();
};

int Stack::IsEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Stack::IsFull()
{
	if (top == MAX - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Stack::Push(int item)
{
	if (IsFull())
	{
		cout << "Stack is full " << endl;
		return;
	}
	else
	{
		++top;
		arr[top] = item;
		cout << item << " Inserted successfully at " << arr[top] << endl;
	}
}

int Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is empty " << endl;
		return 0;
	}
	else
	{
		int item = arr[top];
		top--;
		return item;
	}
}

void Stack::Display()
{
	for (int i = top; i >= 0; i--)
	{
		cout << "Stack elements are " << arr[i] << endl;
	}
}

int Stack::Peek()
{
	if (IsEmpty())
	{
		cout << "Stack is empty " << endl;
		return 0;
	}
	int item = arr[top];
	return item;
}

int main()
{
	Stack stk;
	int choice, ele;
	while (1)
	{
		cout << "1. Push " << endl;
		cout << "2. Pop " << endl;
		cout << "3. Peek " << endl;
		cout << "4. Display " << endl;
		cout << "5. Quit " << endl;
		cout << "Enter your choice " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:	cout << "Enter the item to be inserted " << endl;
				cin >> ele;
				stk.Push(ele);
				break;
		case 2: ele = stk.Pop();
				cout << "Popped element is " << ele << endl;
				break;
		case 3: cout << "Item at the top is " << stk.Peek();
				break;
		case 4: stk.Display();
				break;
		case 5: exit(1);
		}
	}
    return 0;
}

