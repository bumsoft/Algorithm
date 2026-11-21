#include <bits/stdc++.h>
using namespace std;


int main()
{
	string o;
	cin >> o;

	bool k = false;
	int start = 0;
	int sum = 0;
	for (int i = 0; i < o.length(); i++)
	{
		if (i + 1 == o.length()) 
		{
			string temp = o.substr(start, i+1);
			if (k) sum -= stoi(temp);
			else sum += stoi(temp);
		}
		if (o[i] == '-')
		{
			string temp = o.substr(start, i);
			if (k) sum -= stoi(temp);
			else sum += stoi(temp);
			start = i + 1;
			k = true;
		}
		else if (o[i] == '+')
		{
			string temp = o.substr(start, i);
			if (k) sum -= stoi(temp);
			else sum += stoi(temp);
			start = i + 1;
		}
	}
	cout << sum;
	return 0;
}