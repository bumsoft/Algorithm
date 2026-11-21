#include <iostream>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, n, m, ans; double t;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		ans = 0;
		cin >> n >> m;
		for (int b=2;b<n;b++)
		{
			for (int a=1;a<b;a++)
			{
				t = (double)(a * a + b * b + m) / (a * b);
				if (t == (int)t) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
