#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[100'001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	priority_queue<int> PQ;
	int N; cin >> N;
	int t;
	while (N--)
	{
		cin >> t;
		if (t == 0)
		{
			if (PQ.empty()) cout << 0 << '\n';
			else
			{
				cout << - PQ.top() << '\n';
				PQ.pop();
			}
		}
		else
		{
			PQ.push(-t);
		}
	}

	return 0;
}