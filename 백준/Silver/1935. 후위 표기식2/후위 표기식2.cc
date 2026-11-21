#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double arr[26];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	string s; cin >> s;
	for (int i = 0; i < N; i++)cin >> arr[i];
	
	stack<double> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			st.push(arr[s[i] - 'A']);
		}

		else if (s[i] == '+')
		{
			double a = st.top(); st.pop();
			double b = st.top(); st.pop();
			st.push(a + b);
		}		
		else if (s[i] == '-')
		{
			double a = st.top(); st.pop();
			double b = st.top(); st.pop();
			st.push(b - a);
		}		
		else if (s[i] == '*')
		{
			double a = st.top(); st.pop();
			double b = st.top(); st.pop();
			st.push(a * b);
		}		
		else if (s[i] == '/')
		{
			double a = st.top(); st.pop();
			double b = st.top(); st.pop();
			st.push(b / a);
		}
	}
	double ans = st.top();
	string ANS = to_string(ans);
	int d = 0;
	bool ck = false;
	for (int i = 0; i < ANS.length(); i++)
	{
		if (ANS[i] == '.')
		{
			cout << '.';
			ck = true; 
			continue;
		}
		if (ck)
		{
			cout << ANS[i];
			d++;
			if (d == 2) return 0;
		}
		if (!ck)
		{
			cout << ANS[i];
		}
	}
	while (d < 2)
	{
		cout << '0';
		d++;
	}
	return 0;
}