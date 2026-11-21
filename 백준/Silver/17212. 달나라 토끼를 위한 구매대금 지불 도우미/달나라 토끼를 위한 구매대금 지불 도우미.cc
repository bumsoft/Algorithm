#include <iostream>
//1 2 5 7

using namespace std;

int mem[100001];

int dp(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 2;
	if (n == 4) return 2;
	if (n == 5) return 1;
	if (n == 6) return 2;
	if (n == 7) return 1;

	if (mem[n] != 0) return mem[n];

	return mem[n]=((dp(n - 1) < dp(n - 2) ? dp(n - 1) : dp(n - 2)) > (dp(n - 5) < dp(n - 7) ? dp(n - 5) : dp(n - 7)) ? (dp(n - 5) < dp(n - 7) ? dp(n - 5) : dp(n - 7)) : (dp(n - 1) < dp(n - 2) ? dp(n - 1) : dp(n - 2))) + 1;
}

int main()
{
	int N; cin >> N;
	cout<<dp(N);
	return 0;
}