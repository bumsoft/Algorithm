#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a, int b)
{
	if (b == 0) return a;
	else return GCD(b, a % b);
}
int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}
int main()
{
	int T, M, N, x, y, k, t,temp;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		k = LCM(M, N);
		temp = x;
		while (temp <= k) {
			if (temp % N == y%N) { printf("%d\n",temp); break; }
			else temp += M;
		}
		if (temp > k)printf("-1\n");
	}
}