#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)
int score[301];
int sum[300] = { 0, };
int dp(int N)
{
	sum[N] = MAX(dp(N-3)+score[N-1],dp(N-2)) + score[N];
}
int main()
{
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &score[i]);
	}
	sum[0] = 0;
	sum[1] = score[1];
	sum[2] = score[1] + score[2];
	for (i = 3; i <= N; i++) {
		sum[i] = MAX(sum[i-2],sum[i-3]+score[i-1]) + score[i];
	}

	printf("%d", sum[N]);
}