#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, S, i, j,list[20],sum,cnt=0;
	scanf("%d %d", &N, &S);
	for (i = 0; i < N; i++)scanf("%d", &list[i]);

	for (i = 1; i < (1 << N); i++) {
		sum = 0;
		for (j = 0; j < N; j++) {
			if (i & (1 << j)) {
				sum += list[j];
			}
		}
		if (sum == S) cnt++;
	}
	printf("%d", cnt);
}