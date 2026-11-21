#include <iostream>

using namespace std;


int memo[10001];
int n, k, temp;


int main()
{
	cin >> n >> k;
	memo[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j <= k; j++)
		{
			if (j >= temp)
			{
				memo[j] = memo[j - temp] + memo[j];
			}
		}
	}
	cout << memo[k];
}