#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
1. 우선순위에 따라 괄호로 묶기
2. 괄호 연산자를 괄호 오른쪽으로 옮겨주면 됨
*/
//ex. a+b*c => a+(b*c) => (a+(b*c)) => abc*+
// abc*+ => a(b*c)+ => a+b*c

// a+b*c - d
// (a+(b*c))-d) -> abc*+d-
// abc*+d- => 
// 
// 
// (a+bc)) d
// 
//st: a
// +
//res_st : (bc)

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	
	stack<int> st;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '*' || s[i] == '+')
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			if (s[i] == '*') st.push(a * b);
			else st.push(a + b);
		}
		else if (s[i] == '-' || s[i] == '/')
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();

			if (s[i] == '-') st.push(b - a);
			else st.push(b / a);

		}
		else
		{
			st.push(s[i] - 48);
		}
	}
	cout << st.top();

	return 0;
}