//MST 최소 스패닝 트리
//prim algorithm

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2'100'000'000
priority_queue<pair<ll, int>> PQ;
vector<pair<int, ll>> vertex[10001];
bool vist[10001];
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int V, E, A, B; 
	ll C, ans = 0;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		vertex[A].push_back(make_pair(B, C));
		vertex[B].push_back(make_pair(A, C));
	}
	//아무데서나 시작!
	PQ.push(make_pair(0, 1));

	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		int Cost = -PQ.top().first;
		PQ.pop();
		if (vist[Ver]) continue;//MST에 추가돼있는거면 패스
		vist[Ver] = true;
		ans += Cost;
		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			if (vist[vertex[Ver][i].first]) continue; //MST에 추가돼있는거면 패스
			PQ.push(make_pair(-vertex[Ver][i].second, vertex[Ver][i].first));
		}
	}
	cout << ans;

	return 0;
}