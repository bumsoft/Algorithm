#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 각 사람마다 Li 미만 부족, Ri 초과 천국

// 사람 i는 Li<= <=Ri 의 술을 받음
// 모든 사람의 술 총합 T
// 모든 사람은 S를 초과하는 술을 받지 않음'
// T = ? S=5
// A는 최소 2 최대 6
// B는 최소 6 최대 30
// => S=6
// 최대로 주면 36
// 최소로 주면 8
// 이 사이로 주면 무조건 가능한가?
// S일때,
// 1. S값이 모든 L보다 큰가?
// 2. 최대 S로 줬을 때, 딱 T를 맞출 수 있는가? 
// -> 모두 S로 줄 때, 각 사람의 잉여값의 합 해당 값 => 최대 N*S를 줄건데, 잉여값 합만큼은 안마셔도 됨. (잉여합, 못먹합)
// 즉  (N*S - 잉여합) <= T <= (N*S- 못먹합) 범위여야한다.

int arr[1001][2];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, T; cin >> N >> T;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	//1'000'000'000
	int ans = INT_MAX;
	int start = 1;
	int end = 1'000'000;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int sum = 0;
		int mot = 0;

		bool more = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i][0] > mid)
			{
				more = 1;
				break;
			}
			if (mid > arr[i][0])
			{
				sum += mid - arr[i][0]; // 빼도 되는 합
			}
			if (mid > arr[i][1])
			{
				mot += mid - arr[i][1]; //빼야하는 합
			}
		}
		if (more)
		{
			start = mid + 1;
			continue;
		}

		if (mid * N - sum <= T && T <= mid * N - mot)
		{
			ans = min(mid, ans);
			end = mid - 1;
			continue;
		}
		start = mid + 1;
	}


	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}
