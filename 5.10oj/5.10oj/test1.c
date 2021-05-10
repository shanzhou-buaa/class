#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
};

typedef struct TreeNode tn;

bool _isBalanced(tn* root, int* ph)
{
	if (root == NULL)
	{
		*ph = 0;
		return true;
	}

	//后序遍历
	int leftHeight = 0;
	if (_isBalanced(root->left, &leftHeight) == false)
		return false;

	int rightHeight = 0;
	if (_isBalanced(root->right, &rightHeight) == false)
		return false;

	//更新高度
	*ph = (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);

	return abs(leftHeight - rightHeight) < 2;
}

bool isBalanced(struct TreeNode* root)
{
	int height = 0;
	return _isBalanced(root, &height);
}

int main()
{

	return 0;
}