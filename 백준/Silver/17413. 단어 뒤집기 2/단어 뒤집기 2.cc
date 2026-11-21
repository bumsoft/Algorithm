#include <bits/stdc++.h>
using namespace std;

/* 
* 17413 단어 뒤집기2
* <>는 뒤집지않음.
*/

stack<char> st;
bool con = 0;
int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	string s;
	getline(cin, s);
	for(int i=0;i<s.size();i++)
	{
		if (s[i] == '<')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			con = 1;
			cout << s[i];
			continue;
		}
		if (s[i] == '>')
		{
			con = 0;
			cout << s[i];
			continue;
		}
		if (con)
		{
			cout << s[i];
			continue;
		}
		if (s[i] != ' ')
		{
			st.push(s[i]);
			continue;
		}
		if (s[i] == ' ')
		{
			while (!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			cout << ' ';
		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}

	return 0;
}
