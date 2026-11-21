#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N: 2~500'000

int N, Q;
vector < pair<int, pair<ll, ll>>> vertex[500'001];
bool vis[500'001];
// first가 작은순. 같다면 second가 작은순 힙
struct Compare {
	bool operator()(const pair<ll, pair<ll,int>>& p1, const pair<ll, pair<ll,int>>& p2) const 
	{
		if (p1.first == p2.first)
		{
			return p1.second.first > p2.second.first;
		}
		return p1.first > p2.first;
	}
};

priority_queue<pair<ll,pair<ll,int>>,vector<pair<ll,pair<ll,int>>>, Compare> PQ; // {Cost{Time,Ver}}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> Q;
	int from, to;
	ll cost, time;
	for (int i = 0; i < Q; i++)
	{
		cin >> from >> to >> cost >> time;
		vertex[from].push_back({ to,{cost,time} });
		vertex[to].push_back({ from,{cost,time} });
	}
	// {Cost{Time,Ver}}
	PQ.push({ 0,{0,1} });
	int num = 0;
	ll t = -1;
	ll c = 0;

	while (!PQ.empty())
	{
		if (num >= N)break;
		int Ver = PQ.top().second.second;
		ll Cost = PQ.top().first;
		ll Time = PQ.top().second.first;
		PQ.pop();
		if (vis[Ver]) continue;
		vis[Ver] = !vis[Ver];
		num++;
		c += Cost;
		t = max(Time, t);
		int l = vertex[Ver].size();
		for (int i = 0; i < l; i++)
		{
			if (vis[vertex[Ver][i].first])continue;
			PQ.push({ vertex[Ver][i].second.first,{vertex[Ver][i].second.second,vertex[Ver][i].first} });
		}
	}
	if (num < N)
	{
		cout << -1;
	}
	else
	{
		cout << t << ' ' << c;
	}
	return 0;
}