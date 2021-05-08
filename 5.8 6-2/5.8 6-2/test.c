#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef struct WordsTree
{
	char word[50];
	int times;
	struct WordsTree* left;
	struct WordsTree* right;
}wt;

void InOrder(wt* root);
//wt* WordsInsertTreeTimes(wt** root, char* s);//按出现次数的二叉排序数
wt* WordsInsertTreeASCII(wt* root, char* s);//按ASCII码的二叉排序树
//int TreeFind(wt* root, char* s);

wt* root1 = NULL;//按ASCII码的二叉排序树
//wt* root2 = NULL;//按出现次数的二叉排序数

int main()
{
	FILE* read = fopen("article.txt", "r");
	char line[10000];//读取全文单词的内容
	char tmp[100];//存一个单词
	memset(line, 0, sizeof(line));
	memset(tmp, 0, sizeof(tmp));
	int i = 0, j = 0;

	//读入单词
	fread(line, 1, 10000, read);
	int len = strlen(line);
	line[len] = '\0';
	//全转成小写
	for (i = 0; i < len; i++)
		line[i] = tolower(line[i]);

	//读到每一个单词
	i = 0;
	while(i < len)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			j = 0;
			while (line[i] >= 'a' && line[i] <= 'z')
			{
				tmp[j++] = line[i++];
			}
			tmp[j] = '\0';
			i++;
			root1 = WordsInsertTreeASCII(root1, tmp);
		}
		//不是字母
		else
		{
			i++;
			continue;
		}
	}
	//读入单词
	//while (fscanf(read, "%s", line) != EOF)
	//{
	//	//把line中的非字母删掉，大写转化成小写
	//	len = strlen(line);
	//	if (!isalpha(line[len - 1]))
	//	{
	//		line[len - 1] = '\0';
	//		len = strlen(line);
	//	}
	//	for (i = 0; i < len; i++)
	//	{
	//		if (!isalpha(line[i]))
	//		{
	//			strcpy(line + i, line + i + 1);
	//			len = strlen(line);
	//			i--;
	//		}
	//		line[i] = tolower(line[i]);
	//	}

	//	//把单词插入字典树
	//	root1 = WordsInsertTreeASCII(root1, line);
	//	//WordsInsertTreeTimes(&(root2), line);
	//}
	if (root1 != NULL)
	{
		printf("%s", root1->word);
		if (root1->right != NULL)
		{
			printf(" %s", root1->right->word);
			if (root1->right->right != NULL)
			{
				printf(" %s\n", root1->right->right->word);
			}
			else
				printf("\n");
		}
		else
			printf("\n");
	}
	InOrder(root1);
	return 0;
}

//wt* WordsInsertTreeASCII(wt** root, char* s)
//{
//	if ((*root) == NULL)
//	{
//		(*root) = (wt*)malloc(sizeof(wt));
//		strcpy((*root)->word, s);
//		(*root)->times = 1;
//		(*root)->left = NULL;
//		(*root)->right = NULL;
//	}
//	else
//	{
//		if (strcmp(s, (*root)->word) == 0)
//			(*root)->times++;
//		else if (strcmp(s, (*root)->word) > 0)
//			(*root)->right = WordsInsertTreeASCII(&((*root)->right), s);
//		else
//			(*root)->left = WordsInsertTreeASCII(&((*root)->left), s);
//	}
//
//	return (*root);
//}

wt* WordsInsertTreeASCII(wt* root, char* s)
{
	if (root == NULL)
	{
		root = (wt*)malloc(sizeof(wt));
		strcpy(root->word, s);
		root->times = 1;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (strcmp(s, root->word) == 0)
			root->times++;
		else if (strcmp(s, root->word) > 0)
			root->right = WordsInsertTreeASCII(root->right, s);
		else
			root->left = WordsInsertTreeASCII(root->left, s);
	}

	return root;
}


void InOrder(wt* root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%s %d\n", root->word, root->times);
	InOrder(root->right);
}
//wt* WordsInsertTreeTimes(wt** root, char* s)
//{
//	if ((*root) == NULL)
//	{
//		(*root) = (wt*)malloc(sizeof(wt));
//		strcpy((*root)->word, s);
//		(*root)->times = 1;
//		(*root)->left = NULL;
//		(*root)->right = NULL;
//	}
//	else
//	{
//		int times = TreeFind(root1, s);
//		if (times >= (*root)->times)
//			(*root)->right = WordsInsertTreeTimes(&((*root)->right), s);
//		else
//			(*root)->left = WordsInsertTreeTimes(&((*root)->left), s);
//	}
//
//	return (*root);
//}

//在按ASCII码的二叉排序树里找
//int TreeFind(wt* root, char* s)
//{
//	if (root == NULL)
//		return 0;
//
//	if (strcmp(s, root->word) == 0)
//		return root->times;
//	else if (strcmp(s, root->word) > 0)
//		return TreeFind(root->right, s);
//	else
//		return TreeFind(root->left, s);
//}
