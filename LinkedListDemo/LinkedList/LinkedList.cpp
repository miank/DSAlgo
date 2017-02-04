// LinkedList.cpp : All linkedlist operations
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
	void DeleteNode();
	void LengthOfList();
	void DeleteNodeAtEnd();
	void ReverseList();
};

void LinkedList::ReverseList()
{
	node *current = nullptr, *next = nullptr, *prev = nullptr;
	current = start;
	while (current != nullptr)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	start = prev;
}

void LinkedList::DeleteNodeAtEnd()
{
	if (start == nullptr)
	{
		cout << "List is empty " << endl;
		return;
	}
	node *temp = start;
	node *prev;
	while (temp->link != nullptr)
	{
		prev = temp; // Keeping the back of previous node
		temp = temp->link;
	}
	delete temp;
	prev->link = nullptr;
}

void LinkedList::LengthOfList()
{
	int count = 0;
	node *temp = NULL;
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
			temp = temp->link;
			count++;
		}
		cout << count << endl;

	}
}

void LinkedList::DeleteNode()
{
	node *temp = nullptr;
	int value;
	cout << "Enter the value to be deleted " << endl;
	cin >> value;

	if (start == nullptr)
	{
		cout << "List is empty " << endl;
		return;
	}
	if (start->data == value)
	{
		temp = start->link;
		cout << temp->data << " deleted from the list " << endl;
		free(temp);
		start->link = nullptr;
	}
	node *p = start;
	while (p->link != nullptr)
	{
		if (p->link->data == value)
		{
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return;
		}
		p = p->link;
	}
}

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
		return;
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
		return;
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
		cout << "5. Delete a node based on value" << endl;
		cout << "6. Delete a node at end" << endl;
		cout << "7. Reverse a linked list" << endl;
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
		case 5:objList.DeleteNode();
			break;
		case 6:objList.DeleteNodeAtEnd();
			break;
		case 7:objList.ReverseList();
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

