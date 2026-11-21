#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime[10'000'001];//false:소수 true:소수x

int is_ans[10'000'001]; // is_ans[i] : i 이하의 최대 합성소수를 저장함


bool func(int p)
{
	string s = to_string(p);
	int l = s.length();
	
	for (int i = 0; i < l - 1; i++) //i일때
	{
		if (i == 0)
		{
			for (int j = l - 1 - i; j >= 2; j--)//i~i+j자름
			{
				if (is_prime[stoi(s.substr(i, j))])
				{
					return false;
				}
			}
		}
		else
		{
			for (int j = l - i; j >= 2; j--)//i부터 j개 자름
			{
				if (is_prime[stoi(s.substr(i, j))])
				{
					return false;
				}
			}
		}
	}
	return true;
}

// 31373
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 2; i <= 10'000'000; i++)
	{
		if (!is_prime[i])
		{
			int t = 2;
			while (t * i < 10'000'000)
			{
				is_prime[i * t++] = true;
			}
		}
	}
	is_ans[0] = -1;
	is_ans[1] = -1;
	is_ans[2] = 2;
	for (int i = 3; i <= 31373; i++)
	{
		if (!is_prime[i])
		{
			is_ans[i] = is_ans[i - 1];
			continue;
		}
		if (func(i))
		{
			is_ans[i] = i;
		}
		else
		{
			is_ans[i] = is_ans[i - 1];
		}
	}
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n >= 31373)
		{
			cout << 31373 << '\n';
			continue;
		}
		if (is_ans[n] < 100)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << is_ans[n] << '\n';
		}
	}
	return 0;
}