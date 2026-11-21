#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long t[117] = { 0,1,1,1, };

int main()
{
	int N,i,j;
	scanf("%d", &N);
	if (N <= 3) { printf("1"); return 0; }

	for (i = 4; i <= N; i++) {
		t[i] = t[i - 1] + t[i - 3];
	}
	printf("%lld", t[N]);
}