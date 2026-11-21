#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char arr[1'000'001];
//P로 끝나는 개구리와 K로 끝나는 개구리
//PKKKK 4마리
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> arr;
	int P = 0;
	int K = 0;
	int ans = 0;
	for (int i = 0; arr[i]; i++)
	{
		if (arr[i] == 'P')
		{
			if (K)
			{
				K--;
				P++;
			}
			else
			{
				P++;
			}
		}
		else // 'K'
		{
			if (P)
			{
				P--;
				K++;
			}
			else
			{
				K++;
			}
		}
		ans = max({ ans,P,K });
	}
	cout << ans;
}