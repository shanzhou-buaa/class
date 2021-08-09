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

int GetMax(vector<int>& nums)
{
	int max = INT_MIN;
	for (auto e : nums)
	{
		if (e > max)
			max = e;
	}
	return max;
}

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		if (nums.size() < 3)
			return GetMax(nums);
		else
		{
			int init = GetMax(nums);
			int i = 0;
			for (i = 0; i < 2; i++)
			{
				int max = GetMax(nums);
				vector<int>::iterator it = nums.begin();
				while (it != nums.end())
				{
					if (*it == max)
						it = nums.erase(it);
					else
						it++;
				}
			}
			if (nums.size() == 0)
				return init;
			else
				return GetMax(nums);
		}
	}
};

int main()
{
	vector<int> v = { 1, 2, 3 };
	cout << Solution().thirdMax(v) << endl;
	return 0;
}