#include <iostream>

using namespace std;

int list[101];

int main()
{
	int N;
	int t;
	cin >> N; //3<= <=100;
	for (int i = 1; i <= N; i++)
	{
		cin >> t;
		list[t]++;
	}
	int max = 0;
	int num = 0;
	int ck = 0;
	for (int i = 1; i <= N; i++)
	{
		if (list[i] == max)
		{
			ck = 1;
		}
		if (list[i] > max)
		{
			max = list[i];
			num = i;
			ck = 0;
		}

	}
	if (max == 0 || ck==1) cout << "skipped";
	else cout << num;
}