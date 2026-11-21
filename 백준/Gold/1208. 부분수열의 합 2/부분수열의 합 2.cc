#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, S;
ll ans;
int arr[41];
map<int, int> sum;


void left(int start, int ss)
{
	if (start == N / 2)
	{
		sum[ss]++;
		return;
	}
	//포함X
	left(start + 1, ss);
	//포함O
	left(start + 1, ss + arr[start]);
}
void right(int start, int ss)
{
	if (start == N)
	{
		//ss와 더해서 S가 되는 K. 즉 K+ss == S
		//(left만으로 만들어졌다면 어차피 ss는 0인셈이라 sum[S]에 있음)
		ans += sum[S - ss];
		return;
	}
	right(start + 1, ss);
	right(start + 1, ss + arr[start]);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++)cin >> arr[i];
	left(0, 0);
	right(N / 2, 0);

	if (S == 0)cout << ans - 1;
	else cout << ans;
	return 0;
}