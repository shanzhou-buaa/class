//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//
//struct Key
//{
//	char word[101];
//	int cnt;
//}a[1001];
//
//int main(){
//	int m;
//	for(m=0;m<1001;m++){
//		a[m].cnt=0;
//	}
//	FILE *in=fopen("article.txt","r");
//	char new1[101];
//	int i=1,j,k;
//	//¶ÁÈëµ¥´Ê
//	while(fscanf(in,"%s",new1)!=EOF)
//	{
//		k=0;
//		for(j=0;j<strlen(new1);j++)
//		{
//			while(('a'<=new1[j]&&new1[j]<='z')||('A'<=new1[j]&&new1[j]<='Z'))
//			{
//				a[i].word[k]=tolower(new1[j]);
//				j++;
//				k++;
//			}
//			a[i].word[k]='\0';
//			if(strlen(a[i].word)!=0)
//			{
//				a[i].cnt=1;
//			}
//		}
//		i++;
//	}
//
//	i--;
//	for(j=1;j<=i;j++){
//		for(k=j+1;k<=i;k++){
//			if(strcmp(a[j].word,a[k].word)==0){
//				a[j].cnt+=a[k].cnt;
//				a[k].cnt=0;
//			}
//		}
//	}
//	char h1[101];
//	int h2;
//	for(j=1;j<=i;j++){
//		for(k=j+1;k<=i;k++){
//			if(strcmp(a[j].word,a[k].word)>0&&a[j].cnt*a[k].cnt!=0){
//				strcpy(h1,a[j].word);
//				strcpy(a[j].word,a[k].word);
//				strcpy(a[k].word,h1);
//				h2=a[j].cnt;
//				a[j].cnt=a[k].cnt;
//				a[k].cnt=h2;
//			}
//		}
//	}
//	for(j=1;j<=i;j++){
//		if(a[j].cnt!=0){
//			printf("%s %d\n",a[j].word,a[j].cnt);
//		}
//	}
//	fclose(in);
//	return 0;
//}
