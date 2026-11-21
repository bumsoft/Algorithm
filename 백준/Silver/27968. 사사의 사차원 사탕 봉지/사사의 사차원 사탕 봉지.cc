#include <bits/stdc++.h>
using namespace std;
long long kid[300'001];
long long candy[300'001];
long long sum[300'001];
int N, M;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)	cin >> candy[i];
	for (int i = 0; i < N; i++) cin >> kid[i];
	long long s = 0;
	for (int i = 0; i < M; i++)
	{
		s += candy[i];
		sum[i] = s;
	}

	for (int i = 0; i < N; i++)
	{
		
		int pos = lower_bound(sum, sum + M, kid[i]) - sum;
		if (pos == M)
		{
			cout << "Go away!\n";
			continue;
		}
		else cout << pos+1 << '\n';
	}
	return 0;
}