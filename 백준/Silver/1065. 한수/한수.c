#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i,cnt=0;
	scanf("%d", &N);
	if (N < 100) { printf("%d",N); return 0; }
	else {
		cnt = 99;
		int a, b, c;
		for (i = 100; i <= N; i++) {
			a = i / 100;
			b = (i % 100) / 10;
			c = (i % 100) % 10;
			if (a - b == b - c) cnt++;
		}
	}
	printf("%d", cnt);
}