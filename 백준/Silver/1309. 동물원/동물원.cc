#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//크기가 i일때.
// dp[i][0]: i번줄에 0마리 => dp[3]의 합
// dp[i][1]: i번줄에 1마리(왼) => dp[3]의 오른쪽에 배치한경우
// dp[i][2]: i번줄에 1마리(오) => dp[3]의 왼쪽에 배치한 경우

int dp[100'001][3];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][0] %= 9901;
		dp[i][1] %= 9901;
		dp[i][2] %= 9901;
	}
	cout << (dp[N][0] + dp[N][1] + dp[N][2])%9901;

}