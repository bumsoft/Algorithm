//7576에서 큐 하나 더 추가하고 입력부분, bfs함수만 수정
#include <iostream>
#include <queue>

using namespace std;

int tomato[100][100][100]; // 더 추가
int M, N, H;
int zero = 0, one = 0, t = 0;
queue<int>a;
queue<int>b;
queue<int>c;

void bfs(int a, int b, int c)
{
	//상
	if (a > 0 && tomato[c][a - 1][b] == 0) { tomato[c][a - 1][b] = 1; ::a.push(a - 1); ::b.push(b); ::c.push(c); zero--; }
	//하
	if (a < N - 1 && tomato[c][a + 1][b] == 0) { tomato[c][a + 1][b] = 1; ::a.push(a + 1); ::b.push(b); ::c.push(c); zero--; }
	//좌
	if (b > 0 && tomato[c][a][b - 1] == 0) { tomato[c][a][b - 1] = 1; ::a.push(a); ::b.push(b - 1); ::c.push(c); zero--; }
	//우
	if (b < M - 1 && tomato[c][a][b + 1] == 0) { tomato[c][a][b + 1] = 1; ::a.push(a); ::b.push(b + 1); ::c.push(c); zero--; }

	//아래
	if (c > 0 && tomato[c - 1][a][b] == 0) { tomato[c - 1][a][b] = 1; ::a.push(a); ::b.push(b); ::c.push(c - 1); zero--; }
	//위
	if (c < H-1 && tomato[c + 1][a][b] == 0) { tomato[c + 1][a][b] = 1; ::a.push(a); ::b.push(b); ::c.push(c + 1); zero--;}

	::a.pop();
	::b.pop();
	::c.pop();
}

int main()
{
	//토마토 저장상태 입력

	int day = 0;
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> tomato[h][i][j];
				if (tomato[h][i][j] == 0) zero++;
				else if (tomato[h][i][j] == 1)
				{
					a.push(i);
					b.push(j);
					c.push(h);
					one++;
				}
			}
		}
	}
	if (zero == 0) { cout << 0; return 0; }
	else if (one == 0) { cout << -1; return 0; }
	t = one;
	while (!a.empty()) //비어있지 않으면 반복
	{
		bfs(a.front(), b.front(), c.front());
		t--;
		if (t == 0)
		{
			t = a.size();
			day++;
		}
	}

	if (zero <= 0)	cout << day - 1;
	else cout << -1;
	return 0;
}