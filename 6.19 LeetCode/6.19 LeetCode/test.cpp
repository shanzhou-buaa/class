#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		string small = num1;
		string large = num2;
		if (num1.size() > num2.size())
		{
			small = num2;
			large = num1;
		}

		//large³¤£¬small¶Ì
		string::reverse_iterator srit = small.rbegin();
		string::reverse_iterator lrit = large.rbegin();

		while (srit != small.rend())
		{
			*lrit += (*srit - '0');
			if (large[0] > '9')
			{
				large[0] -= 10;
				large.insert(0, "1");
			}
			if (large.size() > 1 && *lrit > '9')
			{
				*lrit -= 10;
				(*(lrit + 1))++;
			}
			lrit++;
			srit++;
		}
		//lrit = large.rbegin();
		//while (lrit != large.rend())
		//{
			//if (large[0] > '9')
			//{
			//	large[0] -= 10;
			//	large.insert(0, "1");
			//}
			//if (large.size() > 1 && *lrit > '9')
			//{
			//	*lrit -= 10;
			//	(*(lrit + 1))++;
			//}
			//lrit++;
		
		
		return large;
	}
};

int main()
{
	//string num1 = "96423702883453279";
	//string num2 = "72156405165936898";

	string num1 = "99";
	string num2 = "12";

	cout << Solution().addStrings(num1, num2) << endl;
	return 0;
}