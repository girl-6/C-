#include <iostream>
using namespace std;

bool IsSu(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

bool IsRun(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int Money(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int sum = 0;
	int s1[] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
	int s2[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y1 == y2&&m1 == m2)
	{
		int n = 0;
		if (IsSu(m1))
			n += d2 - d1 + 1;
		else
			n += 2 * (d2 - d1 + 1);
		sum = n;
	}
	else if (y1 == y2&&m1 != m2)
	{
		int n = 0;
		if (!IsRun(y1))
		{
			for (int i = m1 + 1; i<m2; i++)
				n += s1[i];
			if (IsSu(m1) && IsSu(m2))
				n += s2[m1] - d1 + 1 + s2[m2] - d2 + 1;
			else if (!IsSu(m1) && !IsSu(m2))
				n += 2 * (s2[m1] - d1 + 1 + s2[m2] - d2 + 1);
			else if (!IsSu(m1) && IsSu(m2))
				n += 2 * (s2[m1] - d1 + 1) + s2[m2] - d2 + 1;
			else
				n += s2[m1] - d1 + 1 + 2 * (s2[m2] - d2 + 1);
		}
		else
		{
			if (m1<2 && 2<m2)
				n += 1;
		}
		sum = n;
	}
	else
	{
		int n = 0;
		for (int i = y1 + 1; i<y2; i++)
		{
			if (!IsRun(i))
				n += 579;
			else
				n += 580;
		}
		for (int i = m1 + 1; i <= 12; i++)
		{
			if (IsRun(y1) && i == 2)
				n += 1;
			n += s1[i];
		}
		if (IsSu(m1))
			n += s2[m1] - d1 + 1;
		else
			n += 2 * (s2[m1] - d1 + 1);
		for (int i = 1; i<m2; i++)
		{
			if (IsRun(y2) && i == 2)
				n += 1;
			n += s1[i];
		}
		if (IsSu(m2))
			n += d2;
		else
			n += 2 * d2;
		sum = n;
	}
	return sum;
}

int main()
{
	int y1 = 0; int y2 = 0;
	int m1 = 0; int m2 = 0;
	int d1 = 0; int d2 = 0;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
	{
		int sum = 0;
		sum = Money(y1, m1, d1, y2, m2, d2);
		cout << sum << endl;
	}
	system("pause");
	return 0;
}

