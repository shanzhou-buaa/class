#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char data;
}tn;

tn* BuildTree(char* s, int* pi)
{
	if (s[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	tn* newnode = (tn*)malloc(sizeof(tn));
	newnode->data = s[*pi];
	(*pi)++;
	newnode->left = BuildTree(s, pi);
	newnode->right = BuildTree(s, pi);

	return newnode;
}

void Inorder(tn* root)
{
	if (root == NULL)
		return;

	Inorder(root->left);
	printf("%c ", root->data);
	Inorder(root->right);
}

int main()
{
	char s[105];
	memset(s, 0, sizeof(s));
	while (scanf("%s", s) != EOF)
	{
		int i = 0;
		tn* root = BuildTree(s, &i);
		Inorder(root);
	}

	return 0;
}