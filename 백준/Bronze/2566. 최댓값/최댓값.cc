#include <iostream>
using namespace std;
int main()
{
	int arr[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	int max = 0;
	int max_i = 0, max_j = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] >= max)
			{
				max = arr[i][j];
				max_i = i+1;
				max_j = j+1;
			}
		}
	cout << max << '\n' << max_i << ' ' << max_j;
}