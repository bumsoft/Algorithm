#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M; // N명의 학생에게 M가지 서로 다른 보석을 나눠줌
// 못받는 학생 있을 수도, 학생은 항상 같은 색상 보석을 가짐
//질투심: 가장 많이 가져간 보석 수가 최소가 되도록.

int arr[300'001]; //색상 개수
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}

	int start = 1;
	int end = 10'000'000'000;
	int mid;
	int ans = 0;
	while (start <= end)
	{
		mid = (start + end) / 2; //한 명이 가지는 최대 수가 mid가 되도록
		int cnt = 0;
		for (int i = 0; i < M; i++)
		{
			cnt += arr[i] / mid;
			if (arr[i] % mid != 0) cnt++;
		}

		if (cnt <= N) // mid를 감소시켜도 됨
		{
			end = mid - 1;
			ans = mid;

		}
		else // mid 증가
		{
			start = mid + 1;
		}
	}
	cout << ans;

	return 0;
}
