#include <bits/stdc++.h>
#define size 2
using namespace std;

typedef vector<vector<int>> matrix;


matrix operator*(const matrix& a, const matrix& b)
{
	matrix res(size, vector<int>(size)); //크기를 지정해서 0으로 초기화됨

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++) //a의 행과 b의 열은 i,j,로 고정시키고 열과 행을 k로 바꾸면서 연산
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= 10000; //10000으로 나눈 나머지.
		}
	}
	return res;
}

matrix power(matrix a, int b) //a^b
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
	int N; //0 <= N <= 1,000,000,000
	matrix res{ {1, 1}, 
				{ 1,0 } };
	matrix original{ {1, 1},
				{ 1,0 } };
	while (true)
	{
		cin >> N;
		if (N == -1) break;
		if (N == 0) { cout << 0 << '\n'; continue; }
		res = original;
		res = power(res, N);
		cout << res[0][1] << endl;
	}

	return 0;
}