#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char list[][600], int *count, int n, int m, int N, int M)
{
	if (list[n][m] == 'P') { 
		(*count)++; 
	}
	list[n][m] = 'X';
	//상
	if (n > 0 && list[n - 1][m] != 'X') {
		search(list, count, n - 1, m, N, M);
	}
	//하
	if (n < N-1 && list[n + 1][m] != 'X') {
		search(list, count, n + 1, m, N, M);
	}
	//좌
	if (m > 0 && list[n][m-1] != 'X') {
		search(list, count, n, m-1, N, M);
	}
	//우
	if (m < M-1 && list[n][m + 1] != 'X') {
		search(list, count, n, m + 1, N, M);
	}
	else return;
}
int main()
{
	int N, M, i, j,ck=0, count=0,n,m;
	char list[600][600];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", list[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (list[i][j] == 'I') {
				n = i;
				m = j;
				ck = 1;
				break;
			}
		}
		if (ck == 1) break;
	}
	search(list,&count,n,m,N,M);
	if (count == 0) printf("TT");
	else printf("%d", count);
}