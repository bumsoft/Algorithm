#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int list[101][101] = { 0, };
int visit[101] = { 0, };
int V=0;
void dfs(int start, int N)
{
	int i;
	visit[start] = 1;
	V++;

	for (i = 1; i <= N; i++) {
		if (list[start][i] == 1 && visit[i] == 0) dfs(i, N);
	}
}

int main()
{
	int N, n, i;
	int x, y;
	scanf("%d %d", &N, &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		list[x][y] = 1;
		list[y][x] = 1;
	}
	dfs(1, N);
	printf("%d", V-1);
}