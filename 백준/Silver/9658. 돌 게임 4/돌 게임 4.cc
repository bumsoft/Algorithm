#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

bool dp[1001]; //상근이 기준, 승패여부


// 1 3 4개 가져갈 수 있음.
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	dp[0] = true;
	dp[1] = false;
	dp[2] = true;
	dp[3] = false;
	dp[4] = true; // 나에게 false인 dp[3]을 줄 수 있음
	dp[5] = true; // 나에게 false인 dp[1]을 줄 수 있음
	
	for (int i = 6; i <= N; i++)
	{
		if (dp[i - 1] == false || dp[i - 3] == false || dp[i - 4] == false)
		{
			dp[i] = true;
		}
		else dp[i] = false;
	}
	cout << (dp[N] ? "SK" : "CY");
}