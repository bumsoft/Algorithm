#include <bits/stdc++.h>
using namespace std;
char c;
int board[9][9];

bool isValid(int n, int x, int y)//행, 열
{
	//같은 행에 대해
	for (int i = 0; i < 9; i++)
	{
		if (board[x][i] == n) return 0;
	}
	//같은 열에 대해
	for (int i = 0; i < 9; i++)
	{
		if (board[i][y] == n) return 0;
	}
	//사각형 내에
	int xStart = (x / 3) * 3;
	int yStart = (y / 3) * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[xStart + i][yStart + j] == n) return 0;
		}
	}
	return 1;
}

bool backtracking(int x, int y) //현재 위치 x y
{
	if (x == 9) return true;

	if (board[x][y] != 0)
	{
		if (y == 8) return backtracking(x + 1, 0);
		return backtracking(x, y + 1);
	}

	//1~9까지 가능한지 확인 후 다음 칸으로 넘기기
	for (int n = 1; n <= 9; n++)
	{
		//i에 대해 가능한지 3가지 확인
		if (isValid(n, x, y))
		{
			board[x][y] = n;
			//다음으로
			if (y == 8)
			{
				if (backtracking(x + 1, 0)) 
					return true;
			}
			else
			{
				if (backtracking(x, y + 1)) 
					return true;
			}
			board[x][y] = 0;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> c;
			board[i][j] = c - 48;
		}

	backtracking(0, 0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
	return 0;
}
