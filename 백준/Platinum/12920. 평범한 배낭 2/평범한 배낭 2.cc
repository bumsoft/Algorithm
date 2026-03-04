#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// bounded 배낭

vector<ll> W; // 무게
vector<ll> V; //만족도
int C[101]; //개수

ll dp[10'001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int w, c;
		cin >> w >> c >> C[i];
		W.push_back(w);
		V.push_back(c);
	}
	// 아이템을 1-2-4-...개로 분할
	for (int i = 0; i < N; i++)
	{
		ll weight = W[i];
		ll value = V[i];
		int cnt = C[i];
		int t = 1;
		while (cnt >= t)
		{
			cnt -= t;
			ll new_weight = weight * t;
			ll new_value = value * t;
			t *= 2;
			if (t/2 == 1) continue;
			W.push_back(new_weight);
			V.push_back(new_value);
		}
		if (cnt > 0)
		{
			ll new_weight = weight * cnt;
			ll new_value = value * cnt;
			W.push_back(new_weight);
			V.push_back(new_value);
		}
	}
	// 0/1 배낭 진행
	for (int i = 0; i < W.size(); i++)
	{
		for (ll j = M; j >= 0; j--)
		{
			if (j - W[i] < 0) continue;
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= M; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
