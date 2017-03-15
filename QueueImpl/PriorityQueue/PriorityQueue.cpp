// PriorityQueue.cpp 
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct pNode
{
	int data;
	int priority;
	pNode *link;
}*front = nullptr;

int IsEmpty()
{
	if (front == nullptr)
		return 1;
	else
		return 0;
}
void insert(int data, int priority)
{
	pNode *temp;
	pNode *p;
	temp = new pNode;
	if (temp == nullptr)
	{
		cout << "Memory not allocated " << endl;
		return;
	}
	temp->data = data;
	temp->priority = priority;
	temp->link = nullptr;

	if (IsEmpty() || data < front->priority)
	{
		temp->link = front;
		front = temp;
	}
	else
	{
		p = front;
		while ((p->link != nullptr) && (p->link->priority = priority))
		{
			p = p->link;
		}
		temp->link = p->link;
		p->link = temp;
	}
}

int del()
{
	pNode *temp;
	int item;
	if (IsEmpty())
	{
		cout << "Queue underflow " << endl;
		exit(1);
	}
	else
	{
		temp = front;
		item = temp->data;
		front = front->link;
		free(temp);
	}
	return item;
}

void display()
{
	pNode *ptr(nullptr);
	ptr = front;
	if (IsEmpty())
		cout << "Queue is empty " << endl;
	else
	{
		cout << "Queue is " << endl;
		while (ptr != nullptr)
		{
			cout << "Data " << ptr->data << " " << endl;
			cout << "Priority " << ptr->priority << " ";
			ptr = ptr->link;
		}
	}
}



int main()
{
	int choice(0), ele, priority(0);
	while (1)
	{
		cout << "1. Insert " << endl;
		cout << "2. Delete " << endl;
		cout << "3. Display " << endl;
		cout << "4. Quit " << endl;
		cout << "Enter your choice " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:	cout << "Enter the item to be inserted " << endl;
			cin >> ele;
			cout << "Enter its priority " << endl;
			cin >> priority;
			insert(ele, priority);
			break;
		case 2: cout << "Deleted item is " << del() << endl;
			break;
		case 3: display();
			break;
		case 4: exit(1);
		}
	}
    return 0;
}

