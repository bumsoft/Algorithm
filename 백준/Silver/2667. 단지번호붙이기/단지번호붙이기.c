#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char map[25][25];
int num[320] = { 0, };

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void dfs(int N, int i, int j, int *count)
{
	map[i][j] = 'a';
	(*count)++;
	//상
	if (i > 0 && map[i-1][j]=='1') dfs(N, i - 1, j, count);
	//하
	if (i < N - 1 && map[i + 1][j] == '1') dfs(N, i + 1, j, count);
	//좌
	if (j > 0 && map[i][j-1] == '1') dfs(N, i, j-1, count);
	//우
	if (j < N-1 && map[i][j+1] == '1') dfs(N, i, j+1, count);
}
int main()
{
	int N,i,j,k=0,count;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%s", &map[i]);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == '1') {
				count = 0;
				dfs(N,i,j,&count);
				num[k] = count;
				k++;
			}
		}
	}
	qsort(num, 320, sizeof(int), compare);
	printf("%d\n", k);
	for (i = 0; i < 320; i++) {
		if (num[i] != 0) printf("%d\n", num[i]);
	}
}