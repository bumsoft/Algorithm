#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int temp;
	int Sum[100001] = { 0, };
	int N, M, i, j,q,w;
	scanf("%d %d", &N, &M);
	for (q = 1; q <= N; q++) { 
		scanf("%d", &temp);
		Sum[q] = Sum[q - 1] + temp;
	}
	for (q = 0; q < M; q++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", Sum[j]-Sum[i-1]);
	}
}