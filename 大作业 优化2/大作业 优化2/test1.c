//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//int trie[1000010][26];
//int num[1000010];
//
//int main()
//{
//	int p = 0, i, pos = 0;
//	char str[] = "love";
//	for (i = 0; str[i]; i++)
//	{
//		int n = str[i] - 'a';
//		if (trie[p][n] == 0)
//			trie[p][n] = ++pos;
//		p = trie[p][n];
//	}
//	num[p]++;
//	p = 0;
//	for (i = 0; str[i]; i++)
//	{
//		int n = str[i] - 'a';
//		if (trie[p][n] == 0)
//		{
//			printf("0\n");
//			return 0;
//		}
//		p = trie[p][n];
//	}
//	printf("%d\n", num[p]);
//	return 0;
//}