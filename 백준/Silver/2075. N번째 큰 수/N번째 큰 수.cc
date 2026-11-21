#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//N개 유지하면서, top보다 큰게 들어오면 버리고, 작은게 들어오면 pop하고 push


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, t;
	priority_queue<int> PQ;
	cin >> N;
	cin >> t;
	PQ.push(-t);
	for (int i = 1; i < N * N; i++)
	{
		cin >> t;
		if (PQ.size() == N)
		{
			if (-PQ.top() > t) continue;
			else
			{
				PQ.pop();
				PQ.push(-t);
			}
		}
		else
		{
			PQ.push(-t);
		}
	}
	cout << -PQ.top();

	return 0;
}