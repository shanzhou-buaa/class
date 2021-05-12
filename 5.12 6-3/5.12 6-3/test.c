#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode
{
	int data;
	char op;
	struct TreeNode* left;
	struct TreeNode* right;
}tn;

int TreeTop = 0;
tn TreeStack[100000];

typedef struct Option
{
	char c;
	int priority;
}Option;

typedef struct OpStack
{
	Option s[100000];//计算符号
	int size;//当前栈中数据个数
}ostack;

tn* TreeNodeStackPop(tn* ts)
{
	tn* temp = (tn*)malloc(sizeof(tn));
	memcpy(temp, &ts[TreeTop - 1], sizeof(tn));
	TreeTop--;

	return temp;
}

tn TreeNodeStackTop(tn* ts)
{
	return ts[TreeTop - 1];
}

void OpStackInit(ostack* os)
{
	os->size = 0;
}

char OpStackPop(ostack* os)
{
	return os->s[--os->size].c;
}

char OpStackTop(ostack* os)
{
	return os->s[os->size - 1].c;
}

int OpStackEmpty(ostack* os)
{
	return os->size == 0;
}

int cal(int x, int y, char op)
{
	if (op == '+')
		return x + y;
	else if (op == '-')
		return x - y;
	else if (op == '*')
		return x * y;
	else if (op == '/')
		return x / y;
	else
		return x % y;
}

