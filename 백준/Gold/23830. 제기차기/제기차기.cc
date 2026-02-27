#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// score > K + r -> score -= p;
// score < K -> score += q;

// sum(score) >= S 가 되도록 하는 K

// NlogN이 작아서 그냥 각 탐색마다 전체 합 구해도 됨
// 정렬+누적합으로 최적화 가능

int score[100'001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}
	int p, q, r;
	ll S;
	cin >> p >> q >> r >> S;

	int start = 1;
	int end = 100'001;
	int mid;

	int ans = INT_MAX;

	while (start <= end)
	{
		mid = (start + end) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (score[i] > mid + r)
				sum += score[i] - p;
			else if (score[i] < mid) 
				sum += score[i] + q;
			else 
				sum += score[i];
		}
		if (sum < S)
		{
			start = mid + 1;
		}
		else //sum >= S
		{
			end = mid - 1;
			ans = min(ans, mid);
		}
	}
	if (ans == INT_MAX) cout << -1;
	else cout << ans;


	return 0;
}
