#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int S, m, n;
int A[2001];
int B[2001];
int sum[2'000'001];
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> S >> m >> n;
	int ans = 0;
	int aSum = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> A[i];
		A[i + m] = A[i];
		aSum += A[i];
	}
	int bSum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
		B[i + n] = B[i];
		bSum += B[i];
	}

	for (int i = 0; i < m; i++)
	{
		int t = 0;
		for (int j = i; j < i+m; j++)
		{
			t += A[j];
			sum[t]++;
		}
	}
	sum[aSum] = 1;

	for (int i = 0; i < n; i++)
	{
		int t = 0;
		for (int j = i; j < i + n - 1; j++)
		{
			t += B[j];
			if (S - t > 0) ans += sum[S - t];
			if (S == t) ans++;
		}
	}
	if (bSum == S) ans++; //B 한판 주는 경우
	if (bSum + aSum == S) ans++; //A B 두판 주는 경우

	if(S -bSum > 0) ans += sum[S - bSum];

	ans += sum[S]; //A만 사용
	cout << ans;

	return 0;
}