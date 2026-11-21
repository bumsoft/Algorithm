#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//백트래킹?
// 
// 장소:수족관 시청 학교
// 임무:정보수집 감시
// 
// 하루 한 장소에서 한 가지 임무수행
// 하루에 최소 하나 수행
// 수행시 완수를 위한 진척도 얻음
// 전날과 같은 곳에서 수행시 전척도/2
// M이상의 기여도를 얻을 수 있는 수행방법의 가짓수

int N, M;
int ans;
pair<char, int> arr[6];

pair<char, int> selected[8];

void re(int n)
{
	if (n == N)
	{
		int sum = selected[0].second;
		char prev = selected[0].first;
		for (int i = 1; i < N; i++)
		{
			if (selected[i].first == prev)
			{
				sum += selected[i].second / 2;
			}
			else
			{
				sum += selected[i].second;
				prev = selected[i].first;
			}
		}
		if (sum >= M)ans++;
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		selected[n] = arr[i];
		re(n + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	char t = 'a';
	int tt;
	for (int i = 0; i < 3; i++)
	{
		cin >> tt;
		arr[i] = { t++,tt };
	}
	t = 'a';
	for (int i = 3; i < 6; i++)
	{
		cin >> tt;
		arr[i] = { t++,tt };
	}
	re(0);
	cout << ans;
	return 0;
}