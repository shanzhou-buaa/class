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
	vector<int> twoSum(vector<int>& nums, int target) {
		int i, j;
		int flag = 1;
		for (i = 0; i < nums.size(); i++)
		{
			for (j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					flag = 0;
					break;
				}
			}
			if (!flag)
				break;
		}
		return{ i, j };
	}
};
int main()
{
	vector<int> v = { 2, 7, 11, 15 };
	Solution().twoSum(v, 9);
	return 0;
}