// SearchAndInsert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int key;
	node *left, *right;
};

node * newNode(int data)
{
	node *temp = new node;
	temp->key = data;
	temp->left = temp->right = nullptr;
	return temp;
}

void inorder(node *root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout << root->key << endl;
		inorder(root->right);
	}
}

node * insert(node *temp, int key)
{
	if (temp == nullptr)
		return newNode(key);

	if (key < temp->key)
		temp->left = insert(temp->left, key);
	if (key > temp->key)
		temp->right = insert(temp->right, key);
	return temp;
}

int main()
{
	node * root = nullptr;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// inorder 
	inorder(root);
    return 0;
}

