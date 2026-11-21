#include <bits/stdc++.h>
using namespace std;

void re(int n)
{
	if (n == 1)
	{
		cout << '-';
		return;
	}

	re(n / 3);

	for (int i = 0; i < n / 3; i++)
	{
		cout << ' ';
	}
	re(n / 3);
}

int main()
{
	int N;
	while (cin >> N)
	{
		re(pow(3,N));
		cout << '\n';
	}
}