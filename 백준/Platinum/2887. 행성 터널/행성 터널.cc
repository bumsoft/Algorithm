//MST 최소 스패닝 트리
//prim algorithm

// 모든 간선의 정보가 필요가 없음!!!!!!!!!!!!!!!

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<pair<ll, int>> PQ;
vector<pair<int, ll>> vertex[100001];

vector<pair<ll, int>> x;
vector<pair<ll, int>> y;
vector<pair<ll, int>> z;
bool vist[100001];
ll ans;
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	long long N, X, Y, Z;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> X >> Y >> Z;
		x.push_back(make_pair(X,i));
		y.push_back(make_pair(Y, i));
		z.push_back(make_pair(Z, i));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	//        가중치,{행성a,행성b}
	for (int i = 0; i < N - 1; i++) {

		vertex[x[i].second].push_back(make_pair(x[i + 1].second, abs(x[i].first - x[i + 1].first)));
		vertex[x[i + 1].second].push_back(make_pair(x[i].second, abs(x[i].first - x[i+1].first)));

		vertex[y[i].second].push_back(make_pair(y[i + 1].second, abs(y[i].first - y[i + 1].first)));
		vertex[y[i + 1].second].push_back(make_pair(y[i].second, abs(y[i].first - y[i+1].first)));

		vertex[z[i].second].push_back(make_pair(z[i + 1].second, abs(z[i].first - z[i + 1].first)));
		vertex[z[i + 1].second].push_back(make_pair(z[i].second, abs(z[i].first - z[i+1].first)));
	}


	//for (int i = 1; i <N; i++)
	//{
	//	for (int j = i + 1;j<N;j++)
	//	{
	//		ll t = min({ abs(get<0>(location[i]) - get<0>(location[j])), abs(get<1>(location[i]) - get<1>(location[j])), abs(get<2>(location[i]) - get<2>(location[j])) });
	//		vertex[i].push_back(make_pair(j, t));
	//		vertex[j].push_back(make_pair(i, t));
	//	}
	//}
	//아무데서나 시작!
	PQ.push(make_pair(0, 1));

	while (!PQ.empty())
	{
		int Ver = PQ.top().second;
		ll Cost = -PQ.top().first;
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