#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int GetMonthDay(int year, int month)
{
	int dayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArr[month];
	if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		day++;
	return day;
}

int main()
{
	int y, n;
	while (scanf("%d%d", &y, &n) != EOF)
	{
		int year = y, month = 1, day = n;
		while (day > GetMonthDay(year, month))
		{
			day -= GetMonthDay(year, month);
			month++;
			if (month > 12)
			{
				year++;
				month = 1;
			}
		}
		printf("%04d-%02d-%02d\n", year, month, day);
	}
	return 0;
}