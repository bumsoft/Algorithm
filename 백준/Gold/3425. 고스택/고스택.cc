#include <bits/stdc++.h>
#define LIMIT 1'000'000'000
using namespace std;
using ll = long long;

stack < ll > st;
vector<ll> q;
int o;
void init()
{
	while (!st.empty())
	{
		st.pop();
	}
	o = 0;
}
void init_q()
{
	q.clear();
}
bool twoCheck()
{
	return st.size() > 1;
}

bool num()
{
	st.push(q[o++]);
	return true;
}
bool pop()
{
	if (st.empty()) return false;
	st.pop();
	return true;
}
bool inv()
{
	if (st.empty()) return false;
	ll t = st.top();
	st.pop();
	st.push(-t);
	return true;
}
bool dup()
{
	if (st.empty()) return false;
	st.push(st.top());
	return true;
}
bool swp()
{
	if (!twoCheck()) return false;
	ll a = st.top(); st.pop();
	ll b = st.top(); st.pop();
	st.push(a); st.push(b);
	return true;
}
bool add()
{
	if (!twoCheck()) return false;
	ll a = st.top(); st.pop();
	ll b = st.top(); st.pop();
	if (abs(a + b) > LIMIT) return false;
	st.push(a + b);
	return true;
}
bool sub()
{
	if (!twoCheck()) return false;
	ll a = st.top(); st.pop();
	ll b = st.top(); st.pop();
	if (abs(b - a) > LIMIT) return false;
	st.push(b - a);
	return true;
}
bool mul()
{
	if (!twoCheck()) return false;
	ll a = st.top(); st.pop();
	ll b = st.top(); st.pop();
	if (abs(b * a) > LIMIT) return false;
	st.push(b * a);
	return true;
}
bool div()
{
	if (!twoCheck()) return false;
	ll a = st.top(); st.pop();
	ll b = st.top(); st.pop();
	if (a == 0)return false;

	if (a < 0 && b > 0)
	{
		st.push(-(b / abs(a)));
		return true;
	}
	if (a > 0 && b < 0)
	{
		st.push(-(abs(b) / a));
		return true;
	}
	if (a < 0 && b < 0)
	{
		st.push(abs(b) / abs(a));
		return true;
	}
	else
	{
		st.push(b / a);
		return true;
	}
}
bool mod()
{
	if (!twoCheck()) return false;
	ll a = st.top(); st.pop();
	ll b = st.top(); st.pop();
	if (a == 0)return false;

	if (b < 0)
	{
		st.push(-(abs(b) % abs(a)));
		return true;
	}
	else
	{
		st.push((abs(b) % abs(a)));
		return true;
	}
}

bool sim(vector<string> order)
{
	string s;
	for(int i=0;i<order.size();i++)
	{
		s = order[i];

		if (s == "NUM")
		{
			num();
		}
		else if (s == "POP")
		{
			if (!pop()) return 0;
		}
		else if (s == "INV")
		{
			if (!inv()) return 0;
		}
		else if (s == "DUP")
		{
			if (!dup()) return 0;
		}
		else if (s == "SWP")
		{
			if (!swp()) return 0;
		}
		else if (s == "ADD")
		{
			if (!add()) return 0;
		}
		else if (s == "SUB")
		{
			if (!sub()) return 0;
		}
		else if (s == "MUL")
		{
			if (!mul()) return 0;
		}
		else if (s == "DIV")
		{
			if (!div()) return 0;
		}
		else if (s == "MOD")
		{
			if (!mod()) return 0;
		}
	}
	return 1;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	while (true)
	{
		init_q();
		//명령 입력
		vector<string> order;
		while (true)
		{
			cin >> s;
			if (s == "QUIT") return 0;
			if (s == "END") break;
			if (s == "NUM")
			{
				ll t;
				cin >> t;
				q.push_back(t);
			}
			order.push_back(s);
		}
		//수행
		int n; cin >> n;
		int t;
		while (n--)
		{
			init();
			cin >> t;
			st.push(t);
			if (!sim(order)) cout << "ERROR\n";
			else if (st.size() != 1) cout << "ERROR\n";
			else cout << st.top() << '\n';
		}
		cout << '\n';
	}
}