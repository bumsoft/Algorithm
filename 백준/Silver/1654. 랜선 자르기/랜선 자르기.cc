#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// K개의 길이 다른 랜선
// 같은 길이로 N개를 만들기로 함.
// 이분탐색?
int K;
int N; //1~1'000'000
int arr[10'001]; //1~10'000

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}
	ll start = 1;
	ll end = INT_MAX;
	ll mid;

	int save;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int num = 0;
		for (int i = 0; i < K; i++)
		{
			num += arr[i] / mid;
		}
		if (num < N) //부족한 경우
		{
			end = mid - 1;
		}
		else
		{
			save = mid;
			start = mid+1;
		}
	}
	cout << save;
}