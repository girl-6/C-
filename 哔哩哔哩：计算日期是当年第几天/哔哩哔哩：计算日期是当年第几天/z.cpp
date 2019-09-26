#include <iostream>
#include <string>
using namespace std;

int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	string date;
	getline(cin, date);
	int year, month, day;
	string s1, s2, s3;
	int sum = 0;
	for (int i = 0; i<4; i++)
		s1.push_back(date[i]);
	for (int i = 5; i < 7; i++)
		s2.push_back(date[i]);
	for (int i = 8; i < 10; i++)
		s3.push_back(date[i]);
	year = atoi(s1.c_str());
	month = atoi(s2.c_str());
	day = atoi(s3.c_str());

	if (month == 1)
		cout << day << endl;
	else if (month == 2)
		cout << array[0] + day << endl;
	else
	{
		sum += array[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				sum += 1;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}

