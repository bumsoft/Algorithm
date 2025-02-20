#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

bool dp[1001]; //상근이 기준, 승패여부


// 1 3개 가져갈 수 있음.
// 마지막 가지면 이김!
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;
	dp[4] = false;
	
	for (int i = 5; i <= N; i++)
	{
		if (dp[i - 1] == false || dp[i - 3] == false)
		{
			dp[i] = true;
		}
		else dp[i] = false;
	}
	cout << (dp[N] ? "SK" : "CY");
}