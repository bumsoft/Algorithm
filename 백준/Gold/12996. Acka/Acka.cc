#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int S, A, B, C;

ll mem[51][51][51][51];

ll dp(int n, int a, int b, int c)
{
	if (a > A || b > B || c > C) return 0;
	if (n == S)
	{
		if (a == A && b == B && c == C) { return mem[n][a][b][c] = 1; }
		else return 0;
	}

	if (mem[n][a][b][c] != -1) return mem[n][a][b][c];

	mem[n][a][b][c] = dp(n + 1, a+1, b, c) % 1000000007;
	mem[n][a][b][c] += dp(n + 1, a+1, b+1, c) % 1000000007;
	mem[n][a][b][c] += dp(n + 1, a+1, b, c+1) % 1000000007;
	mem[n][a][b][c] += dp(n + 1, a+1, b+1, c+1) % 1000000007;

	mem[n][a][b][c] += dp(n + 1, a, b+1, c) % 1000000007;
	mem[n][a][b][c] += dp(n + 1, a, b+1, c+1) % 1000000007;

	mem[n][a][b][c] += dp(n + 1, a, b, c+1) % 1000000007;

	return mem[n][a][b][c] % 1000000007;
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> S >> A >> B >> C;
	for (int i = 0; i <= S; i++)
	{
		for (int j = 0; j <= A; j++)
		{
			for (int k = 0; k <= B; k++)
			{
				for (int l = 0; l <= C; l++)
				{
					mem[i][j][k][l] = -1;
				}
			}
		}
	}

	cout<<dp(0, 0, 0, 0);

	return 0;
}