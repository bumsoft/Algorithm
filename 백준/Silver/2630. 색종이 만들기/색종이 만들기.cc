#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
char arr[130][130];

int blue;
int white;

void sol(int i, int j, int n) // i,j부터 n*n 보기
{
	if (n == 1)
	{
		if (arr[i][j] == '0')
		{
			white++;
		}
		else
		{
			blue++;
		}
		return;
	}

	char save = arr[i][j];
	bool ck = true;
	for (int a = i; a < i + n; a++)
	{
		for (int b = j; b < j + n; b++)
		{
			if (save != arr[a][b])
			{
				ck = false;
				break;
			}
		}
	}
	if (ck)
	{
		if (save == '0')white++;
		else blue++;
		return;
	}
	sol(i,j,n/2);
	sol(i+n/2,j,n/2);
	sol(i,j+n/2,n/2);
	sol(i+n/2,j+n/2,n/2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	sol(0,0,N);
	cout << white << '\n' << blue;
	return 0;
}