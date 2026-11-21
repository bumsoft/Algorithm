#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator*(const matrix& a, const matrix& b)
{
	int size = a.size();
	matrix res(size, vector<long long>(size)); //크기를 지정해서 0으로 초기화됨

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++) //a의 행과 b의 열은 i,j,로 고정시키고 열과 행을 k로 바꾸면서 연산
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1000; //10000으로 나눈 나머지.
		}
	}
	return res;
}

matrix power(matrix a, long long b) //a^b
{
	if (b == 1) return a;
	if (b % 2 == 0)
	{
		matrix half = power(a, b / 2); 
		return half * half;
	}
	else
	{
		matrix half = power(a, (b - 1) / 2);
		return half * half * a;
	}
}

int main()
{
	int N;
	long long B; //1 <= B <= 100,000,000,000
	cin >> N >> B;
	matrix m(N, vector<long long>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m[i][j];
		}
	}
	m = power(m, B);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << m[i][j]%1000 << ' ';
		}
		cout << '\n';
	}

	return 0;
}