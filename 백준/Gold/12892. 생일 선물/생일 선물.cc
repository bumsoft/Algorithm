#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, D;
//물건을 선물가격순으로 정렬

vector<pair<ll, ll>> v; // <가격,만족도>
vector<ll> sum; // 가치의 누적합
vector<ll> price;
ll ans;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> D;
	ll a, b;
	for (int i = 1; i <= N; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
		price.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(price.begin(), price.end());

	sum.push_back(v[0].second);
	for (int i = 1; i < v.size(); i++)
	{
		sum.push_back(sum[i-1] + v[i].second);
	}
	
	for (int i = 0; i < v.size(); i++) //i번째 물건을 골랐을 때
	{
		// v[k].first - v[i].first < D 이어야한다. D미만으로 차이
		// v[k].first < D+v[i].first 인 k값 찾기
		int index = lower_bound(price.begin(), price.end(), v[i].first + D) - price.begin();
		index--;
		if (price[i] + D < price[index])continue;

		if (i == 0) ans = max(ans, sum[index]);
		else ans = max(ans, sum[index] - sum[i-1]);
	}
	cout << ans;
	return 0;
}