#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE* fin = fopen("filein.txt", "r");
	FILE* fout = fopen("fileout.txt", "w");
	char sin[100], sout[100], str[1000];
	gets(sin);
	gets(sout);
	int len1 = strlen(sin);
	int len3 = strlen(sout);
	int i = 0, j = 0, k = 0;
	int flag = 1;

	while (fgets(str, 1000, fin) != NULL)
	{
		int len2 = strlen(str);
		for (i = 0; i < strlen(str); i++)
		{
			flag = 1;
			for (j = i, k = 0; k < len1; j++, k++)
			{
				if (tolower(str[j]) != tolower(sin[k]))
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			//#include <stdio.h>
			//i = 1
			//len1 in 2
			//len2 str 19
			//len3 out 3
			{
				char s[1000];
				for (j = i + len1, k = 0; j < len2;j++, k++)
					s[k] = str[j];
				s[k] = '\0';
				for (k = i, j = 0; j < len3; j++, k++)
					str[k] = sout[j];
				strcpy(str + i + j, s);
				len2 = strlen(str);
			}
		}
		fputs(str, fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}


//int main()
//{
//	char a = 'a';
//	char b = toupper(a);
//	printf("%c\n", a);
//	printf("%c\n", b);
//}