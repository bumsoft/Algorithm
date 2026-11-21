#include <iostream>
#include <string>
using namespace std;

int main()
{
	int clap = 0;
	string temp;
	int len;
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		temp = to_string(i);
		len = temp.size();
		for (int j = 0; j < len; j++)
		{
			if (temp[j] == '3') clap++;
			else if (temp[j] == '6') clap++;
			else if (temp[j] == '9') clap++;
		}
	}
	cout << clap;
	return 0;
}