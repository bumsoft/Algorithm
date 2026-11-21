#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, T, K, S, E;

ll sum[200'001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> T;
	int emax = 0;
	while (N--)
	{
		cin >> K;
		while (K--)
		{
			cin >> S >> E;
			sum[S]++;
			sum[E]--;
			emax = max(emax, E);
		}
	}
	for (int i = 1; i <= emax; i++)
	{
		sum[i] += sum[i - 1];
	}
	//for (int i = 0; i <= emax; i++)
	//{
	//	cout << i << "전까지 사람수:" << sum[i] << '\n';
	//}
	ll Max = 0;
	for (int i = 0; i < T; i++)
	{
		Max += sum[i];
	}
	int st = 0;
	int en = T;
	//for (int i = 0; i <= emax; i++)
	//{
	//	cout << sum[i] << ' ';
	//}
	//cout << '\n';
//	int z = 0;
	ll temp = Max;
	//cout << z<<"~ seg:" << Max << '\n';
	for (int i = 1; i <= emax+10-T; i++)
	{
		//cout << i << "~seg:" << temp - sum[i - 1] + sum[i + T] << '\n';
		//if (Max < temp - sum[i - 1] + sum[i + T])
		temp = temp - sum[i - 1] + sum[i + T-1];
		if(Max<temp)
		{
	//		cout << i << '\n';
			Max = temp;
			st = i;
			en = T + i;
		}
	}
	cout << st << ' ' << en;
	return 0;
}