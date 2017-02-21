// PreOrder_Iterative.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

struct node * newNode(int data)
{
	node *newNode = new node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

void preOrder(node * root)
{
	if (root == nullptr)
		return;

	stack<node *> nodeStk;
	nodeStk.push(root);

	while (!nodeStk.empty())
	{
		node *temp = nodeStk.top();
		cout << temp->data << " ";
		nodeStk.pop();

		if (temp->right)
			nodeStk.push(temp->right);
		if (temp->left)
			nodeStk.push(temp->left);
		
	}
}

int main()
{
	node *root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);
	preOrder(root);
    return 0;
}

