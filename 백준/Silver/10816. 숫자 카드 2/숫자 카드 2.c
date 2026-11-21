#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int count[20000001]={0,};

int main()
{
	int i, N, M, k;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &k);
		count[k + 10000000]++;
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d",&k);
		printf("%d ", count[k + 10000000]);
	}
}