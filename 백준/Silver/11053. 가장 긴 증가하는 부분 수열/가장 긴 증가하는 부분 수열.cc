#include <bits/stdc++.h>
using namespace std;
int ls[1001];
int mem[1001];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N;i++)
	{
		cin >> ls[i];
	}


	for (int n = 1; n<=N; n++)
	{
		if (n == 1)
		{
			mem[n] = 1;
			continue;
		}
		int _max = 1;
		for (int i = 1; i < n; i++)
		{
			if (ls[i] < ls[n])
			{
				_max = max(_max, mem[i] + 1);
			}
		}
		mem[n] = _max;
	}
	int max_ = 0;
	for (int i = 1; i <= N; i++)
	{
		max_ = max(mem[i], max_);
	}
	cout << max_;
	return 0;
}