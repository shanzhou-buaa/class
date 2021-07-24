#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
	int StrToInt(const string& str)
	{
		int ret = 0, flag = 0;
		size_t pos = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			pos = 1;
			flag = 1;
		}
		else if (!isdigit(str[0]))
			return 0;

		for (; pos < str.size(); pos++)
		{
			if (!isdigit(str[pos]))
				return 0;
			else
				ret = ret * 10 + str[pos] - '0';
		}
		if (flag == 1)
		{
			if (str[0] == '-')
				ret *= -1;
		}
		return ret;
	}
};

int main()
{
	string str = "-2107483647";
	Solution s;
	cout << s.StrToInt(str) << endl;
	return 0;
}