#include <bits/stdc++.h>
#define size 2
using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;


matrix operator*(const matrix& a, const matrix& b)
{
	matrix res(size, vector<ll>(size)); //크기를 지정해서 0으로 초기화됨

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++) //a의 행과 b의 열은 i,j,로 고정시키고 열과 행을 k로 바꾸면서 연산
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 1'000'000'007;
		}
	}
	return res;
}

matrix power(matrix a, ll b) //a^b
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
	ll N; 
	matrix res{ {1, 1},
				{ 1,0 } };
	matrix original{ {1, 1},
					{ 1,0 } };

	cin >> N;
	res = original;
	res = power(res, N);
	cout << res[0][1] << endl;


	return 0;
}