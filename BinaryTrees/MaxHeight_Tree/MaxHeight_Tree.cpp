// MaxHeight_Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

int maxHeight(node * root)
{
	if (root == nullptr)
		return 0;
	else
	{
		int leftTree = maxHeight(root->left);
		int rightTree = maxHeight(root->right);

		if (leftTree > rightTree)
			return (leftTree + 1);
		else
			return (rightTree + 1);
	}
}

node *newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << maxHeight(root) << endl;
    return 0;
}

