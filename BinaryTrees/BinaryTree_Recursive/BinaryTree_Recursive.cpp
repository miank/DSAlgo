// BinaryTree_Recursive.cpp : 
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

class Tree
{
	node *root;
public:
	Tree()
	{
		root = nullptr;
	}
	int IsEmpty()
	{
		return(root == NULL);
	}
	void preorder(node *root)
	{
		if (root == nullptr)
			return;
		cout << root->data << endl;
		preorder(root->left);
		preorder(root->right);
	}

	void inorder(node *root)
	{
		if (root == nullptr)
			return;
		inorder(root->left);
		cout << root->data << endl;
		inorder(root->right);
	}

	void postorder(node *root)
	{
		if (root == nullptr)
			return;
		postorder(root->left);
		postorder(root->right);
		cout << root->data << endl;
	}

	void insert(int item)
	{
		node *newNode = new node;
		node *parent = nullptr;
		newNode->data = item;
		newNode->left = nullptr;
		newNode->right = nullptr;

		if (IsEmpty())
		{
			root = newNode;
		}
		else
		{
			node *temp = nullptr;
			temp = root;
			while (temp != nullptr)
			{
				parent = temp;
				if (item > temp->data)
					temp = temp->right;
				else
					temp = temp->left;
			}
			if (item < parent->data)
				parent->left = newNode;
			else
				parent->right = newNode;
		}
	}

	void inorderTraversal()
	{
		inorder(root);
	}

	void postorderTraversal()
	{
		postorder(root);
	}

	void preorderTraversal()
	{
		preorder(root);
	}
};
int main()
{
	Tree obj;
	obj.insert(52);
	obj.insert(25);
	obj.insert(50);
	obj.insert(15);
	obj.insert(40);
	obj.insert(45);
	obj.insert(20);
	cout << "Inorder Traversal " << endl;
	obj.inorderTraversal();
	cout << "Postorder Traversal " << endl;
	obj.postorderTraversal();
	cout << "Preorder Traversal " << endl;
	obj.preorderTraversal();
	return 0;
}


