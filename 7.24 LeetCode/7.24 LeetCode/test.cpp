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
	int firstUniqChar(string s)
	{
		int arr[26] = { 0 };
		for (auto e : s)
			arr[e - 'a']++;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (arr[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};

class Solution2
{
public:
	void reverseString(vector<char>& s) 
	{
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
};

int main()
{

	return 0;
}