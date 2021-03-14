#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int s[30][30];
	int i, j;
	int flag = 0;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19; j++)
		{
			//行相等
			if (s[i][j] == s[i][j + 1] && s[i][j + 1] == s[i][j + 2]
				&& s[i][j + 2] == s[i][j + 3] && s[i][j] != 0)
			{
				if ((s[i][j - 1] == 0 || s[i][j + 4] == 0)
					|| (j - 1 < 0 && s[i][j + 4] == 0)
					|| (j + 4 > 19 && s[i][j - 1] == 0))
				{
					printf("%d:%d,%d\n", s[i][j], i + 1, j + 1);
					flag = 1;
				}
			}
				
			//列相等
			else if (s[i][j] == s[i + 1][j] && s[i + 1][j] == s[i + 2][j]
				&& s[i + 2][j] == s[i + 3][j] && s[i][j] != 0)
			{
				if ((s[i - 1][j] == 0 || s[i + 4][j] == 0)
					|| (i - 1< 0 && s[i + 4][j] == 0)
					|| (i + 4 > 19 && s[i - 1][j] == 0))
				{
					printf("%d:%d,%d\n", s[i][j], i + 1, j + 1);
					flag = 1;
				}
			}
			else if (s[i][j] == s[i + 1][j + 1] && s[i + 1][j + 1] == s[i + 2][j + 2]
				&& s[i + 2][j + 2] == s[i + 3][j + 3] && s[i][j] != 0)
			{
				if ((s[i - 1][j - 1] == 0 || s[i + 4][j + 4] == 0)
					|| ((i - 1 < 0 || j - 1 < 0) && s[i + 4][j + 4] == 0)
					|| ((i + 4 > 19 || j + 4 > 19) && s[i - 1][j - 1] == 0))
				{
					printf("%d:%d,%d\n", s[i][j], i + 1, j + 1);
					flag = 1;
				}
			}
			//     0
			//    1
			//   1
			//  1
			// 1
			//0
			else if (s[i][j] == s[i + 1][j - 1] && s[i + 1][j - 1] == s[i + 2][j - 2]
				&& s[i + 2][j - 2] == s[i + 3][j - 3] && s[i][j] != 0)
			{
				if ((s[i - 1][j + 1] == 0 || s[i + 4][j - 4] == 0)
					|| ((i - 1 < 0 || j + 1 > 19) && s[i - 4][j + 4] == 0)
					|| ((j + 4 >19 || i - 4 < 0) && s[i - 1][j + 1] == 0))
				{
					printf("%d:%d,%d\n", s[i][j], i + 1, j + 1);
					flag = 1;
				}
			}
		}
	}
	if (flag == 0)
		printf("No\n");
	return 0;
}

//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 2 0 1 1 2 0 0 0 0 0 0 0
//0 0 0 0 0 2 1 1 1 1 2 2 0 0 0 0 0 0 0 
//0 0 0 0 0 0 0 1 2 1 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 1 1 0 2 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 2 0 1 0 0 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0


//0 2 0 2 1 0 0 0 0 0 0 0 0 0 0 2 0 0 2
//0 0 2 0 2 0 0 0 0 0 0 0 0 0 0 0 2 2 0
//0 2 0 2 2 0 0 0 0 0 0 0 0 0 0 0 2 2 0
//2 0 0 1 2 0 0 0 0 0 0 0 0 0 0 2 2 2 2
//0 0 1 0 2 1 0 0 0 0 0 0 0 0 1 0 0 0 0
//0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//1 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 2 0 1 1 2 0 0 0 0 0 0 0
//0 0 0 0 0 2 1 0 1 0 2 2 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 1 2 1 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 1 1 0 0 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 2 0 1 0 0 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

//0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 2 2 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 2 0 1 1 2 0 0 0 0 0 0 0
//0 0 0 0 0 2 1 1 1 0 2 2 0 0 0 0 0 0 0 
//0 0 0 0 0 0 0 1 2 1 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 1 1 0 2 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 2 0 1 0 0 2 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0


//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
