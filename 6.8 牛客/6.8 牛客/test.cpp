#include <iostream>
using namespace std;

int GetMonthDay(int year, int month)
{
	int dayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArr[month];
	if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 400 != 0)))
		day++;
	return day;
}

int main()
{
	int m, year, month, day, num;
	scanf("%d", &m);
	int i = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &year, &month, &day, &num);
		day += num;
		while (day > GetMonthDay(year, month))
		{
			day -= GetMonthDay(year, month);
			month++;
			if (month == 13)
			{
				year++;
				month = 1;
			}
		}
		printf("%04d-%02d-%02d\n", year, month, day);
	}
	return 0;
}