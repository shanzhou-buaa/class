#define _CRT_SECURE_NO_WARNINGS 1

//文件压缩-Huffman实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman树结构
	char c;						//字符
	int weight;					//树节点权重，叶节点为字符和它的出现次数
	struct tnode *left,*right;
}; 
int Ccount[128]={0};			//存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数 
struct tnode *Root=NULL; 		//Huffman树的根节点
char HCode[128][MAXSIZE]={{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式） 
int Step=0;						//实验步骤 
FILE *Src, *Obj;				//Src为读入文件的指针，Obj为输出文件的指针
	
void statCount();				//步骤1：统计文件中字符频率
void createHTree();				//步骤2：创建一个Huffman树，根节点为Root 
void makeHCode();				//步骤3：根据Huffman树生成Huffman编码
void atoHZIP(); 				//步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件

void print1();					//输出步骤1的结果
void print2(struct tnode *p);	//输出步骤2的结果 
void print3();					//输出步骤3的结果
void print4();					//输出步骤4的结果

void PreOrder(struct tnode* root, int index, char* s);

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//输入当前实验步骤 
	
	statCount();						//实验步骤1：统计文件中字符出现次数（频率）
	(Step==1) ? print1(): 1; 			//输出实验步骤1结果	
	createHTree();						//实验步骤2：依据字符频率生成相应的Huffman树
	(Step==2) ? print2(Root): 2; 		//输出实验步骤2结果	
	makeHCode();				   		//实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
	(Step==3) ? print3(): 3; 			//输出实验步骤3结果
	(Step>=4) ? atoHZIP(),print4(): 4; 	//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//【实验步骤1】开始 

void statCount()
{
	Ccount[0] = 1;
	while (1)
	{
		char c = fgetc(Src);
		if (c == EOF)
			break;
		Ccount[c]++;
	}
}

//【实验步骤1】结束

//【实验步骤2】开始

void createHTree()
{
	struct tnode* tree[130];
	int i = 0, j = 0, index = 0;//index是tree数组中指针的个数
	for (i = 0; i < 130; i++)//从0开始
		tree[i] = NULL;

	//把树林放进tree指针数组里
	for (i = 0; i < 128; i++)
	{
		if (Ccount[i] > 0)
		{
			struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
			node->c = i;
			node->weight = Ccount[i];
			node->left = NULL;
			node->right = NULL;

			tree[index++] = node;
		}
	}

	//排序
	i = 0, j = 0;
	for (i = 0; i < index - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < index - i - 1; j++)
		{
			if (tree[j]->weight > tree[j + 1]->weight)
			{
				flag = 0;
				struct tnode* temp = tree[j];
				tree[j] = tree[j + 1];
				tree[j + 1] = temp;
			}
		}
		if (flag)
			break;
	}
	
	struct tnode* root = NULL;
	while (index > 1)
	{
		int init = index;
		//连接一个新树
		root = (struct tnode*)malloc(sizeof(struct tnode));
		struct tnode* t0 = (struct tnode*)malloc(sizeof(struct tnode));
		struct tnode* t1 = (struct tnode*)malloc(sizeof(struct tnode));
		root->left = t0;
		root->right = t1;
		memcpy(t0, tree[0], sizeof(struct tnode));
		memcpy(t1, tree[1], sizeof(struct tnode));
		//root->c = t0->c + t1->c;
		root->weight = t0->weight + t1->weight;
		tree[0]->weight = -1;
		tree[1]->weight = -1;

		//把后面的指针往前挪
		for (i = 0, j = 0; i < index; i++)
		{
			if (tree[i]->weight == -1)
				continue;
			
			//不是被删除的指针且权值小于root
			if (tree[i]->weight < root->weight)
				memcpy(tree[j++], tree[i], sizeof(struct tnode));
			
			//碰见相等的，放到这一串的最后面
			if (tree[i]->weight == root->weight)
			{
				while (tree[i]->weight == root->weight)
					memcpy(tree[j++], tree[i++], sizeof(struct tnode));
				memcpy(tree[j++], root, sizeof(struct tnode));
				break;
			}
			if (j > 1 && tree[i]->weight > root->weight && tree[j - 1]->weight < root->weight)
			{
				memcpy(tree[j++], root, sizeof(struct tnode));
				break;
			}
		}

		//root是最大的
		if (i == index)
			memcpy(tree[j++], root, sizeof(struct tnode));

		while (i < index)
			memcpy(tree[j++], tree[i++], sizeof(struct tnode));

		index--;
		//for (i = index; i < init; i++)
			//memset(tree[i], 0, sizeof(struct tnode));
	}
	
	Root = root;
}

//【实验步骤2】结束

//【实验步骤3】开始

void PreOrder(struct tnode* root, int index, char* s)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			s[index] = '\0';
			strcpy(HCode[root->c], s);
			return;
		}
		s[index] = '0';
		PreOrder(root->left, index + 1, s);
		s[index] = '1';
		PreOrder(root->right, index + 1, s);
	}
	else
		return;
}

void makeHCode()
{
	char s[40];
	int index = 0;
	PreOrder(Root, index, s);
} 

//【实验步骤3】结束

//【实验步骤4】开始

void atoHZIP()
{
	char s[5005];
	char code[10005];
	memset(code, 0, 10005);
	rewind(Src);
	int len = fread(s, 1, 5000, Src);
	int hc = 0, i;
	//根据输入字符序列将其Huffman编码串连接成一个由0、1字符组成的串
	for (i = 0; i < len; i++)
		strcat(code, HCode[s[i]]);
	strcat(code, HCode[0]);
	int len1 = strlen(code);
	for (i = 0; code[i] != '\0'; i++)
	{
		hc = (hc << 1) | (code[i] - '0');
		if ((i + 1) % 8 == 0)
		{
			fputc(hc, Obj);     //输出到目标（压缩）文件中
			printf("%x", hc);   //按十六进制输出到屏幕上
			hc = 0;
		}
	}
	if (len1 % 8 != 0)
	{
		int remain = len1 % 8;
		int x = 0;
		for (i = 0; i < remain; i++)
			x = (x << i) | (hc << i);
		fputc(x, Obj);
		printf("%x", x);
	}
}

//【实验步骤4】结束

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\n原文件大小：%ldB\n",in_size);
	printf("压缩后文件大小：%ldB\n",out_size);
	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
