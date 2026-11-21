#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
map<string, int> mp;
string arr[100'001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	string t;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		mp.insert({ arr[i],i });
	}
	string tt;
	for (int i = 0; i < M; i++)
	{
		cin >> tt;
		if (tt[0] >= '0' && tt[0] <= '9')
		{
			cout << arr[stoi(tt)] << '\n';
		}
		else
		{
			cout << mp[tt] << '\n';
		}
	}
	return 0;
}