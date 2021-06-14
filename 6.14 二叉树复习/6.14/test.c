#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
}tn;

tn* TreeNodeCreate(int x);
tn* TreeInsert(tn* root, int x);
tn* TreeSearch(tn* root, int x);

int main()
{
	int a[] = { 8, 4, 9, 2, 10, 5, 3, 7 };
	int n = sizeof(a) / sizeof(a[0]);
	int i = 0;
	tn* root = TreeNodeCreate(a[0]);
	for (i = 1; i < n; i++)
		TreeInsert(root, a[i]);
	
	tn* node1 = TreeSearch(root, 5);
	if (node1 != NULL)
		printf("%d\n", node1->val);
	else
		printf("找不到5\n");

	tn* node2 = TreeSearch(root, 10);
	if (node2 != NULL)
		printf("%d\n", node2->val);
	else
		printf("找不到10\n");

	tn* node3 = TreeSearch(root, 50);
	if (node3 != NULL)
		printf("%d\n", node3->val);
	else
		printf("找不到50\n");
	return 0;
}

tn* TreeNodeCreate(int x)
{
	tn* node = (tn*)malloc(sizeof(tn));
	node->left = NULL;
	node->right = NULL;
	node->val = x;

	return node;
}

tn* TreeInsert(tn* root, int x)
{
	if (root == NULL)
	{
		tn* newnode = TreeNodeCreate(x);
		return newnode;
	}
	if (root->val == x)
		return root;
	else if (root->val > x)
		root->left = TreeInsert(root->left, x);
	else
		root->right = TreeInsert(root->right, x);

	return root;
}

tn* TreeSearch(tn* root, int x)
{
	if (root == NULL)
		return NULL;
	else
	{
		if (root->val == x)
			return root;
		else if (root->val > x)
			return TreeSearch(root->left, x);
		else
			return TreeSearch(root->right, x);
	}
}