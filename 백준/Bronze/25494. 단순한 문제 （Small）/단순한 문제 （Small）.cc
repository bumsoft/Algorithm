#include <iostream>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c, T, ans;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		ans = 0;
		cin >> a >> b >> c;
		for (int aa = 1; aa <= a; aa++)
		{
			for (int bb = 1; bb <= b; bb++)
			{
				for (int cc = 1; cc <= c; cc++)
				{
					if ((aa % bb == bb % cc) && (bb % cc == cc % aa)) ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
