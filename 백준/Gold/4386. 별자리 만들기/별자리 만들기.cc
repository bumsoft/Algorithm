#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<pair<double, int>> PQ;
int N;
vector<pair<double, double>> v;
bool vis[101];
vector<pair<double, int>> vertex[101]; //가중치와 정점번호

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	double x, y;
	v.push_back({ 0,0 });
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		v.push_back({x,y});
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double X = abs(v[i].first - v[j].first);
			double Y = abs(v[i].second - v[j].second);
			vertex[i].push_back({sqrt(X * X + Y * Y), j});
			vertex[j].push_back({sqrt(X * X + Y * Y), i});
		}
	}
	for (int i = 0; i < vertex[1].size(); i++)
	{
		PQ.push({ -vertex[1][i].first,vertex[1][i].second});
	}
	vis[1] = true;
	double ans = 0;
	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		double Cost = -PQ.top().first;
		PQ.pop();
		if (vis[Ver]) continue;
		vis[Ver] = true;
		ans += Cost;
		for (int i = 0; i < vertex[Ver].size(); i++)
		{
			if (vis[vertex[Ver][i].second])continue;
			PQ.push({ -vertex[Ver][i].first,vertex[Ver][i].second });
		}
	}
	cout << ans;
	return 0;
}