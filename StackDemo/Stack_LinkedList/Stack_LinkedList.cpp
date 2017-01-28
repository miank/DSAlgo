// Stack_LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *link;
}*top = nullptr;

class Stack
{
public:
	void Push(int item);
	int Pop();
	void Display();
	int Peek();
	int IsEmpty();
};

void Stack::Push(int item)
{
	node *temp = new node;
	temp->data = item;
	temp->link = top;
	top = temp;
}

int Stack::Pop()
{
	node *temp;
	int item;
	if (IsEmpty())
	{
		cout << "Stack Underflow " << endl;
		exit(1);
	}
	temp = top;
	item = temp->data;
	top = top->link;
	free(temp);
	return item;
}

void Stack::Display()
{
	node *ptr;
	ptr = top;
	if (IsEmpty())
	{
		cout << "Stack is empty " << endl;
		return;
	}
	cout << "Stack elements are " << endl;
	while (ptr != nullptr)
	{
		cout << ptr->data;
		ptr = ptr->link;
	}
}

int Stack::Peek()
{
	if (IsEmpty())
	{
		cout << "Stack Underflow " << endl;
		exit(1);
	}
	return top->data;
}

int Stack::IsEmpty()
{
	if (top == nullptr)
		return 1;
	else
		return 0;
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

