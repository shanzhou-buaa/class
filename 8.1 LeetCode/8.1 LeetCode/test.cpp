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
	int removeElement(vector<int>& nums, int val) 
	{
		vector<int>::iterator it = nums.begin();
		while (it != nums.end())
		{
			if (*it == val)
				it = nums.erase(it);
			else
				it++;
		}
	}
};

class Solution2 {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums[0] > target)
			return 0;
		else if (nums[nums.size() - 1] < target)
			return nums.size();

		size_t i;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
				break;
			if (i > 0 && nums[i - 1] < target && nums[i] > target)
				break;
		}
		return i;
	}
};

class Solution3 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int arr[26] = { 0 };
		for (auto e : magazine)
			arr[e - 'a']++;

		for (auto e : ransomNote)
			arr[e - 'a']--;

		for (size_t i = 0; i < 26; i++)
		{
			if (arr[i] < 0)
				return false;
		}

		return true;
	}
};

int main()
{
	string s1 = "aab";
	string s2 = "bba";
	cout << Solution3().canConstruct(s1, s2) << endl;
	return 0;
}