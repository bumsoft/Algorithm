#include <bits/stdc++.h>
using namespace std;
int mmin = 2'100'000'000;

//치킨집 선택하며 백트레킹.
//다 고른다음, 도시 치킨거리 구하고 min갱신해주기

pair<int, int> house[100];
pair<int, int> chicken[13];
int tempHarr[100];
bool chosenChicken[13];
int h, ck; //집과 치킨 개수

void rree(int m,int w) //선택해야하는 치킨집 수/어느 치킨집부터 볼지
{
	if (m == 0)//다골랐으면
	{
		int c = 0;
		for (int i = 0; i < ck; i++)
		{
			if (chosenChicken[i])
			{
				c++;
				int a = chicken[i].first;
				int b = chicken[i].second;
				for (int j = 0; j < h; j++)
				{
					int t = abs(house[j].first - a) + abs(house[j].second - b);
					if (c==1)
					{
						tempHarr[j] = t;
						continue;
					}
					if (tempHarr[j] > t)
					{
						tempHarr[j] = t;
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < h; i++)
		{
			sum += tempHarr[i];
		}
		if (sum < mmin) mmin = sum;
		return;
	}

	for (int i = w; i < ck; i++)
	{
		chosenChicken[i] = true;
		rree(m - 1, i + 1);
		chosenChicken[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, t;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> t;
			if (t == 0) continue;
			if (t == 1) house[h++] = make_pair(i, j);
			else chicken[ck++] = make_pair(i, j);
		}
	}
	rree(M,0);
	cout << mmin;
	return 0;
}