#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[1001];
int T, W;

int mem[1001][31][3];

int backTracking(int s, int w, int loc)
{
	if (w == W)
	{
		int r = 0;
		for (int i = s; i <= T; i++)
		{
			if (arr[i] == loc) r++;
		}
		return r;
	}
	if (s > T) return 0; 

	if (mem[s][w][loc] != -1) return mem[s][w][loc];
	int add = 0;
	if (arr[s] == loc) add++;

	int cloc = loc == 1 ? 2 : 1;
	return mem[s][w][loc] = max(backTracking(s + 1,w,loc) + add, backTracking(s + 1, w + 1, cloc) + add);
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i <= T; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			for (int k = 0; k <= 3; k++)
			{
				mem[i][j][k] = -1;
			}
		}
	}
	cout<<max(backTracking(1, 0, 1), backTracking(1, 1, 2));

}