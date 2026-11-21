#include <iostream>
#include <stack>
#define min(a,b) a<b ? a:b
using namespace std;

stack<char> main_stack;
stack<int> value_stack;

bool g_func()
{
	if (value_stack.empty())
	{
		//cout << -1;
		return false;
	}
	else
	{
		int temp = value_stack.top();
		value_stack.pop();
		value_stack.push(temp + 1);
		return true;
	}
}
bool f_func()
{
	if (value_stack.size() < 2)
	{
		return false;
	}
	else
	{
		int a = value_stack.top(); value_stack.pop();
		int b = value_stack.top(); value_stack.pop();
		value_stack.push(min(a, b));
		return true;
	}
}
void x_func()
{
	value_stack.push(0);
}

int main()
{
	char t;
	while (cin >> t)
	{
		main_stack.push(t);
	}
	//스택이 비지 않았다면 ㄱㄱ
	while (!(main_stack.empty()))
	{
		if (main_stack.top() == 'x')
		{
			main_stack.pop();
			x_func();
		}
		else if (main_stack.top() == 'g')
		{
			main_stack.pop();
			if (!g_func())
			{
				cout << -1; return 0;
			}
		}
		else
		{
			main_stack.pop();
			if (!f_func())
			{
				cout << -1; return 0;
			}
		}
	}
	if (value_stack.size() == 1)
	{
		cout << value_stack.top();
	}
	else
	{
		cout << -1;
	}
	return 0;
}