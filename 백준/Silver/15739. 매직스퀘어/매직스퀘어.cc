#include <iostream>

using namespace std;

int list[100][100];
char check[10005];

int main()
{
	int N; cin >> N;
	int sum = N * (N * N + 1) / 2;
	int t;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> t;
			if (check[t] == 0) check[t] = '1';
			else { cout << "FALSE"; return 0; }
			list[i][j] = t;
			
		}
	}

	//행
	for (int i = 0; i < N; i++)
	{
		t = 0;
		for (int j = 0; j < N; j++)
		{
			t += list[i][j];
		}
		if (t != sum) { cout << "FALSE"; return 0; }
	}
	//열
	for (int i = 0; i < N; i++)
	{
		t = 0;
		for (int j = 0; j < N; j++)
		{
			t += list[j][i];
		}
		if (t != sum) { cout << "FALSE"; return 0; }
	}
	//대각선
	int r = 0; t = 0;
	while (r < N)
	{
		t += list[r][r];
		r++;
	}
	if (sum != t) { cout << "FALSE"; return 0; }

	r = N - 1; t = 0;
	while (r >= 0)
	{
		t += list[r][r];
		r--;
	}
	if (sum != t) { cout << "FALSE"; return 0; }
	cout << "TRUE";
}