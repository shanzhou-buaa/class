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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		int i = m + n - 1, i1 = m - 1, i2 = n - 1;
		while (i1 >= 0 && i2 >= 0)
		{
			if (nums1[i1] < nums2[i2])
				nums1[i--] = nums2[i2--];
			else
				nums1[i--] = nums1[i1--];
		}
		while (i1 >= 0)
			nums1[i--] = nums1[i1--];
		while (i2 >= 0)
			nums1[i--] = nums2[i2--];
		i = 0;
	}
};

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return false;
		
		sort(nums.begin(), nums.end());
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] == nums[i])
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> v1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> v2 = { 2 };
	//Solution1().merge(v1, 3, v2, 3);
	cout << Solution().containsDuplicate(v2) << endl;
	return 0;
}