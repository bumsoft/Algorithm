#include <bits/stdc++.h>
using namespace std;
int ans;
int temp;
int main()
{
	int H, W;
	bool c = false;
	cin >> H >> W;
	vector<int> M(W);
	for (int i = 0; i < W; i++)
	{
		cin >> M[i];
	}
	//end_input
	
	for (int i = 1; i <= H; i++)
	{
		c = false;
		temp = 0;
		for (int j = 0; j < W; j++)
		{
			if (!c && i <= M[j])
			{
				c = true;
				//ans += temp;
				//temp = 0;
				continue;
			}
			if (c && i > M[j])
			{
				temp++;
				continue;
			}
			if (c && i <= M[j])
			{
				ans += temp;
				temp = 0;
				c = true;
			}
		}
	}
	cout << ans;
	return 0;
}