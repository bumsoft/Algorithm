#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// 파이프는 1개로 생각하고 풀기

int N;
int board[33][33];
//3차원 dp
ll mem[33][33][3];

// 0: 가로
// 1: 세로
// 2: 대각

ll dp(int i,int j, int dir)
{
	if (i > N || j > N) return 0;
	if (board[i][j] == 1) return 0;
	if (dir == 2 && (board[i - 1][j] == 1 || board[i][j - 1] == 1)) return 0; // 벽 추가 고려
	if (i == N && j == N) return 1;

	if (mem[i][j][dir] != -1) return mem[i][j][dir];

	if (dir == 0) //가로
	{
		return mem[i][j][dir] = dp(i + 1, j + 1, 2) + dp(i, j + 1, 0);
	}

	if (dir == 1) //세로
	{
		return mem[i][j][dir] = dp(i + 1, j, 1) + dp(i + 1, j + 1, 2);
	}

	if (dir == 2) //대각
	{
		return mem[i][j][dir] = dp(i, j + 1, 0) + dp(i + 1, j, 1) + dp(i + 1, j + 1, 2);
	}
	
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >>  board[i][j];
			for (int k = 0; k < 3; k++)
			{
				mem[i][j][k] = -1;
			}
		}
	}
	cout<<dp(1, 2, 0); //0행 1열 가로


	return 0;
}