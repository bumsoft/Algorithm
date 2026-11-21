#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string A, B;
int dp[1001][1001];

void sol(int a,int b)
{
	if (dp[a][b] == 0)return;

	if (A[a - 1] == B[b - 1])
	{
		sol(a - 1, b - 1);
		cout << A[a - 1];
	}
	else
	{
		if (dp[a - 1][b] > dp[a][b - 1])
		{
			sol(a - 1, b);
		}
		else sol(a, b - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> A >> B;
	int a = A.length();
	int b = B.length();
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (A[i] == B[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	cout << dp[a][b] << '\n';
	sol(a, b);
}