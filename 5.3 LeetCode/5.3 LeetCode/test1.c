#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode tn;

bool _isUnivalTree(tn* root, int x)
{
	if (root == NULL)
		return true;

	if (root->val != x)
		return false;

	return _isUnivalTree(root->left, x) && _isUnivalTree(root->right, x);
}


bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL)
		return true;

	int val = root->val;
	return _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);
}


int main()
{

	return 0;
}