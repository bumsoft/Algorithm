#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int W, H;
int mem[101][101][2][2]; //[i][j][0]: i j위치에서 교차로 방금 돌았는지 여부

int dp(int i,int j, bool dir, bool turn)
{
	if (i == H && j == W) return 1;
	if (i > H || j > W) return 0;

	if (mem[i][j][dir][turn] != -1) return mem[i][j][dir][turn];
	if (dir) // 아래에서 옴
	{
		if (turn) //방금 돌았음
		{
			//위로 진행
			return mem[i][j][dir][turn] = dp(i + 1, j, dir, !turn) % 100000;
		}
		else //돌 수 있음
		{
			//위 + 오른쪽 진행
			return mem[i][j][dir][turn] = (dp(i + 1, j, dir, turn) + dp(i, j + 1, !dir, !turn)) % 100000;
		}
	}
	else // 왼쪽에서 옴
	{
		if (turn) //방금 돌았음
		{
			// 왼쪽 진행
			return mem[i][j][dir][turn] = dp(i, j + 1, dir, !turn) % 100000;
		}
		else //돌 수 있음
		{
			// 위 + 오른쪽 진행
			return mem[i][j][dir][turn] = (dp(i + 1, j, !dir, !turn) + dp(i, j + 1, dir, turn)) % 100000;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> W >> H;
	for (int i = 0; i <= H; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int l = 0; l < 2; l++)
				{
					mem[i][j][k][l] = -1;
				}
			}
		}
	}
	cout << ((dp(2, 1, 1, 0) + dp(1, 2, 0, 0)) % 100000);
	return 0;
}