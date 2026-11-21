#include <iostream>
#include <queue>

using namespace std;

int tomato[1000][1000];
int M, N;
int zero = 0, one = 0, t = 0;
queue<int>a;
queue<int>b;

void bfs(int a, int b)
{
	//상
	if (a > 0 && tomato[a - 1][b] == 0) { tomato[a - 1][b] = 1; ::a.push(a - 1); ::b.push(b); zero--; }
	//하
	if (a < N - 1 && tomato[a + 1][b] == 0) { tomato[a + 1][b] = 1; ::a.push(a + 1); ::b.push(b); zero--; }
	//좌
	if (b > 0 && tomato[a][b - 1] == 0) { tomato[a][b - 1] = 1; ::a.push(a); ::b.push(b - 1); zero--; }
	//우
	if (b < M - 1 && tomato[a][b + 1] == 0) { tomato[a][b + 1] = 1; ::a.push(a); ::b.push(b + 1); zero--; }
	::a.pop();
	::b.pop();
}

int main()
{
	//토마토 저장상태 입력


	int day = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 0) zero++;
			else if (tomato[i][j] == 1)
			{
				a.push(i);
				b.push(j);
				one++;
			}
		}
	}
	if (zero == 0) { cout << 0; return 0; }
	else if (one == 0) { cout << -1; return 0; }
	t = one;
	while (!a.empty()) //비어있지 않으면 반복
	{
		bfs(a.front(), b.front());
		t--;
		if (t == 0)
		{
			t = a.size();
			day++;
		}
	}

	if (zero == 0)	cout << day-1;
	else cout << -1;
	return 0;
}