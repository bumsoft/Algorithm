#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long t[36] = { 1, };

int main()
{
	int N,i,j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int temp = 0;
		for (j = 0; j < i;j++) {
			t[i] += t[j] * t[i - j - 1];
		}
	}
	printf("%lld", t[N]);
}