#include <iostream>
using namespace std;


class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	int GetDays()
	{
		int d1[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int d2[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int days = 0;
		if (_year>0 && _month>0 && _month<13 && _day>0 && _day<32)
		{
			for (int i = 1; i<_month; i++)
			{
				if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0)
					days += d2[i];
				else
					days += d1[i];
			}
			if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0)
			{
				if (_day <= d2[_month])
					days += _day;
				else
					return -1;
			}
			else
			{
				if (_day <= d1[_month])
					days += _day;
				else
					return -1;
			}
			return days;
		}
		else
			return -1;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int y;
	int m;
	int d;
	while (cin >> y >> m >> d)
	{
		Date date(y, m, d);
		int days = date.GetDays();
		cout << days;
	}
	return 0;
}