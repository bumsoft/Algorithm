#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j, N, p;
	double V = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &p);
		V = 1 - (1 - V) * (1 - (double)p/100);
		printf("%lf\n", V*100);
	}
}