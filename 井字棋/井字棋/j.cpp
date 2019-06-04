#include<vector>
#include<iostream>
using namespace std;

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		if ((board[0][0] + board[1][1] + board[2][2]) == 3)   //���Խ���
			return true;
		if ((board[0][2] + board[1][1] + board[2][0]) == 3)     //���Խ���
			return true;
		for (int i = 0; i<3; i++)
		{
			int a = 0;
			int b = 0;
			for (int j = 0; j<3; j++)
			{ 
				a += board[i][j];       //��
				b += board[j][i];       //��
			}
			if (a == 3)
				return true;
			if (b == 3)
				return true;
		}
		return false;
	}
};