void squeez(char* s, char c)
{
	int i, j;
	int len = strlen(s);
	for (i = 0, j = 0; i < len; i++)
	{
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

int priority(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/' || c == '%')
		return 2;
	else if (c == '(')
		return 3;
	else
		return 4;
}

void TreeNodeStackPush(tn* ts,int data, char op)
{
	if (op == 0)//是数字
	{
		ts[TreeTop].data = data;
		ts[TreeTop].op = op;
		ts[TreeTop].left = NULL;
		ts[TreeTop].right = NULL;
		TreeTop++;
	}
	else//是运算符
	{
		tn* new1 = (tn*)malloc(sizeof(tn));
		tn* new2 = (tn*)malloc(sizeof(tn));
		tn* newNode = (tn*)malloc(sizeof(tn));
		memcpy(new1, &ts[TreeTop - 1], sizeof(tn));
		TreeTop--;
		memcpy(new2, &ts[TreeTop - 1], sizeof(tn));
		newNode->data = cal(new2->data, new1->data, op);
		newNode->left = new2;
		newNode->right = new1;
		newNode->op = op;
		memcpy(&ts[TreeTop - 1], newNode, sizeof(tn));
	}
}

void OpStackPush(ostack* os, int priority, char op)
{
	if (priority == 4)//碰到右括号就往前找左括号
	{
		while (!OpStackEmpty(os))
		{
			if (os->s[os->size - 1].c != '(')
			{
				TreeNodeStackPush(TreeStack, 0, os->s[os->size - 1].c);//把运算符插入树中
				os->size--;
			}
			else
				break;
		}
		os->size--;//左括号出栈
	}
	else if (OpStackEmpty(os))//空直接入栈
	{
		os->s[os->size].c = op;
		if (op == '(')
			os->s[os->size].priority = 0;
		else
			os->s[os->size].priority = priority;
		os->size++;
	}
	else if (priority > os->s[os->size - 1].priority)//新的运算符优先级高于栈顶运算符则入栈
	{
		os->s[os->size].c = op;
		if (op == '(')
			os->s[os->size].priority = 0;
		else
			os->s[os->size].priority = priority;
		os->size++;
	}
	else if (priority <= os->s[os->size - 1].priority && priority != 3)//新的运算符优先级低于等于栈顶运算符，插入树中
	{
		//把优先级高的都放进树里
		while (priority <= os->s[os->size - 1].priority && os->s[os->size - 1].priority != 3)
		{
			TreeNodeStackPush(TreeStack, 0, os->s[os->size - 1].c);
			os->size--;
			if (OpStackEmpty(os))
				break;
		}
		//把新的运算符放进栈
		os->s[os->size].c = op;
		os->s[os->size].priority = priority;
		os->size++;
	}
}

int TreeCal(tn* root)
{
	if (root->left == NULL || root->right == NULL)
		return root->data;

	//后序算
	root->left->data = TreeCal(root->left);
	root->right->data = TreeCal(root->right);
	root->data = cal(root->left->data, root->right->data, root->op);
	free(root->left);
	free(root->right);

	return root->data;
}

int main()
{
	//memset(TreeStack, 0, sizeof(TreeStack));
	
	char s[10000];
	memset(s, 0, sizeof(s));
	gets(s);
	squeez(s, ' ');
	int len = strlen(s);
	
	ostack os;//符号栈
	OpStackInit(&os);

	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (s[i] == '=')
			break;

		else if (isdigit(s[i]))//把数字字符串转化为int类型的数字
		{
			int temp = s[i] - '0';
			while (isdigit(s[i + 1]))
			{
				i++;
				temp = temp * 10 + s[i] - '0';
			}
			TreeNodeStackPush(TreeStack, temp, 0);
		}
		else//运算符
		{
			int pri = priority(s[i]);
			OpStackPush(&os, pri, s[i]);
		}
	}

	i = 0;
	if (os.size == 1 || (os.s[os.size - 1].priority < os.s[os.size - 2].priority))
	{
		tn* new1 = (tn*)malloc(sizeof(tn));
		tn* new2 = (tn*)malloc(sizeof(tn));
		tn* newNode = (tn*)malloc(sizeof(tn));
		memcpy(new1, &TreeStack[TreeTop - 1], sizeof(tn));
		TreeTop--;
		memcpy(new2, &TreeStack[TreeTop - 1], sizeof(tn));
		newNode->data = cal(new2->data, new1->data, os.s[i].c);
		newNode->left = new2;
		newNode->right = new1;
		newNode->op = os.s[i].c;
		memcpy(&TreeStack[TreeTop - 1], newNode, sizeof(tn));
		i++;
	}
	else
	{
		tn* new1 = (tn*)malloc(sizeof(tn));
		tn* new2 = (tn*)malloc(sizeof(tn));
		tn* newNode = (tn*)malloc(sizeof(tn));
		memcpy(new1, &TreeStack[TreeTop - 1], sizeof(tn));
		TreeTop--;
		memcpy(new2, &TreeStack[TreeTop - 1], sizeof(tn));
		newNode->data = cal(new2->data, new1->data, os.s[os.size - 1].c);
		newNode->left = new2;
		newNode->right = new1;
		newNode->op = os.s[os.size - 1].c;
		memcpy(&TreeStack[TreeTop - 1], newNode, sizeof(tn));
		os.size--;

		memcpy(new1, &TreeStack[TreeTop - 1], sizeof(tn));
		TreeTop--;
		memcpy(new2, &TreeStack[TreeTop - 1], sizeof(tn));
		newNode->data = cal(new2->data, new1->data, os.s[os.size - 1].c);
		newNode->left = new2;
		newNode->right = new1;
		newNode->op = os.s[os.size - 1].c;
		memcpy(&TreeStack[TreeTop - 1], newNode, sizeof(tn));
	}

	tn* root = &TreeStack[TreeTop - 1];
	if (root->left == NULL && root->right == NULL)
	{
		printf("%d\n", root->data);
		return 0;
	}

	if (root != NULL)
	{
		if (root->op == 0)
			printf("%d ", root->data);
		else
			printf("%c ", root->op);
	}
	if (root->left != NULL)
	{
		if (root->left->op == 0)
			printf("%d ", root->left->data);
		else
			printf("%c ", root->left->op);
	}
	
	if (root->right != NULL)
	{
		if (root->right->op == 0)
			printf("%d\n", root->right->data);
		else
			printf("%c\n", root->right->op);
	}
	else
		printf("\n");

	printf("%d\n", root->data);

	return 0;
}

//(8/9+8)*(5*7+6)/(4+8)+1=28
//24 / ( 1 + 2 + 36 / 6 / 2 - 2) * ( 12 / 2 / 2 )     =
//(1+3+4*5*(36/9+37))/(7+81/10+3*6)=24
//1=1
//(((1+2)+13%10)+4)* (5-5) =
//(((1+2)+3)+4)+5=
//1+(2+(3+4))=
//12*(15+12)/4   =
//((12+13)/5+(   (100+15%3)4-16)*4)/ 6   =
//12*15 +12 / 4  =
//2 * 5 * 3 + 2     =