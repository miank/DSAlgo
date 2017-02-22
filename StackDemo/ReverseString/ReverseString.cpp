// ReverseString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MAX 100
using namespace std;

int top = -1;
char str[MAX];

void push(char item)
{
	if (top == MAX - 1)
	{
		cout << "Stack is full " << endl;
		return;
	}
	str[++top] = item;
}

char pop()
{
	if (top == -1)
	{
		cout << "Stack underflow " << endl;
		exit(1);
	}
	char ele = str[top];
	top--;
	return ele;
}

int main()
{
	cout << "Enter a string " << endl;
	cin >> str;

	// push all characters in the stack
	for (int i = 0; i < strlen(str); i++)
	{
		push(str[i]);
	}
	// Pop all characters from stack

	cout << "The reversed string is " << endl;
	for (int i = 0; i < strlen(str); i++)
	{
		cout << pop();
	}
	cout << endl;
	return 0;
}

