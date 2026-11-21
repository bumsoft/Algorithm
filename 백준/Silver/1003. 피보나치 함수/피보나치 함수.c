#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int list0[41];
int list1[41];

int dp0(int N)
{
	switch (N) {
	case 0: {return 1;}
	case 1: {return 0; }
	}
	if (list0[N] != 0) return list0[N];

	list0[N] = dp0(N - 1) + dp0(N - 2);
	return list0[N];
}

int dp1(int N)
{
	switch (N) {
	case 0: {return 0; }
	case 1: {return 1; }
	}
	if (list1[N] != 0) return list1[N];

	list1[N] = dp1(N - 1) + dp1(N - 2);
	return list1[N];
}

int main()
{
	int T,N,i,j,zero,one;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		for (j = 1; j <= N; j++) { list0[j] = 0; list1[j] = 0; }
		zero = dp0(N);
		one = dp1(N);
		printf("%d %d\n", zero, one);
	}
}