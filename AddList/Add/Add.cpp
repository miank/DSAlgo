// Add.cpp : Addling two numbers represnted by linked list
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node1
{
	int data;
	node1 *next;
}*start1;

struct node2
{
	int data;
	node2 *next;
}*start2;

struct node3
{
	int data;
	node3 *next;
}*start3;

class LinkedList
{
public:
	void InsertAtEndList1()
	{
		int value;
		cout << "Enter the value at List1 ";
		cin >> value;
		node1 *newNode = new node1;
		if (start1 == nullptr)
		{
			newNode->data = value;
			start1 = newNode;
			start1->next = nullptr;
			return;
		}
		node1 *temp = start1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		newNode->data = value;
		temp->next = newNode;
		newNode->next = nullptr;
		cout << newNode->data << " inserted successfully in list1 " << endl;
	}

	void InsertAtEndList2()
	{
		int value;
		cout << "Enter the value at List1 ";
		cin >> value;
		node2 *newNode = new node2;
		if (start2 == nullptr)
		{
			newNode->data = value;
			start2 = newNode;
			start2->next = nullptr;
			return;
		}
		node2 *temp = start2;
		newNode->data = value;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = nullptr;

		cout << newNode->data << " inserted successfully in list2 " << endl;
	}

	void DisplayList1()
	{
		if (start1 == nullptr)
		{
			cout << "Linked List is empty ";
			return;
		}
		node1 *temp = start1;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		return;
	}

	void DisplayList2()
	{
		if (start2 == nullptr)
		{
			cout << "Linked List is empty ";
			return;
		}
		node2 *temp = start2;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		return;
	}

	void DisplayList()
	{
		if (start3 == nullptr)
		{
			cout << "Linked List is empty ";
			return;
		}
		node3 *temp = start3;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		return;
	}

	void AddTwoList()
	{
		node1 *temp1 = start1;
		node2 *temp2 = start2;
		int carry(0), total(0), result(0);

		while (temp1 != nullptr || temp2 != nullptr)
		{
			result = temp1->data + temp2->data + carry;
			total = result % 10;
			carry = (result >= 10) ? 1 : 0;
			TotalList(total);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

	void TotalList(int value)
	{
		node3 *newNode = new node3;
		if (start3 == nullptr)
		{
			newNode->data = value;
			start3 = newNode;
			start3->next = nullptr;
			return;
		}
		node3 *temp = start3;
		newNode->data = value;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = nullptr;

		//cout << newNode->data << " inserted successfully in list3 " << endl;
	}
};

int main()
{
	int choice;
	LinkedList objList;
	int ele = 0;
	while (1)
	{
		cout << "Linked List Operations " << endl;
		cout << "1. Insert a node at end of List1" << endl;
		cout << "2. Insert a node at end of List2" << endl;
		cout << "3. Display List 1" << endl;
		cout << "4. Display List 2" << endl;
		cout << "5. Add two list " << endl;
		cout << "6. Add two list " << endl;
		cout << "7. Exit " << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:objList.InsertAtEndList1();
			break;
		case 2: objList.InsertAtEndList2();
			break;
		case 3: objList.DisplayList1();
			break;
		case 4: objList.DisplayList2();
			break;
		case 5: objList.AddTwoList();
			break;
		case 6: objList.DisplayList();
			break;
		case 7: exit(0);
			break;
		default:
			cout << "Error in choice" << endl;
			break;
		}
	}
	return 0;
}

