#include <bits/stdc++.h>
using namespace std;
int T;
int t[501][501];
int mem[501][501];

int dp(int I, int J)
{
	if (I == T) return 0;
	if (mem[I][J] != 0) return mem[I][J];

	return mem[I][J] = (dp(I + 1, J) >= dp(I + 1, J + 1) ? dp(I + 1, J) : dp(I + 1, J + 1)) + t[I][J];
}



int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> t[i][j];
		}
	}
	cout<<dp(0, 0);

	return 0;
}