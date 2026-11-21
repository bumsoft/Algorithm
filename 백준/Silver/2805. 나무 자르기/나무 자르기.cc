#include <bits/stdc++.h>
using namespace std;
int N, M;
long long arr[1'000'001];
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	long long low = 0, high = 2'000'000'000;
	long long mid;
	long long sum = 0;
	while (low<high)
	{
		sum = 0;
		mid = (low + high+1) / 2;
		for (int i = 0; i < N; i++)
		{
			if(arr[i]-mid>0) sum += arr[i] - mid;
		}
		if (sum >= M) //더 큰쪽으로
		{
			low = mid;
		}
		else //더 작은쪽으로
		{
			high = mid-1;
		}
		mid = (low + high + 1) / 2;
	}
	cout << mid;

	return 0;
}