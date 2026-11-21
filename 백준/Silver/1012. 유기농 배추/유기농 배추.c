#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* 백준 1012 유기농 배추(실버II)  #그래프탐색 #DFS #깊이우선탐색 #재귀함수 */

void dfs(int land[][50], int *M, int *N, int i, int j)
{	
	if (land[i][j] == 0) return;
	land[i][j] = 0;
	/*오른쪽으로 한칸*/
	if (j < *M - 1) {
		dfs(land, M, N, i, j + 1);
	}
	/*왼쪽으로 한칸*/
	if (j > 0) {
		dfs(land, M, N, i, j - 1);
	}
	/*위로 한칸*/
	if (i > 0) {
		dfs(land, M, N, i - 1, j);
	}
	/*아래로 한칸*/
	if (i < *N-1) {
		dfs(land, M, N, i+1, j);
	}
}


int main()
{
	int T, M, N, K,R,i,j,q,w,count=0;
	int land[50][50];
	scanf("%d", &T);
	for (R = 0; R < T; R++) {
		scanf("%d %d %d", &M, &N,&K);
		for (i = 0; i < 50; i++) {
			for (j = 0; j < 50; j++) land[i][j] = 0;
		}
		for (i = 0; i < K; i++) {
			scanf("%d %d", &q, &w);
			land[w][q] = 1;
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (land[i][j] == 1) { 
					dfs(land, &M, &N, i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);
		count = 0;
	}
}