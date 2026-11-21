#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//배열의 뒤에 수를 N번 추가
// 추가할 때마다 1<=i<=j<=len(N)를 만족하는 정수 i j에 대해 A[j]-A[i]의 최대값을 구하려고 한다.

//dp로 ㄱㄱ

//dp 후 dp[1]~dp[N]까지 출력하면 됨

ll Min[200'001];//i까지 중 가장 작은값 (A[i]로 쓸거임)
ll dp[200'001];
ll arr[200'001];
int N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		if (i == 1)Min[i] = arr[i];
		else
		{
			Min[i] = min(Min[i-1], arr[i]);
		}
	}
	//
	for (int i = 1; i <= N; i++)
	{
		//i에서의 최대 : i-1 값을 가져오거나, i번째를 포함시킨 값 중 큰 값.
		dp[i] = max(dp[i - 1], arr[i] - Min[i]);
	}
	//
	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << ' ';
	}
}