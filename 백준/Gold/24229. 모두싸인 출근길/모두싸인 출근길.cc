//판자에서 갈 수 있는 각각의 최대거리를 통해, 가장 큰 판자를 선택해 이동.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, L, R;
priority_queue<pair<ll, ll>> P;
vector<pair<ll, ll>> V;
vector<ll> v;
//1,000,000,000 10억.
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> L >> R;
		P.push(make_pair(-L, -R));
	}
	ll lll = 0, rr = 0, l, r;
	for (int i = 0; i < N; i++)
	{
		l = -P.top().first;
		r = -P.top().second;
		P.pop();
		if (l <= rr)
		{
			rr = max(r, rr);
		}
		else
		{
			V.push_back(make_pair(lll, rr));
			v.push_back(rr+rr-lll);
			lll = l;
			rr = r;
		}
	}
	V.push_back(make_pair(lll, rr));
	v.push_back(rr + rr - lll);

	int len = v.size();
	int now = 0; //현재 인덱스
	int temp = 0;
	ll tt = V[0].second;
	ll M = v[0];
	bool ck = false;
	while (true)
	{
		ck = false;
		for (int i = now + 1; i < len; i++)
		{
			if (V[i].first <= v[now])
			{
				tt = V[i].second;
				if (M <= v[i])
				{
					ck = true;
					M = v[i];
					temp = i;
				}
			}
			else
			{
				break;
			}
		}
		now = temp;
		if (!ck)break;
	}
	cout << max(V[now].second, tt);
	return 0;

 }