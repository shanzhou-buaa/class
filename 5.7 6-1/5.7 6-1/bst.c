#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}tn;

tn* TreeInsert(tn** root, int x)
{
	if ((*root) == NULL)
	{
		(*root) = (tn*)malloc(sizeof(tn));
		(*root)->data = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if ((*root)->data <= x)
		(*root)->right = TreeInsert(&((*root)->right), x);
	else
		(*root)->left = TreeInsert(&((*root)->left), x);

	return (*root);
}

int GetLevel(tn* root, int x)
{
	if (root == NULL)
		return 0;

	int k = 1;
	while (1)
	{
		if (x == root->data && root->left == NULL && root->right == NULL)
			break;

		else
		{
			if (x >= root->data)
			{
				k++;
				root = root->right;
			}
			else
			{
				k++;
				root = root->left;
			}
		}
	}

	return k;
}

//root是根节点
//subRoot是当前结点
void InOrder(tn* root, tn* subRoot)
{
	if (subRoot == NULL)
		return;
	else
	{	
		InOrder(root, subRoot->left);
		if (subRoot->left == NULL && subRoot->right == NULL)
		{
			printf("%d ", subRoot->data);
			printf("%d\n", GetLevel(root, subRoot->data));
		}
		InOrder(root, subRoot->right);
	}
}

int main()
{
	int i = 0, n = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * 4);
	tn* root = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		TreeInsert(&root, a[i]);//插入数据
	}

	InOrder(root, root);
	return 0;
}