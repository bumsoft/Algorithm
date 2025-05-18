#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, C; //N개의 집, 공유기 C개 설치
// 공유기 사이의 거리를 가능한 크게 설치해서, 가장 인접한 공유기 사이의 거리를 최대로.

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int t; cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	// 사이의 거리 d를 매개변수로 탐색
	// 1 <= d <= 1'000'000'000
	int end = v[N - 1] - v[0];
	int start = 1;
	int mid;

	int ans = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		//사이 최대 거리가 mid이상 되도록 설치하기

		int prev = v[0];
		int num = 1; //설치수 
		for (int i = 1; i < N; i++)
		{
			if (v[i] - prev >= mid)
			{
				num++;
				prev = v[i];
			}
		}
		if (num >= C) // mid이상 간격으로 더 많이 설치 가능하면?
		{
			ans = mid;
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}
	cout << ans;

}

