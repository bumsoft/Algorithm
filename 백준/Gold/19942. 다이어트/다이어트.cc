#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int mini[4];

int ingre[16][5];

bool vis[16];
int ans = INT_MAX;
vector<int> save;
void backTracking(int start)
{
	if (start > N)
	{
		int a = 0, b = 0, c = 0, d = 0, cost = 0;
		vector<int> temp;
		for (int i = 1; i <= N; i++)
		{
			if (vis[i])
			{
				a += ingre[i][0];
				b += ingre[i][1];
				c += ingre[i][2];
				d += ingre[i][3];
				cost += ingre[i][4];
				temp.push_back(i);
			}
		}
		if (a >= mini[0] && b >= mini[1] && c >= mini[2] && d >= mini[3])
		{
			if (ans > cost) 
			{
				save = temp; 
				ans = cost;
			}
			if (ans == cost)
			{
				//save와 temp의 사전 순 비교 후 갱신!
				int l = 0;
				int e = min(save.size(), temp.size()); //e-1까지 보기
				while (true)
				{
					if (l == e)
					{
						save = save.size() > temp.size() ? temp : save;
						break;
					}
					if (save[l] < temp[l])
					{
						break;
					}
					if (save[l] > temp[l])
					{
						save = temp;
					}
					l++;
				}
			}
		}
		return;
	}

	vis[start] = true;
	backTracking(start + 1);
	vis[start] = false;
	backTracking(start + 1);
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	//cout << pow(2, 15); => 30000 브루트포스 가능

	cin >> N;
	cin >> mini[0] >> mini[1] >> mini[2] >> mini[3];

	for (int i = 1; i <= N; i++)
	{
		cin >> ingre[i][0] >> ingre[i][1] >> ingre[i][2] >> ingre[i][3] >> ingre[i][4];
	}
	backTracking(1);
	if (ans == INT_MAX)
	{
		cout << -1;
		return 0;
	}

	cout << ans << '\n';
	for (int i = 0; i < save.size(); i++)
	{
		cout << save[i] << ' ';
	}
	return 0;
}