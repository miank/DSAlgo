// BalancedBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>  
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int leftHeight = isBalanced(root->left);
		if (leftHeight == -1)
			return -1;
		int rightHeight = isBalanced(root->right);
		if (rightHeight == -1)
			return -1;
		if (abs(leftHeight - rightHeight) > 1)
			return -1;
		return (1 + max(leftHeight, rightHeight));
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
	struct TreeNode *root = newNode(3);
	root->left = newNode(1);
	root->right = newNode(5);
	root->left->left = newNode(0);
	root->left->right = newNode(2);
	root->right->left = newNode(4);
	root->right->left->right = newNode(6);
	cout << obj.isBalanced(root) << endl;
    return 0;
}

