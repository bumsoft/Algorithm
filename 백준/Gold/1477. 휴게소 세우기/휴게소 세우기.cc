#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, L;
vector<int> diff;

bool check(int l) // 최대를 l 이하로 만드는 것이 가능한 지 확인
{
	int m = M;
	for (int i = 0; i < diff.size(); i++)
	{
		if (diff[i] <= l) continue;
		else
		{
			for (int j = 2; ; j++)
			{
				int ma;
				if (diff[i] % j == 0)
				{
					ma = diff[i] / j;
				}
				else
				{
					ma = diff[i] / j + 1;
				}
				if (ma > l) continue;
				m -= j-1; break;
			}
			if (m < 0) return false;
		}
	}
	if (m < 0) return false;
	return true;

}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> L;
	int t;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int pre = 0;
	for (int i = 0; i < v.size(); i++)
	{
		diff.push_back(v[i] - pre);
		pre = v[i];
	}
	diff.push_back(L - pre);

	int s = 1;
	int e = L;
	int mid = (s + e) / 2;
	int ans = mid;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (check(mid))
		{
			ans = mid;
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}
	cout << ans;
	return 0;
}