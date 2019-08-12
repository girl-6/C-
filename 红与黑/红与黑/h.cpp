#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Get(vector<vector<char>>& v, int x, int y, int m, int n, int &count)
{
	if (x<0 || y<0 || x >= m || y >= n || v[x][y] == '1' || v[x][y] == '#')
		return;
	count++;
	v[x][y] = '1';
	Get(v, x - 1, y, m, n, count);
	Get(v, x, y - 1, m, n, count);
	Get(v, x + 1, y, m, n, count);
	Get(v, x, y + 1, m, n, count);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int x, y;
		int count = 0;
		vector<vector<char>> v(m, vector<char>(n, 0));
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		Get(v, x, y, m, n, count);
		cout << count << endl;
	}
	return 0;
}