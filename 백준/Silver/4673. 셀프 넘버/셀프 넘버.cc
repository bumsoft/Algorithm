#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 1; i <= 10'000; i++)
	{
		int ck = 1;
		for (int j = 1; j < i; j++)
		{
			int a = j / 1000;
			int b = j%1000 / 100;
			int c = j%100 / 10;
			int d = j % 10;
			if (j + a + b + c + d == i)
			{
				ck = 0;
				break;
			}
		}
		if (ck)
		{
			cout << i << '\n';
		}
	}
	return 0;
}