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

class Solution 
{
public:
	bool alnum(char c)
	{
		if (isdigit(c) || isalpha(c))
			return true;
		return false;
	}


	bool isPalindrome(const string& s)
	{
		int head = 0;
		int tail = s.size() - 1;
		
		while (head < tail)
		{
			while (head < tail && !alnum(s[head]))
				head++;
			char x = tolower(s[head]);
			while (head < tail && !alnum(s[tail]))
				tail--;
			char y = tolower(s[tail]);

			if (x != y)
				return false;
			else
			{
				head++;
				tail--;
			}
		}
		return true;
	}
};

int main()
{
	string s = ",.";
	Solution sol;
	cout << sol.isPalindrome(s) << endl;
	return 0;
}