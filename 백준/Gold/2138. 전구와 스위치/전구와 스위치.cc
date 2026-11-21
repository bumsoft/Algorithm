
#include <bits/stdc++.h>
#define min(a,b) a<b?a:b
using namespace std;
char pre[100001];
char last[100001];
bool l[100001];
bool ll[100001];
int N;
int ans;
int ans2;
void cal(int a, bool l[]) //a, a+1, a+2를 바꿔야함
{
	if (a + 2 == N)
	{
		if (l[a]) l[a] = false;
		else l[a] = true;

		if (l[a + 1]) l[a+1] = false;
		else l[a+1] = true;
	}
	else
	{
		l[a] = true;

		if (l[a + 1]) l[a+1] = false;
		else l[a+1] = true;

		if (l[a + 2]) l[a+2] = false;
		else l[a+2] = true;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> pre[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> last[i];
	}
	//같은경우
	if(memcmp(pre,last,sizeof(pre))==0)
	{
		cout << 0;
		return 0;
	}
	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	//if (N == 2)
	//{
	//	if((pre[0]+pre[1]))
	//}
	for (int i = 0; i < N; i++)
	{
		ll[i] = l[i] = (pre[i] == last[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1 && !l[i])
		{
			ans = 2100000000;
			break;
		}
		else if (!l[i])
		{
			cal(i,l);
			ans++;
		}
	}
	if (ll[0]) ll[0] = false;
	else ll[0] = true;
	if (ll[1])ll[1] = false;
	else ll[1] = true;
	ans2++;
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1 && !ll[i])
		{
			ans2 = 2100000000;
			break;
		}
		else if (!ll[i])
		{
			cal(i,ll);
			ans2++;
		}
	}
	if (ans==2100000000&&ans==ans2)
	{
		cout << -1;
		return 0;
	}
	int k = min(ans, ans2);
	cout << k;
	return 0;
}