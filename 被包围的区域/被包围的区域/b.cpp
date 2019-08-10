#include <iostream>
#include <vector>
using namespace std;

int pos[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };  //…œœ¬◊Û”“
class Solution {
public:
	void dfs(vector<vector<char>>& board, int x, int y, int row, int col)
	{
		board[x][y] = 'W';
		for (int k = 0; k < 4; k++)
		{
			int nx = x + pos[k][0];
			int ny = y + pos[k][1];
			//cout << nx << "AND" << ny << endl;
			if (nx<0 || nx >= row || ny<0 || ny >= col)
				continue;
			if (board[nx][ny] == 'O')
				dfs(board, nx, ny, row, col);
		}
	}

	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;
		int row = board.size();
		int col = board[0].size();

		for (int j = 0; j<col; ++j)
		{
			if (board[0][j] == 'O')
				dfs(board, 0, j, row, col);
			if (board[row - 1][j] == 'O')
				dfs(board, row - 1, j, row, col);
		}
		for (int i = 0; i<row; ++i)
		{
			if (board[i][0] == 'O')
				dfs(board, i, 0, row, col);
			if (board[i][col - 1] == 'O')
				dfs(board, i, col - 1, row, col);
		}
		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<col; j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == 'W')
					board[i][j] = 'O';
			}
		}
	}

};

int main()
{
	vector<vector<char>> v = { 
	{ 'X', 'O', 'X', 'O', 'X' },
	{ 'O', 'X', 'O', 'X', 'X' }, 
	{ 'O', 'X', 'X', 'O', 'X' },
	{ 'X', 'X', 'O', 'X', 'X' } };

	Solution s;
	s.solve(v);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}

