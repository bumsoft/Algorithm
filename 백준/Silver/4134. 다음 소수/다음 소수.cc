#include <iostream>
#include <string>
#include <cmath>
using namespace std;


//학번/전번/이메일
int main()
{
	long long N; cin >> N;
	long long n;
	int ck;
	for (long long l = 0; l < N; l++)
	{
		cin >> n;
		if (n == 0) { cout << 2<<"\n"; continue; }
		if (n == 1) { cout << 2 << "\n"; continue; }
		if (n == 2) { cout << 2 << "\n"; continue; }
		if (n == 3) { cout << 3 << "\n"; continue; }
		if (n == 4) { cout << 5 << "\n"; continue; }
		

		for (long long i = n; ; i++)
		{
			ck = 0;
			long long t = (long long)sqrt(i);
			for (long long j = 2; j <= t; j++)
			{
				if (i % j == 0) { ck = 0; break; }
				else ck = 1;
			}
			if (ck == 1) { cout << i << "\n"; break; }
		}
	}
	return 0;
}