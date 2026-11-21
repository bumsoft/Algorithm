#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int list[101][101] = { 0, };
int visit[10001][2] = { 0, };
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int que(int N,int M)
{
	int i, j;
	int front = 0, back = 0;

	visit[front][0] = 1;
	visit[front][1] = 1;
	back++;

	while (front < back) {
		int x = visit[front][0];
		int y = visit[front][1];
		front++;

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (list[nx][ny] != 1) continue;

			list[nx][ny] = list[x][y] + 1;

			visit[back][0] = nx;
			visit[back][1] = ny;
			back++;
		}
	}
	return list[N][M];
}
int main()
{
	int N, M,i,j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%1d", &list[i][j]);
		}
	}
	int ans = que(N,M);
	printf("%d", ans);
}