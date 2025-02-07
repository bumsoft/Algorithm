#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[101][101];
//[열][행]
int obstacle[101][101]; //0이면, 왼쪽/아래에서 올 수 있음 //1이면 왼쪽에서만 //2면 아래에서만 //3이면 못옴

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	int a, b, c, d;

	for (int i = 0; i <= N; i++) //0행 i열에 대해
	{
		obstacle[i][0] = 1; //아래는 못오게
	}
	for (int i = 0; i <= M; i++) //i행 0열에 대해
	{
		obstacle[0][i] = 2; //왼쪽은 못오게
	}

	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c >> d;
		if (a + b > c + d) //(a,b)가 더 뒤에 있음
		{
			if (a != c) //좌우 관계
			{
				if (obstacle[a][b] == 0)
				{
					obstacle[a][b] = 2;
					continue;
				}
				if (obstacle[a][b] == 1)
				{
					obstacle[a][b] = 3;
					continue;
				}
			}
			else //상하관계
			{
				if (obstacle[a][b] == 0)
				{
					obstacle[a][b] = 1;
					continue;
				}
				if (obstacle[a][b] == 2)
				{
					obstacle[a][b] = 3;
					continue;
				}
			}
		}
		else //(c,d)가 더 뒤에 있음
		{
			if (a != c)//좌우관계
			{
				if (obstacle[c][d] == 0)
				{
					obstacle[c][d] = 2;
					continue;
				}
				if (obstacle[c][d] == 1)
				{
					obstacle[c][d] = 3;
					continue;
				}
			}
			else //상하관계
			{
				if (obstacle[c][d] == 0)
				{
					obstacle[c][d] = 1;
					continue;
				}
				if (obstacle[c][d] == 2)
				{
					obstacle[c][d] = 3;
					continue;
				}
			}
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i <= N; i++) //열
	{
		for (int j = 0; j <= M; j++) //행
		{
			if (i == 0 && j == 0) continue;
			//0이면, 왼쪽/아래에서 올 수 있음 //1이면 왼쪽에서만 //2면 아래에서만 //3이면 못옴
			if (obstacle[i][j] == 0)
			{
				dp[i][j] += dp[i - 1][j];
				dp[i][j] += dp[i][j - 1];
			}
			if (obstacle[i][j] == 1)
			{
				dp[i][j] += dp[i - 1][j];
			}
			if (obstacle[i][j] == 2)
			{
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	cout << dp[N][M];
}