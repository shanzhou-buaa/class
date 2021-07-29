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
	string reverseWords(string& s) 
	{
		string ret;
		size_t i = 0;
		for (i = 0; i < s.size(); i++)
		{
			string temp;
			while (i < s.size() && s[i] != ' ')
			{
				temp += s[i];
				i++;
			}
			reverse(temp.begin(), temp.end());
			ret += temp;
			if (i != s.size())
				ret += " ";
		}

		return ret;
	}
};
int main()
{
	Solution s;
	string str("Let's take LeetCode contest");
	cout << s.reverseWords(str) << endl;
	return 0;
}