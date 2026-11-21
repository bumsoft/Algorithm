#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
집의 수 m
길의 수 n
n: x y z: x~y 거리z인 양방향 도로

정점 m개
간선 n개.
그래프는 연결그래프
=> 최소신장트리
prim's algo
1. 아무 정점에서나 시작
2. 정점에서 가장 가중치 작은 정점선택해 잇기
3. 이어진 정점 중 가장 가중치 작은 정점 잇기
4. 모든 정점이 선택될 때 까지 반복

출력: (가중치 합) - (mst가중치합)
*/
bool vis[200'000];
int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, n;
	while (cin >> m >> n)
	{
		if (m == 0)
		{
			return 0;
		}

		for (int i = 0; i < m; i++)
		{
			vis[i] = 0;
		}

		vector<pair<int, int>> E[200'000]; //<연결된정점, 거리>
		int x, y, z;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> z;
			E[x].push_back({ y,z });
			E[y].push_back({ x,z });
			sum += z;
		}
		/*
		prim's algo
		1. 아무 정점에서나 시작
		2. 정점에서 가장 가중치 작은 정점선택해 잇기
		3. 이어진 정점 중 가장 가중치 작은 정점 잇기
		4. 모든 정점이 선택될 때 까지 반복
		*/
		priority_queue<pair<int, int>> PQ; //<거리, 갈 정점>
		PQ.push({ 0,0 }); //0번집 시작
		int cnt = 0;
		int c = 0;
		while (!PQ.empty())
		{
			int house = PQ.top().second; //PQ에서 꺼내는순간 정점을 선택하는 것.
			int cost = -PQ.top().first;
			PQ.pop();
			if (vis[house]) continue;
			vis[house] = 1;
			c += cost;
			cnt++;
			if (cnt == m) break;
			for (int i = 0; i < E[house].size(); i++)
			{
				if (vis[E[house][i].first]) continue;

				PQ.push({ -E[house][i].second, E[house][i].first });
			}
		}
		cout << sum - c << '\n';
	}
	
	

	return 0;
}