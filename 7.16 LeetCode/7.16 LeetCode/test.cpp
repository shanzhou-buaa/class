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

int cal(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '*')
		return a * b;
	else
		return a / b;
}

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> st;
		size_t i = 0;
		while (i < tokens.size())
		{
			size_t j = 0;
			while (i < tokens.size() && j < tokens[i].size())
			{
				if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
				{
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					int ret = cal(left, right, tokens[i][j]);

					st.push(ret);
					j++;
				}
				else
				{
					int flag = 1;
					if (tokens[i][j] == '-')
					{
						flag = -1;//是负数
						j++;
					}
					//数字直接入栈
					int temp = 0;
					while (tokens[i][j] >= '0' && tokens[i][j] <= '9')
					{
						temp = temp * 10 + tokens[i][j] - '0';
						j++;
					}
					temp *= flag;
					st.push(temp);
				}
			}
			i++;
		}
		return st.top();
	}
};

int main()
{
	Solution s;
	vector<string> v = { "-78", "-33", "196", "+", "-19", "-", "115", "+", "-", "-99", "/", "-18", "8", "*", "-86", "-", "-", "16", "/", "26", "-14", "-", "-", "47", "-", "101", "-", "163", "*", "143", "-", "0", "-", "171", "+", "120", "*", "-60", "+", "156", "/", "173", "/", "-24", "11", "+", "21", "/", "*", "44", "*", "180", "70", "-40", "-", "*", "86", "132", "-84", "+", "*", "-", "38", "/", "/", "21", "28", "/", "+", "83", "/", "-31", "156", "-", "+", "28", "/", "95", "-", "120", "+", "8", "*", "90", "-", "-94", "*", "-73", "/", "-62", "/", "93", "*", "196", "-", "-59", "+", "187", "-", "143", "/", "-79", "-89", "+", "-" };

	cout << s.evalRPN(v) << endl;
	//cout << -10 / -3 << endl;
	return 0;
}