////文件压缩-Huffman实现
//#define _CRT_SECURE_NO_WARNINGS 1
//#include  <stdio.h>
//#include  <string.h>
//#include  <stdlib.h>
//
//#define  MAXSIZE  32
//
//struct  tnode  {                        //Huffman树结构
//	char  c;
//	int  weight;                //树节点权重，叶节点为字符和它的出现次数
//	struct  tnode  *left,*right;
//}  ;
//int  Ccount[128]= {0};               //存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数
//struct  tnode  *Root=NULL;          //Huffman树的根节点
//char  HCode[128][MAXSIZE]= {{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式）
//int  Step=0;                        //实验步骤
//FILE  *Src,  *Obj;
//
//void  statCount();                //步骤1：统计文件中字符频率
//void  createHTree();                //步骤2：创建一个Huffman树，根节点为Root
//void  makeHCode();                //步骤3：根据Huffman树生成Huffman编码
//void  atoHZIP();                  //步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件
//
//void  print1();                        //输出步骤1的结果
//void  print2(struct  tnode  *p);        //输出步骤2的结果
//void  print3();                        //输出步骤3的结果
//void  print4();                        //输出步骤4的结果
//
//int  main() {
//	if((Src=fopen("input.txt","r"))==NULL)  {
//		fprintf(stderr,  "%s  open  failed!\n",  "input.txt");
//		return  1;
//	}
//	if((Obj=fopen("output.txt","w"))==NULL)  {
//		fprintf(stderr,  "%s  open  failed!\n",  "output.txt");
//		return  1;
//	}
//	scanf("%d",&Step);                //输入当前实验步骤
//
//	statCount();                        //实验步骤1：统计文件中字符出现次数（频率）
//	(Step==1)?print1():1;              //输出实验步骤1结果
//	createHTree();                        //实验步骤2：依据字符频率生成相应的Huffman树
//	(Step==2)?print2(Root):2;          //输出实验步骤2结果
//	makeHCode();                //实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
//	(Step==3)?print3():3;              //输出实验步骤3结果
//	(Step>=4)?atoHZIP(),print4():4;//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果
//
//	fclose(Src);
//	fclose(Obj);
//	return  0;
//}
//void print1() {
//	int i;
//	printf("NUL:1\n");
//	for(i=1; i<128; i++)
//		if(Ccount[i] > 0)
//			printf("%c:%d\n", i, Ccount[i]);
//}
//
//void print2(struct tnode *p) {
//	if(p != NULL) {
//		if((p->left==NULL)&&(p->right==NULL))
//			switch(p->c) {
//				case 0:
//					printf("NUL ");
//					break;
//				case ' ':
//					printf("SP ");
//					break;
//				case '\t':
//					printf("TAB ");
//					break;
//				case '\n':
//					printf("CR ");
//					break;
//				default:
//					printf("%c ",p->c);
//					break;
//			}
//		print2(p->left);
//		print2(p->right);
//	}
//}
//
//void print3() {
//	int i;
//
//	for(i=0; i<128; i++) {
//		if(HCode[i][0] != 0) {
//			switch(i) {
//				case 0:
//					printf("NUL:");
//					break;
//				case ' ':
//					printf("SP:");
//					break;
//				case '\t':
//					printf("TAB:");
//					break;
//				case '\n':
//					printf("CR:");
//					break;
//				default:
//					printf("%c:",i);
//					break;
//			}
//			printf("%s\n",HCode[i]);
//		}
//	}
//}
//
//void print4() {
//	long int in_size, out_size;
//
//	fseek(Src,0,SEEK_END);
//	fseek(Obj,0,SEEK_END);
//	in_size = ftell(Src);
//	out_size = ftell(Obj);
//
//	printf("\n原文件大小：%ldB\n",in_size);
//	printf("压缩后文件大小：%ldB\n",out_size);
//	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
//}
//void statCount() {
//	char u;
//	Ccount[0]=1;
//	while((u=fgetc(Src))!=EOF) {
//		Ccount[(int)u]++;
//	}
//}
//int cmp(const void *a,const void *b) {
//	struct tnode **p=(struct tnode**)a;
//	struct tnode **q=(struct tnode**)b;
//	if((*p)->weight!=(*q)->weight)
//		return (*p)->weight-(*q)->weight;
//	else
//		return (*p)->c-(*q)->c;
//}
//void createHTree() {
//	int i,j,n=0;
//	struct tnode *F[128],*p;
//	for(i=0; i<128; i++) {
//		if(Ccount[i]) {
//			p = (struct tnode *)malloc(sizeof(struct tnode));
//			p->c = i;
//			p->weight = Ccount[i];
//			p->left = p->right = NULL;
//			F[n++]=p;
//		}
//	}
//	qsort(F,n,sizeof(struct tnode *),cmp);
//	while(n>1) {
//		p = (struct tnode *)malloc(sizeof(struct tnode));
//		p->weight = F[0]->weight+F[1]->weight;
//		p->left=(struct tnode *)malloc(sizeof(struct tnode));
//		p->right=(struct tnode *)malloc(sizeof(struct tnode));
//		memcpy(p->left,F[0],sizeof(struct tnode));
//		memcpy(p->right,F[1],sizeof(struct tnode));
//		for(i=2; i<n; i++) {
//			if(F[i]->weight>p->weight) {
//				if(i==2) {
//					memcpy(F[1],p,sizeof(struct tnode));
//					for(j=0; j<n-1; j++)
//						memcpy(F[j],F[j+1],sizeof(struct tnode));
//				} else {
//					for(j=1; j<i-1; j++)
//						memcpy(F[j],F[j+1],sizeof(struct tnode));
//					memcpy(F[i-1],p,sizeof(struct tnode));
//					for(j=0; j<n-1; j++)
//						memcpy(F[j],F[j+1],sizeof(struct tnode));
//				}
//				break;
//			} else if(i==n-1&&F[i]->weight<p->weight) {
//				for(j=0; j<n-2; j++)
//					memcpy(F[j],F[j+2],sizeof(struct tnode));
//				memcpy(F[j],p,sizeof(struct tnode));
//			}
//		}
//		n--;
//	}
//	Root=p;
//}
//
//void visitHTree(struct tnode *p,char *s,int cur) {
//	if(p!=NULL) {
//		if(p->left==NULL && p->right==NULL) {
//			s[cur]='\0';
//			strcpy(HCode[p->c],s);
//			return;
//		}
//		s[cur]='0';
//		visitHTree(p->left,s,cur+1);
//		s[cur]='1';
//		visitHTree(p->right,s,cur+1);
//	}
//}
//void makeHCode() {
//	char s[2000];
//	memset(s,'\0',2000);
//	visitHTree(Root,s,0);
//}
//char s[200000],s1[200000];
//void atoHZIP() {
//	int i,j,hc=0;
//	Src=fopen("input.txt","r");
//	fread(s,sizeof(char),200000,Src);
//	for(i=0; s[i]!='\0'; i++) {
//		strcat(s1,HCode[s[i]]);
//	}
//	strcat(s1,HCode[0]);
//	for(i=0;s1[i]!='\0'||(i+1)%8!=0;i++) {
//		if(s1[i]!='\0')
//			hc = (hc << 1) | (s1[i]-'0');
//		else
//			hc = (hc << 1) | 0;
//		if((i+1)%8 == 0) {
//			fputc(hc,Obj);     //输出到目标（压缩）文件中
//			printf("%x",hc);   //按十六进制输出到屏幕上
//			hc=0;
//		}
//	}
//}
//
