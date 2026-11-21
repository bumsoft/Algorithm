#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//nCk =  N! / K!(N-K)!

int main()
{
	int N, K, ans = 1, i, k;
	scanf("%d %d", &N, &K);
	for (i = N; i > 0; i--) ans *= i;
	for (i = K; i > 0; i--) ans /= i;
	for (i = N - K; i > 0; i--) ans /= i;
	printf("%d", ans);
}