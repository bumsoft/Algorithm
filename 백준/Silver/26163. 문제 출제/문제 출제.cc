#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//난이도 i : 1~5
//출제한 문제수가 3이하일때
// 문제수 * (출제할문제난이도) <=10
// 
//출제한 문제수가 4이상일때
// 문제수 * (출제할문제난이도) <=15

int W[6] = { 0,1,2,3,4,5 };
int V[6];

int arr[6];

int ans;

void backK(int K,int n)
{
	if (n == K)
	{
		int temp_ans = 0;
		for (int i = 1; i <= 5; i++)
		{
			temp_ans += arr[i] * V[i];
		}
		ans = max(ans, temp_ans);
		return;
	}

	for (int i = 1; i <= 5; i++)
	{
		arr[i]++;
		int limit = 0;
		for (int t = 1; t <= 5; t++)
		{
			limit += arr[t] * t;
		}
		if (K<=3&&limit<=10)
		{
			backK(K, n + 1);
		}
		else if (K > 3 && limit <= 15)
		{
			backK(K, n + 1);
		}
		else
		{
			arr[i]--;
			return;
		}
		arr[i]--;
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 5; i++)cin >> V[i];

	for (int i = 1; i <= 15; i++)
	{
		backK(i, 0);
	}
	cout << ans;
}