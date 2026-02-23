#include <bits/stdc++.h>

using namespace std;

// 재료를 넣으면 끝나는 시간을 분 단위로 계산해줌
// 시작시각과 필요한 시간이 주어졌을 때, 끝나느 시각을 계산해라.

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h, m;
	cin >> h >> m;
	int c;
	cin >> c;

	m += c;
	if (m >= 60)
	{
		h += m / 60;
		m %= 60;
	}
	if (h > 23)
	{
		h %= 24;
	}
	cout << h << ' ' << m;


	return 0;
}