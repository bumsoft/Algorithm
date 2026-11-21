#include <iostream>

using namespace std;

int N, M, x, y, K;
int map[20][20];

class dice
{
public:
	//x가 세로
	//y가 가로
	int x;
	int y;
	int top;
	int bottom;
	int north;
	int south;
	int east;
	int west;
	dice(int _x, int _y, int _top = 0, int _bottom = 0, int _north = 0, int _south = 0, int _east = 0, int _west = 0)
		: x(_x), y(_y), top(_top), bottom(_bottom), north(_north), south(_south), east(_east), west(_west)
	{}
	void one(int t) //동
	{
		int k = top;
		top = west;
		west = bottom;
		bottom = east;
		east = k;

		if (t == 0)
		{
			map[x][y] = bottom;
		}
		else
		{
			bottom = t;
			map[x][y] = 0;
		}
		cout << top << endl;
	}
	void two(int t) //서
	{
		int k = top;
		top = east;
		east = bottom;
		bottom = west;
		west = k;

		if (t == 0)
		{
			map[x][y] = bottom;
		}
		else
		{
			bottom = t;
			map[x][y] = 0;
		}
		cout << top << endl;
	}
	void three(int t) //북
	{
		int k = top;
		top = south;
		south = bottom;
		bottom = north;
		north = k;

		if (t == 0)
		{
			map[x][y] = bottom;
		}
		else
		{
			bottom = t;
			map[x][y] = 0;
		}
		cout << top << endl;

	}
	void four(int t) //남
	{
		int k = top;
		top = north;
		north = bottom;
		bottom = south;
		south = k;

		if (t == 0)
		{
			map[x][y] = bottom;
		}
		else
		{
			bottom = t;
			map[x][y] = 0;
		}
		cout << top << endl;

	}
};
int main()
{
	cin >> N >> M >> x >> y >> K;
	dice d(x, y);
	 //맵 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	// 명령 입력
	int order;
	for (int i = 0; i < K; i++)
	{
		cin >> order;
		switch (order)
		{
		case 1:
		{
			if (d.y < M - 1)
			{
				d.y += 1;
				d.one(map[d.x][d.y]);
			}
			break;
		}
		case 2: 
		{
			if (d.y > 0)
			{
				d.y -= 1;
				d.two(map[d.x][d.y]);
			}
			break;
		}
		case 3:
		{
			if (d.x > 0)
			{
				d.x -= 1;
				d.three(map[d.x][d.y]);
			}
			break;
		}
		case 4:
		{
			if (d.x < N - 1)
			{
				d.x += 1;
				d.four(map[d.x][d.y]);
			}
			break;
		}
		}
	}
	return 0;
}