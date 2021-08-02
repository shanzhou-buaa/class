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

class Solution1
{
public:
	bool isPalindrome(int x) 
	{
		if (x < 0)
			return false;
		size_t i = 0;
		//12321
		//123321
		string str;
		while (x)
		{
			int temp = x % 10;
			str += (temp + '0');
			x /= 10;
		}

		stack<char> s;
		for (i = 0; i < str.size() / 2; i++)
			s.push(str[i]);
		if (str.size() % 2 == 0)
			i = str.size() / 2;
		else
			i = str.size() / 2 + 1;
		for (; i < str.size(); i++)
		{
			if (str[i] != s.top())
				return false;
			s.pop();
		}
		return true;
	}
};

class Solution
{
public:
	int lengthOfLastWord(string& s)
	{
		string::reverse_iterator rit = s.rbegin();
		while (rit != s.rend() && *rit == ' ')
			rit++;
		int num = 0;
		while (rit != s.rend() && isalpha(*rit))
		{
			num++;
			rit++;
		}
		return num;
	}
};

int main()
{
	string s = "hello world";
	cout << Solution().lengthOfLastWord(s) << endl;
	return 0;
}