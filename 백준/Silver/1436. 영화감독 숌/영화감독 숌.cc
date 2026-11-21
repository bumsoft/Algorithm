#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 0;
	for (int i = 1; ; i++)
	{
		int temp = i;
		while (true)
		{
			if (temp % 1000 == 666)
			{
				count++;
				if (count == N) 
				{
					cout << i;
					return 0;
				}
				break;
			}
			else
			{
				temp /= 10;
				if (temp == 0) break;
			}
		}
	}
}