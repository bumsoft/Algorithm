#include <bits/stdc++.h>
using namespace std;

int ans=0;
int N;
int r, c;
bool _find;
void z(int n, int rr, int cc)
{
	if (rr == r && cc == c)
	{
		_find = true;
		return;
	}
	else if ((rr <= r && r < (rr + n)) && (cc <= c && c < (cc + n))) //지금 보고있는 것 안에 있는 경우
	{
		z(n / 2, rr, cc);

		z(n / 2, rr, cc + n / 2);

		z(n / 2, rr + n / 2, cc);

		z(n / 2, rr + n / 2, cc + n / 2);
	}
	else if (_find) return;
	else
	{
		ans += n * n;
	}
}


int main()
{
	cin >> N >> r >> c;
	z(pow(2, N), 0, 0);
	cout << ans;
	return 0;
}