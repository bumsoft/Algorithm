#include <bits/stdc++.h>
using namespace std;

int N;
int P[200'001];
long long K;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}
	cin >> K;
	long long ans = 0, t;
	for (int i = 0; i < N; i++)
	{
		t = P[i]; 
		if (t > K)break;
		while (K / t != 0)
		{
			ans += K / t;
			t *= P[i];
		}
	}
	cout << ans;
	return 0;
}