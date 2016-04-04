// IdenticalList.cpp : Check wether two list are identical or node based on number of nodes 
// and coreesponding data in the nodes
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct NodeList1
{
	int data;
	NodeList1 *next;
}*start1 = NULL;

struct NodeList2
{
	int data;
	NodeList2 *next;
}*start2 = NULL;

class LinkedList
{
	int small = 0, big = 0;
public:
	NodeList1 * CreateList1(int ele);
	NodeList2 * CreateList2(int value);
	void DisplayList();
	void InsertNodeList1();
	void InsertNodeList2();
	void IdenticalList();
};
int main()
{
	int choice;
	LinkedList objList;
	int ele = 0;
	while (1)
	{
		cout << "Linked List Operations " << endl;
		cout << "1. Insert Node at List1" << endl;
		cout << "2. Insert Node at List2" << endl;
		cout << "3. Display List" << endl;
		cout << "4. List are identical or not" << endl;
		cout << "5. Exit " << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:objList.InsertNodeList1();
			break;
		case 2:objList.InsertNodeList2();
			break;
		case 3:objList.DisplayList();
			break;
		case 4:objList.IdenticalList();
			break;
		case 5: exit(0);
			break;
		default:
			cout << "Error in choice" << endl;
			break;
		}
	}
	return 0;
}

NodeList1 * LinkedList::CreateList1(int ele)
{
	NodeList1 *newNode = new NodeList1;
	NodeList1 * temp = start1;
	if (start1 == NULL)
	{
		start1 = newNode;
		newNode->data = ele;
		newNode->next = NULL;
	}
	else
	{
		newNode->data = ele;
		newNode->next = NULL;
	}
	return newNode;
	return nullptr;
}


NodeList2 * LinkedList::CreateList2(int ele)
{
	NodeList2 *newNode = new NodeList2;
	NodeList2 * temp = start2;
	if (start2 == NULL)
	{
		start2 = newNode;
		newNode->data = ele;
		newNode->next = NULL;
	}
	else
	{
		newNode->data = ele;
		newNode->next = NULL;
	}
	return newNode;
	return nullptr;
}

void LinkedList::DisplayList()
{
	NodeList1 *temp1 = start1;
	while (temp1 != NULL)
	{
		cout << temp1->data << endl;
		temp1 = temp1->next;
	}
	NodeList2 *temp2 = start2;
	while (temp2 != NULL)
	{
		cout << temp2->data << endl;
		temp2 = temp2->next;
	}
}

void LinkedList::IdenticalList()
{
	NodeList1 *temp1 = start1;
	NodeList2 *temp2 = start2;
	int count1 = 0;
	int count2 = 0;
	while (temp1 != NULL && temp2 != NULL)
	{
		count1++;
		count2++;
		if ((temp1->data == temp2->data) && (count1 == count2))
		{
			cout << "List is identical" << endl;
		}
		else
		{
			cout << "List is not identical " << endl;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}

void LinkedList::InsertNodeList1()
{
	int value;
	NodeList1 *temp = nullptr;
	NodeList1 *nodeEnd = new NodeList1;
	cout << "Enter the value to be inserted at end of the list" << endl;
	cin >> value;
	nodeEnd = CreateList1(value);
	temp = start1;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = nodeEnd;
	nodeEnd->next = NULL;
	cout << "The element inserted at last successfully" << endl;
}

void LinkedList::InsertNodeList2()
{
	int value;
	NodeList2 *temp = nullptr;
	NodeList2 *nodeEnd = new NodeList2;
	cout << "Enter the value to be inserted at end of the list" << endl;
	cin >> value;
	nodeEnd = CreateList2(value);
	temp = start2;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = nodeEnd;
	nodeEnd->next = NULL;
	cout << "The element inserted at last successfully" << endl;
}
