// DoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
}*head;

class DoubleLinkedList
{
	int value = 0;
public:
	DoubleLinkedList()
	{
		Node *head = NULL;
	}
	Node *CreateNode();
	void InsertNode();
	void InsertAtFront();
	void InsertAtEnd();
	void AddAfter();
	void AddBefore();
	void Delete();
	void Print();
	void Reverse();
};

int main()
{
	int choice;
	DoubleLinkedList objList;
	int ele = 0;
	while (1)
	{
		cout << "Linked List Operations " << endl;
		cout << "1. Insert a node" << endl;
		cout << "2. Insert a node at front" << endl;
		cout << "3. Insert a node at end" << endl;
		cout << "4. Print the List" << endl;
		cout << "5. Reverse the List" << endl;
		cout << "6. Exit " << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:objList.InsertAtFront();
			break;
		case 2: objList.InsertAtEnd();
			break;
		case 3: objList.Print();
			break;
		case 4: objList.Reverse();
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

Node * DoubleLinkedList::CreateNode()
{
	cout << "Enter the element for the node" << endl;
	cin >> value;
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void DoubleLinkedList::InsertNode()
{
	Node* nodeAdd = CreateNode();
	if (head == NULL)
	{
		head = nodeAdd;
	}
	else  // If list is not empty then add the node in the front of te list.
	{
		InsertAtFront();
	}
}

void DoubleLinkedList::InsertAtFront()
{
	struct Node *nodeFront = CreateNode();
	if (head == NULL)
	{
		head = nodeFront;
		return;
	}
	head->prev = nodeFront;
	nodeFront->next = head;
	head = nodeFront;
}

void DoubleLinkedList::InsertAtEnd()
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	struct Node *nodeLast = CreateNode();
	nodeLast->next = NULL;
	nodeLast->prev = temp->next;	
}

void DoubleLinkedList::Print()
{
	struct Node *temp = head;
	cout << "Forward :" << endl;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void DoubleLinkedList::Reverse()
{
	struct Node *temp = head;
	if (temp == NULL)  // empty list, exist
		return;
	// Going to last Node
	while (temp->next != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void DoubleLinkedList::AddAfter()
{

}