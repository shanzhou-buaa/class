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

int get_max(int a, int b)
{
	return (a) > (b) ? (a) : (b);
}
int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return 1 + get_max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{

	return 0;
}