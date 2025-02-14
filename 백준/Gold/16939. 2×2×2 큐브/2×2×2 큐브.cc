#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 돌리는 경우의 수 6가지.
// 각 경우의 수 별, 각 칸이 어디로 가는지 미리 구해둬야할 듯

vector<int> original;
vector<int> copy_;
/*
	육면 확인하는 함수
*/
bool check()
{
	if (copy_[1] == copy_[2] && copy_[2] == copy_[4] && copy_[4] == copy_[3])
	{

	}
	else return false;

	if (copy_[5] == copy_[6] && copy_[6] == copy_[8] && copy_[8] == copy_[7])
	{

	}
	else return false;

	if (copy_[9] == copy_[10] && copy_[10] == copy_[12] && copy_[12] == copy_[11])
	{

	}
	else return false;

	if (copy_[13] == copy_[14] && copy_[14] == copy_[16] && copy_[16] == copy_[15])
	{

	}
	else return false;

	if (copy_[17] == copy_[18] && copy_[18] == copy_[20] && copy_[20] == copy_[19])
	{

	}
	else return false;

	if (copy_[21] == copy_[22] && copy_[22] == copy_[24] && copy_[24] == copy_[23])
	{
		return true;
	}
	else return false;
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	original.push_back(0);
	for (int i = 0; i < 24; i++)
	{
		cin >> t;
		original.push_back(t);
	}
	int a, b, c, d;

	//세로로, 왼쪽을 아래로 이동---------------------
	copy_ = original;
	//1 3 => 5 7
	a = copy_[5];
	b = copy_[7];
	copy_[5] = copy_[1];
	copy_[7] = copy_[3];

	//5 7 => 9 11
	c = copy_[9];
	d = copy_[11];
	copy_[9] = a;
	copy_[11] = b;

	//9 11 => 22 24
	a = copy_[22];
	b = copy_[24];
	copy_[22] = c;
	copy_[24] = d;

	//22 24 => 1 3
	copy_[1] = a;
	copy_[3] = b;
	if (check())
	{
		cout << 1;
		return 0;
	}

	//세로로, 왼쪽을 위로 이동------------------------
	copy_ = original;
	//1 3 => 22 24
	a = copy_[22];
	b = copy_[24];
	copy_[22] = copy_[1];
	copy_[24] = copy_[3];
	//22 24 => 9 11
	c = copy_[9];
	d = copy_[11];
	copy_[9] = a;
	copy_[11] = b;
	//9 11 => 5 7
	a = copy_[5];
	b = copy_[7];
	copy_[5] = c;
	copy_[7] = d;
	//5 7 => 1 3
	copy_[1] = a;
	copy_[3] = b;
	if (check())
	{
		cout << 1;
		return 0;
	}
	//가로로, 위쪽을 왼쪽으로 이동-----------------------
	//13 14 => 21 22
	copy_ = original;
	a = copy_[21];
	b = copy_[22];
	copy_[21] = copy_[13];
	copy_[22] = copy_[14];
	//21 22 => 17 18
	c = copy_[17];
	d = copy_[18];
	copy_[17] = a;
	copy_[18] = b;
	//17 18 => 5 6
	a = copy_[5];
	b = copy_[6];
	copy_[5] = c;
	copy_[6] = d;
	// 5 6 => 13 14
	copy_[13] = a;
	copy_[14] = b;
	if (check())
	{
		cout << 1;
		return 0;
	}
	//가로로, 위쪽을 오른쪽으로 이동----------------------
	//13 14 => 5 6
	copy_ = original;
	a = copy_[5];
	b = copy_[6];
	copy_[5] = copy_[13];
	copy_[6] = copy_[14];
	//5 6 => 17 18
	c = copy_[17];
	d = copy_[18];
	copy_[17] = a;
	copy_[18] = b;
	//17 18 => 21 22
	a = copy_[21];
	b = copy_[22];
	copy_[21] = c;
	copy_[22] = d;
	//21 22 => 13 14
	copy_[13] = a;
	copy_[14] = b;
	if (check())
	{
		cout << 1;
		return 0;
	}

	//맨 앞면 돌리기, 오른쪽으로 이동----------------------
	//3 4 => 17 19
	copy_ = original;
	a = copy_[17];
	b = copy_[19];
	copy_[17] = copy_[3];
	copy_[19] = copy_[4];
	//17 19 => 9 10
	c = copy_[9];
	d = copy_[10];
	copy_[9] = a;
	copy_[10] = b;
	//9 10 => 14 16
	a = copy_[14];
	b = copy_[16];
	copy_[14] = c;
	copy_[16] = d;
	//14 16 => 3 4
	copy_[3] = a;
	copy_[4] = b;
	if (check())
	{
		cout << 1;
		return 0;
	}

	//맨 앞면 돌리기, 왼쪽으로 이동----------------------
	//3 4 => 14 16
	copy_ = original;
	a = copy_[14];
	b = copy_[16];
	copy_[14] = copy_[3];
	copy_[16] = copy_[4];
	//14 16 => 9 10
	c = copy_[9];
	d = copy_[10];
	copy_[9] = a;
	copy_[10] = b;
	//9 10 => 17 19
	a = copy_[17];
	b = copy_[19];
	copy_[17] = c;
	copy_[19] = d;
	//17 19 => 3 4
	copy_[3] = a;
	copy_[4] = b;
	if (check())
	{
		cout << 1;
		return 0;
	}
	cout << 0;
}