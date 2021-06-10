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

struct date
{
	int year;
	int month;
	int day;
};

bool Equal(date d1, date d2)
{
	return (d1.year == d2.year)
		&& (d1.month == d2.month)
		&& (d1.day == d2.day);
}

int main()
{
	char date1[10];
	char date2[10];
	while (scanf("%s%s", date1, date2) != EOF)
	{
		date d1, d2;
		memset(&d1, 0, sizeof(d1));
		memset(&d2, 0, sizeof(d2));
		int i = 0;
		for (i = 0; i < 4; i++)
		{
			d1.year = d1.year * 10 + date1[i] - '0';
			d2.year = d2.year * 10 + date2[i] - '0';
		}

		if (date1[4] == '0')
			d1.month = date1[5] - '0';
		else
			d1.month = (date1[4] - '0') * 10 + date1[5] - '0';
		if (date2[4] == '0')
			d2.month = date2[5] - '0';
		else
			d2.month = (date2[4] - '0') * 10 + date2[5] - '0';

		if (date1[6] == '0')
			d1.day = date1[7] - '0';
		else
			d1.day = (date1[6] - '0') * 10 + date1[7] - '0';
		if (date2[6] == '0')
			d2.day = date2[7] - '0';
		else
			d2.day = (date2[6] - '0') * 10 + date2[7] - '0';

		int n = 0;
		while (!Equal(d1, d2))
		{
			n++;
			d1.day++;
			if (d1.day > GetMonthDay(d1.year, d1.month))
			{
				d1.day -= GetMonthDay(d1.year, d1.month);
				d1.month++;
			}
			if (d1.month > 12)
			{
				d1.year++;
				d1.month = 1;
			}
		}
		n++;
		printf("%d\n", n);
	}
	return 0;
}