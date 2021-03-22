//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<stdlib.h>
//#include<ctype.h>
//int main(){
//	FILE *in, *out;
//	in=fopen("encrypt.txt","r");
//	out=fopen("output.txt","w");
//	char s[52]={0},t[52]={0},s1[100];
//	char c;
//	int i=0,l_s,j,k,l_s1;
//	c=fgetc(in);
//	while(c!=EOF){
//		s1[i++]=c;
//		c=fgetc(in);
//	}
//	l_s1=i;
//	scanf("%s",s);
//	l_s=strlen(s);
//	for(i=0;i<l_s;i++){
//		for(j=i+1;j<l_s;j++){
//			if(s[i]==s[j]){
//				for(k=j;k<l_s;k++){
//					s[k]=s[k+1];
//				}
//				l_s--;
//				j--;
//			}
//		}
//	}
//	s[l_s]='\0';
//	for(i=122;i>=97;i--){
//		for(j=0;j<l_s;j++){
//			if(s[j]==i)
//			break;
//		}
//		if(j==l_s){
//			s[l_s]=i;
//			l_s++;
//		}
//	}	
//	for(i=0;i<26;i++){
//			t[i]=97+i;
//		}
//	for(i=0;i<l_s1;i++){
//		for(j=0;j<26;j++){
//			if(t[j]==s1[i])
//			s1[i]=s[j];
//		}
//	}
//	for(i=0;i<l_s1;i++){
//		fputc(s1[i],out);
//	}
//	fclose(in);
//	fclose(out);
// 	return 0;
//}
