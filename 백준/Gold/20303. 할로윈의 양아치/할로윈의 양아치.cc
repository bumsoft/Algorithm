#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int root[30'001];

int candy[30'001];

int find_parent(int x)
{
	if (x == root[x]) return x;
	return root[x] = find_parent(root[x]);
}

int union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) return a;

	if (a < b) return root[b] = a;
	else return root[a] = b;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) root[i] = i;

	// 사탕 수 입력
	for (int i = 1; i <= N; i++)
	{
		cin >> candy[i];
	}

	// 친구관계 입력
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		union_parent(a, b);
	}
	map<int, pair<int,int>> m; //루트번호, <사람수,사탕수>
	for (int i = 1; i <= N; i++)
	{
		int r = find_parent(i);
		m[r].first++;
		m[r].second += candy[i];
	}
	vector<pair<int, int>> v; //<사람수, 사탕수>
	for (auto it = m.begin(); it != m.end(); it++)
	{
		v.push_back(it->second);
		//cout << "사람수: " << it->second.first << " 사탕수: " << it->second.second << '\n';
	}
	// v로 배낭문제 풀기
	vector<int> dp(K+1);
	
	for (int i = 0; i <v.size(); i++)
	{
		int kids = v[i].first;
		int candys = v[i].second;
		for (int j = K; j >= 0; j--)
		{
			if (j - kids < 0) continue;
			dp[j] = max(dp[j], dp[j - kids] + candys);
		}
	}
	int ans = 0;
	for (int i = 0; i < K; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;


	return 0;
}
