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
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;
		size_t i = 0, j = 0;
		while (i < pushed.size())
		{
			//不相等就入栈
			while (i < pushed.size() && pushed[i] != popped[j])
			{
				st.push(pushed[i]);
				i++;
			}
			//相等时还要入一次栈
			if (i < pushed.size())
			{
				st.push(pushed[i]);
				i++;
			}
			//相等就出栈，直到不相等
			while (!st.empty() && st.top() == popped[j])
			{
				st.pop();
				j++;
			}
		}
		return st.empty();

	}
};

int main()
{
	vector<int> pushed;
	pushed.push_back(8);
	pushed.push_back(9);
	pushed.push_back(2);
	pushed.push_back(3);
	pushed.push_back(7);
	pushed.push_back(0);
	pushed.push_back(5);
	pushed.push_back(4);
	pushed.push_back(6);
	pushed.push_back(1);

	vector<int> popped;
	popped.push_back(6);
	popped.push_back(8);
	popped.push_back(2);
	popped.push_back(1);
	popped.push_back(3);
	popped.push_back(9);
	popped.push_back(0);
	popped.push_back(7);
	popped.push_back(4);
	popped.push_back(5);
	Solution s;
	cout << s.validateStackSequences(pushed, popped) << endl;

	return 0;
}