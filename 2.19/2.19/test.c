#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct TreeNode
{
	char ch;
	struct TreeNode* left;
	struct TreeNode* right;
}TN;


TN* Rebuild(char* a, int* pi)
{
	if (a[(*pi)] == '#')
		return NULL;
	else
	{
		TN* newnode = (TN*)malloc(sizeof(TN));
		newnode->ch = a[(*pi)];
		(*pi)++;
		newnode->left = Rebuild(a, pi);
		(*pi)++;
		newnode->right = Rebuild(a, pi);
		return newnode;
	}
}


//前序遍历打印
void Prevorder(TN* root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%c ", root->ch);
		Prevorder(root->left);
		Prevorder(root->right);
	}
}


//中序遍历打印
void Inorder(TN* root)
{
	if (root == NULL)
		return;
	else
	{
		Inorder(root->left);
		printf("%c ", root->ch);
		Inorder(root->right);
	}
}

//后序遍历打印
void Postorder(TN* root)
{
	if (root == NULL)
		return;
	else
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("%c ", root->ch);
	}
}


void TreeDestroy(TN* root)
{
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}


TN* TreeFind(TN* root, char x)
{
	TN* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->ch == x)
		return root;
	ret = TreeFind(root->left, x);
	if (ret != NULL)
		return ret;
	ret = TreeFind(root->right, x);
	if (ret != NULL)
		return ret;
	return NULL;
}



int main()
{
	char a[100] = "ABC##DE#G##F###";
	int i = 0;
	TN* root = Rebuild(a, &i);

	Prevorder(root);
	printf("\n");
	Inorder(root);
	printf("\n");
	Postorder(root);
	printf("\n");
	TN* ret = TreeFind(root, 'A');
	printf("%c\n", ret->ch);
    return 0;
}