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

bool Equal(int month1, int day1,
	int month2, int day2)
{
	return (month1 == month2)
		&& (day1 == day2);
}

int main()
{
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	int m = 1, d = 1;
	int n = 1;
	while (!Equal(month, day, m, d))
	{
		n++;
		d++;
		if (d > GetMonthDay(year, m))
		{
			d -= GetMonthDay(year, m);
			m++;
		}
	}
	printf("%d\n", n);
	return 0;
}