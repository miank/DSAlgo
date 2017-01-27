// Traversal.cpp : 
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct node 
{
	int data;
	node *left;
	node *right;
};

class BST
{
	
public:
	node *root;
	BST() 
	{
		root = nullptr;
	}
	int isEmpty() 
	{ 
		return (root == nullptr); 
	}

	void insert(int item);
	void preorder(node *ptr);
	void inorder(node *ptr);
	void postorder(node *ptr);
	void inordertrav();
	void postordertrav();
	void preodertrav();
	int treeSize();
	int sizeOfTree(node *ptr);
};

void BST::inordertrav()
{
	inorder(root);
}

void BST::postordertrav()
{
	postorder(root);
}

void BST::preodertrav()
{
	preorder(root);
}

void BST::insert(int item) 
{
	node *p = new node;
	node *parent;
	p->data = item;
	p->left = nullptr;
	p->right = nullptr;
	parent = nullptr;

	if (isEmpty())
		root = p;
	else
	{
		node *ptr;
		ptr = root;
		while (ptr != nullptr) 
		{
			parent = ptr;
			if (item > ptr->data)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		if (item < parent->data)
			parent->left = p;
		else
			parent->right = p;
	}
}

void BST::preorder(node *ptr)
{
	if (ptr != nullptr)
	{
		cout << ptr->data << "\t ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BST::inorder(node *ptr)
{
	if (ptr != nullptr)
	{
		preorder(ptr->left);
		cout << ptr->data << "\t ";
		preorder(ptr->right);
	}
}

void BST::postorder(node *ptr)
{
	if (ptr != nullptr)
	{
		preorder(ptr->left);
		preorder(ptr->right);
		cout << ptr->data << "\t ";
	}
}

int BST::treeSize()
{
	return sizeOfTree(root);
}

int BST::sizeOfTree(node *ptr)
{
	if (root == nullptr)
		return 0;
	int leftSize = sizeOfTree(root->left);
	int rightSize = sizeOfTree(root->right);
	return (leftSize + 1 + rightSize);
}

int main()
{
	BST obj;
	obj.insert(10);
	obj.insert(15);
	obj.insert(3);
	obj.insert(5);
	obj.insert(6);
	obj.insert(30);
	obj.insert(2);
	obj.insert(9);
	obj.insert(8);

	cout << "Inorder Traversal " << endl;
	obj.inordertrav();
	cout << endl;
	cout << "Post Traversal " << endl;
	obj.postordertrav();
	cout << endl;
	cout << "Pre Traversal " << endl;
	obj.preodertrav();
	cout << endl;
	cout << "Size of Binary Tree is ";
	cout << obj.treeSize();
	
    return 0;
}


