#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int list[1000001] = { 0, };

int min3(int a, int b, int c)
{
	if (a < b) {
		if (a < c) return a;
		else return c;
	}
	else {
		if (b < c) return b;
		else return c;
	}
}
int min2(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int dp(int N)
{
	switch (N) {
	case 1: return 0;
	case 2: return 1;
	case 3: return 1;
	}
	if (list[N] != 0) return list[N];

	if (N % 3 == 0 && N % 2 == 0) {
		list[N] = min3(dp(N/3),dp(N/2),dp(N-1))+1;
	}
	else if (N % 3 == 0 && N % 2 != 0) {
		list[N] = min2(dp(N/3),dp(N-1))+1;
	}
	else if (N % 3 != 0 && N % 2 == 0) {
		list[N] = min2(dp(N/2),dp(N-1))+1;
	}
	else list[N] = dp(N - 1)+1;

	return list[N];
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", dp(N));
}