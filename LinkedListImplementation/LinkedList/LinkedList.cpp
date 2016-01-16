// LinkedList.cpp : LinkedList operations implementation using C++
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct List
{
	int data;
	List *next;
}*start; // ??

class LinkedList
{
public:
	LinkedList()
	{
		start = NULL;
	}
	List *CreateNode(int);
	void InsertFront();
	void InsertEnd();
	void DisplayList();
	void LengthOfList();
	void ReverseList();
};

void LinkedList::LengthOfList()
{
	int count = 0;
	List *temp = NULL;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	else
	{
		temp = start;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		cout << count << endl;

	}
}
List *LinkedList::CreateNode(int value) // ??
{
	List *myNode = new List;
	if (myNode == NULL)
	{
		cout << "Memory not allocated " << endl;
		return 0;
	}
	else
	{
		myNode->data = value;
		myNode->next = NULL;
		return myNode; // ??
	}
}

void LinkedList::InsertFront()
{
	int ele;
	List *temp;
	List *nodeInsert;
	cout << "Enter the element to insert" << endl;
	cin >> ele;
	nodeInsert = CreateNode(ele);
	if (start == NULL)
	{
		start = nodeInsert;
		start->next = NULL;
	}
	else
	{
		temp = start;
		start = nodeInsert;
		start->next = temp;
	}
}

void LinkedList::InsertEnd()
{
	int value;
	List *temp =nullptr;
	List *nodeEnd = new List;
	cout << "Enter the value to be inserted at end of the list" << endl;
	cin >> value;
	nodeEnd = CreateNode(value);
	temp = start;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = nodeEnd;
	nodeEnd->next = NULL;
	cout << "The element inserted at last successfully" << endl;
}

void LinkedList::DisplayList()
{
	List *temp;
	temp = start;

	if (temp == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
}

void LinkedList::ReverseList()
{
	List *current, *prev, *next;
	prev = NULL;
	current = start;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
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
		case 4: objList.LengthOfList();
			break;
		case 5:objList.ReverseList();
			break;
		case 8: exit(0);
			break;
		default:
			cout << "Error in choice" << endl;
			break;
		}
	}
    return 0;
}

