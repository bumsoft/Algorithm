#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N; //스태프 수
int M; //M개의 풍선 만들기

ll A[1'000'001]; //스태프당 풍선 만드는 시간


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> A[i];

	// mid분 동안 만들 수 있는 풍선의 최대 개수
	ll start = 1;
	ll end = 1'000'000'000'000;
	ll mid;
	ll ans = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		ll cnt = 0;
		for (int i = 0; i < N; i++)
		{
			cnt += mid / A[i];
		}
		if (cnt >= M)
		{
			end = mid - 1;
			ans = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << ans;


	return 0;
}
