#include <bits/stdc++.h>
using namespace std;

int n,sum;
vector<pair<int, int>> v; //p d
bool visit_[10001];
bool compare(pair<int, int>a, pair<int, int>b)
{
	return a.first >= b.first; //금액순으로 정렬
}



int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int p, d;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back(make_pair(p, d));
	}
	sort(v.begin(), v.end(), compare);

	//p가 큰거부터 보면서, 원소별 가장 늦게 갈 수 있는 날에 넣음
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i].second; j >= 1; j--) //안비어있으면 하루씩 줄이면서
		{
			if (!visit_[j])//비어있다면
			{
				visit_[j] = true;
				sum += v[i].first;
				break;
			}
		}
	}
	cout << sum;

	return 0;
}