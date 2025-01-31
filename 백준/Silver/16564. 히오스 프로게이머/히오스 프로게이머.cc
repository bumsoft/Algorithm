#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;

int level[1'000'001];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> level[i];
	}
	sort(level, level + N);
	
	int num = 1; //가장 낮은 레벨의 개수
	int l = level[0]; //현재 가장 낮은 레벨

	for (int i = 1; i < N; i++)
	{
		if (l == level[i])
		{
			num++;
			continue;
		}

		// l num개를 모두 level[i]로 만들 수 있는 경우
		if ((level[i] - l) * num <= K)
		{
			K -= (level[i] - l) * num;
			num++;
			l = level[i];
		}
		// 없는 경우, break;
		else break;
	}

	//남은 K 분배
	l += K / num;
	cout << l;

}