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
	string reverseStr(string& s, int k)
	{
		size_t i = 0;
		for (i = 0; i < s.size(); i += 2*k)
		{
			if (s.size() - i > k)
			{
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else
			{
				reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}
};
int main()
{
	string str("123");
	cout << Solution().reverseStr(str, 5) << endl;
	return 0;
}