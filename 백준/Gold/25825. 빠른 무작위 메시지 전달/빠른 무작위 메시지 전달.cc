#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//선생1 학생 12
// 학생 1번~12번
// 1,2  3,4   5,6  ...  11,12
//임의집단 p에 메시지 전달
// p의 학생 a는 같은 집단 b에게 전달
// b는 전달받지못한 다른 임의집단에 전달

//우선 '집단의 순서' 에 대한 모든 경우의 수

//각 집단에 대해 모든 경우의 수.

int st[13][13];
int selected_group[6];
bool vis[7];
int ans = INT_MAX;
int sel_st[12];
pair<int, int> g[7] = {{ 0,0 }, { 1,2 }, {3, 4}, { 5,6 }, { 7,8 }, { 9,10 }, { 11,12 }};

void in_group(int n,int l)
{
	if (n == 12)
	{
		int temp = 0;
		for (int i = 1; i < 12; i++)
		{
			temp += st[sel_st[i - 1]][sel_st[i]];
		}
	//	cout << '\n';
		ans = min(temp, ans);
		return;
	}

	for (int i = l; i < 6; i++)
	{
		sel_st[n] = g[selected_group[i]].first;
		sel_st[n+1] = g[selected_group[i]].second;
		in_group(n + 2,i+1);
		sel_st[n] = g[selected_group[i]].second;
		sel_st[n+1] = g[selected_group[i]].first;
		in_group(n + 2, i + 1);
		//n += 2;
	}
}

void group(int n)
{
	if (n == 6)
	{
		in_group(0, 0);
		return;
	}
	for (int i = 1; i <= 6; i++)
	{
		if (vis[i])continue;
		selected_group[n] = i;
		vis[i] = true;
		group(n + 1);
		vis[i] = false;
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			cin >> st[i][j];
		}
	}
	group(0);
	cout << ans;
	return 0;
}