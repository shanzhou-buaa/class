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
	vector<int> sortArrayByParity(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			while (left < right && nums[left] % 2 == 0)
				left++;
			while (left < right && nums[right] % 2 == 1)
				right--;

			swap(nums[left], nums[right]);
			left++;
			right--;
		}
		return nums;
	}
};

//总和为total
//左侧和为sum
//右侧和为total-sum-nums[i]
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		size_t i, j;
		int sum = 0, total = 0;
		for (i = 0; i < nums.size(); i++)
			total += nums[i];
		for (i = 0; i < nums.size(); i++)
		{
			if (2 * sum + nums[i] == total)
				return i;
			sum += nums[j];
		}
		return -1;
	}
};

int main()
{
	vector<int> v = { 3, 1, 2, 4 };
	
	return 0;
}