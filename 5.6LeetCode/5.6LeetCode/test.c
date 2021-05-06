#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode tn;
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q != NULL)
		return false;

	if (q == NULL && p != NULL)
		return false;

	if (q == NULL && p == NULL)
		return true;

	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;


	tn* temp = root->left;
	root->left = root->right;
	root->right = temp;


	invertTree(root->left);
	invertTree(root->right);

	return root;
}

int TreeSize(tn* root)
{
	return (root == NULL) ? 0 : (1 + TreeSize(root->left) + TreeSize(root->right));
}

void _preorderTraversal(tn* root, int** ret, int* i)
{
	if (root == NULL)
		return;

	(*ret)[*i] = root->val;
	(*i)++;
	_preorderTraversal(root->left, ret, i);
	_preorderTraversal(root->right, ret, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	int sz = TreeSize(root);
	*returnSize = sz;
	int* ret = (int*)malloc(sizeof(int)* sz);
	int i = 0;
	_preorderTraversal(root, &ret, &i);

	return ret;
}

void _inorderTraversal(struct TreeNode* root, int* a, int* pi)
{
	if (root == NULL)
		return;
	_inorderTraversal(root->left, a, pi);
	a[(*pi)] = root->val;
	(*pi)++;
	_inorderTraversal(root->right, a, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int)* size);
	*returnSize = size;
	int i = 0;
	_inorderTraversal(root, a, &i);
	return a;
}

bool isSame(tn* p, tn* q)
{
	if (p == NULL && q == NULL)
		return true;

	if (p == NULL || q == NULL)
		return false;

	if (p->val != q->val)
		return false;

	return isSame(p->left, q->left) && isSame(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (root == NULL && subRoot != NULL)
		return false;

	if (root != NULL && subRoot == NULL)
		return false;

	if (isSame(root, subRoot))
		return true;

	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{

	return 0;
}