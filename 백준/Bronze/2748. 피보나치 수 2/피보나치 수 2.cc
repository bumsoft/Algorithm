//1, 000, 000, 000, 000, 000, 000
//long long 9, 223, 372, 036, 854, 775, 807
//unsigned long long 18, 446, 744, 073, 709, 551, 615
#include <bits/stdc++.h>
#define size 2
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator*(const matrix& a, const matrix& b)
{
	matrix res(size, vector<long long>(size)); //크기를 지정해서 0으로 초기화됨

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++) //a의 행과 b의 열은 i,j,로 고정시키고 열과 행을 k로 바꾸면서 연산
			{
				res[i][j] += a[i][k] * b[k][j];
			}
			//res[i][j] %= 1000000; //10000으로 나눈 나머지.
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
	long long N;
	cin >> N;
	matrix m{ {1,1},{1,0} };
	m = power(m, N);
	cout << m[0][1];

	return 0;
}

