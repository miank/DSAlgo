// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MAX 10
using namespace std;

class Queue
{
public:
	void push(int ele);
	int pop();
	int peek();
	void display();
	int empty();
	int full();
	int front = -1;
	int rear = -1;
	int queue[MAX];
};

void Queue::push(int ele)
{
	if (full())
	{
		cout << "Queue Overflow " << endl;
		return;
	}
	if (front == -1)
		front = 0;
	rear = rear + 1;
	queue[rear] = ele;
	cout << "Item successfully inserted " << endl;
}

int Queue::pop()
{
	if (empty())
		cout << "Queue Underflow " << endl;
	int item = queue[front];
	front++;
	cout << item << "removed successfully " << endl;
	return item;
}

int Queue::peek()
{
	int item = queue[front];
	return item;
}

void Queue::display()
{
	if (front > rear)
	{
		cout << "Queue is empty " << endl;
		return;
	}
	for (int i = front; i < rear; front++)
	{
		cout << queue[front] << endl;
	}
}

int Queue::empty()
{
	if (front == rear + 1)
		return 1;
	else
		return 0;
}

int Queue::full()
{
	if (rear == MAX)
		return 1;
	else
		return 0;
}

int main()
{
	Queue qu;
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
			qu.push(ele);
			break;
		case 2: ele = qu.pop();
			cout << "Popped element is " << ele << endl;
			break;
		case 3: cout << "Item at the top is " << qu.peek() << endl;
			break;
		case 4: qu.display();
			break;
		case 5: exit(1);
		}
	}
    return 0;
}

