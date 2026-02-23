#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string name;
	string c;
	string score;

	int total = 0;
	double total_s = 0;
	for (int i = 0; i < 20; i++)
	{
		cin >> name >> c >> score;
		int t;
		if (c == "1.0")
		{
			t = 1;
		}
		else if (c == "2.0")
		{
			t = 2;
		}
		else if (c == "3.0")
		{
			t = 3;
		}
		else
		{
			t = 4;
		}
		if (score == "P")
		{
			continue;
		}
		total += t;
		double s;
		if (score == "A+")
		{
			s = 4.5;
		}
		else if (score == "A0")
		{
			s = 4.0;
		}
		else if (score == "B+")
		{
			s = 3.5;
		}
		else if (score == "B0")
		{
			s = 3.0;
		}
		else if (score == "C+")
		{
			s = 2.5;
		}
		else if (score == "C0")
		{
			s = 2.0;
		}
		else if (score == "D+")
		{
			s = 1.5;
		}
		else if (score == "D0")
		{
			s = 1.0;
		}
		else
		{
			s = 0;
		}
		total_s += s*t;
	}
	printf("%.6f", total_s / total);
	return 0;
}