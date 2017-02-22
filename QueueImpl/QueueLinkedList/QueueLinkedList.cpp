// QueueLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int info;
	node *link;
}*front = nullptr, *rear = nullptr;

int IsEmpty()
{
	if (front == nullptr)
		return 1;
	else
		return 0;
}

int peek()
{
	if (IsEmpty())
	{
		cout << "Queue Undeflow " << endl;
		exit(1);
	}
	return front->info;
}

void display()
{
	node *temp;
	temp = front;
	if (IsEmpty())
	{
		cout << "Queue is empty " << endl;
		return;
	}
	cout << "Queue Elements are " << endl;
	while (temp != nullptr)
	{
		cout << temp->info << endl;
		temp = temp->link;
	}
}

void push(int ele)
{
	struct node *temp = new node;
	if (temp == nullptr)
	{
		cout << "Memory not available " << endl;
		return;
	}
	temp->info = ele;
	temp->link = nullptr;

	if (front == nullptr)
		front = temp;
	else
		rear->link = temp;
	rear = temp;
}

int pop()
{
	if (IsEmpty())
	{
		cout << "Queue Underflow " << endl;
		exit(1);
	}
	node *temp;
	temp = front;
	int item = temp->info;
	front = front->link;
	free(temp);
	return item;
}

int main()
{
		int choice(0), ele;
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
				push(ele);
				break;
			case 2: ele = pop();
				cout << "Popped element is " << ele << endl;
				break;
			case 3: cout << "Item at the top is " << peek() << endl;
				break;
			case 4: display();
				break;
			case 5: exit(1);
			}
		}
		return 0;
}

