// BinaryTreePath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};

class Solution {
public:
	void printPath(TreeNode *root)
	{
		int path[1000];
		pathRecursively(root, path, 0);
	}

	void pathRecursively(TreeNode *root, int arr[], int len) 
	{
		if (root == nullptr)
			return;

		arr[len] = root->val;
		len++;

		if (root->left == nullptr && root->right == nullptr)
		{
			printArray(arr, len);
		}
		else
		{
			pathRecursively(root->left, arr, len);
			pathRecursively(root->right, arr, len);
		}
	}

	void printArray(int arr[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

TreeNode *newNode(int data)
{
	TreeNode *temp = new TreeNode;
	temp->val = data;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

int main()
{
	Solution obj;
	TreeNode *root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);
	obj.printPath(root);
	return 0;
}


