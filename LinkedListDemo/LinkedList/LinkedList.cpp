// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *link;
}*start;

class LinkedList
{
public:
	node *CreateNode(int);
	void InsertFront();
	void InsertEnd();
	void DisplayList();
	//void LengthOfList();
	//void ReverseList();
};

node *LinkedList::CreateNode(int ele)
{
	node *temp = new node;

	if (temp == nullptr)
	{
		cout << "Memory not allocated " << endl;
		return 0;
	}
	else
	{
		temp->data = ele;
		temp->link = nullptr;
		return temp;
	}
	
}

void LinkedList::InsertFront()
{
	int value(0);
	cout << "Enter the value to insert in the begining " << endl;
	cin >> value;
	node *newNode = CreateNode(value);
	if (start == nullptr)
	{
		start = newNode;
		start->link = nullptr;
	}
	else
	{
		node *temp = start;
		start = newNode;
		start->link = temp;
	}
	cout << newNode->data << " successfully inserted at the begining " << endl;
}

void LinkedList::InsertEnd()
{
	int value(0);
	cout << "Enter the value to insert in the end " << endl;
	cin >> value;
	node *newNode = CreateNode(value);
	if (start == nullptr)
	{
		start = newNode;
		start->link = nullptr;
	}
	node *temp = start;
	while (temp->link != nullptr)
		temp = temp->link;
	temp->link = newNode;
	newNode->link = nullptr;
	cout << newNode->data << " successfully inserted at the end " << endl;
}
void LinkedList::DisplayList()
{
	if (start == nullptr)
	{
		cout << "Linked List is empty ";
		return;
	}
	node *temp = start;
	while (temp != nullptr)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
}

int main()
{
	int choice;
	LinkedList objList;
	int ele = 0;
	while (1)
	{
		cout << "Linked List Operations " << endl;
		cout << "1. Insert a node at front" << endl;
		cout << "2. Insert a node at end" << endl;
		cout << "3. Display List" << endl;
		cout << "4. Length of Linked List" << endl;
		cout << "8. Exit " << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;


		switch (choice)
		{
		case 1:objList.InsertFront();
			break;
		case 2: objList.InsertEnd();
			break;
		case 3: objList.DisplayList();
			break;
		/*case 4: objList.LengthOfList();
			break;
		case 5:objList.ReverseList();
			break;*/
		case 8: exit(0);
			break;
		default:
			cout << "Error in choice" << endl;
			break;
		}
	}
	return 0;
}

