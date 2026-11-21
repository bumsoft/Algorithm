#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//버터가 섞이지 않는 최대 시간
//붙어있는 버터들을 보면서, 섞이는 시간을 갱신(min)

int N;
vector<pair<int, int>> v;
bool cal(int x1, int x2, int t, int a, int b)
{
	if (x1 + (a<t?a:t) < x2 - (b<t?b:t)) return true;
	return false;
}
int search(int start, int end, int x1, int x2, int a, int b)
{
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (cal(x1, x2, mid, a, b))
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int x, h;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> h;
		v.push_back({ x,h });
	}
	if (N == 1)
	{
		cout << "forever";
		return 0;
	}
	sort(v.begin(), v.end());
	int ans = INT_MAX;
	for (int i = 0; i < N - 1; i++)
	{
		int temp = search(0, (v[i].second/2>v[i+1].second/2?v[i].second/2:v[i+1].second/2), v[i].first, v[i + 1].first, v[i].second / 2, v[i + 1].second / 2);
		if(temp == (v[i].second / 2 > v[i + 1].second / 2 ? v[i].second / 2 : v[i + 1].second / 2)) temp = INT_MAX;
		ans = min(ans, temp);
		
	}
	
	if (ans == INT_MAX)
	{
		cout << "forever";
	}
	else
	{
		cout << ans;
	}
	return 0;
}