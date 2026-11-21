#include <bits/stdc++.h>
using namespace std;

long mem[1000001];

int dp(int n)
{
	if (n == 0)return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 2;

	if (mem[n] != 0) return mem[n];
	return mem[n] = dp(n - 1) % 1000000007 + dp(n - 2) % 1000000007;
}

int main()
{
	int N;
	cin >> N;
	cout << dp(N) % 1000000007;
	return 0;
}