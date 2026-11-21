#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int h[50], w[50], num[50] = { 0, };
	int N, x, y, i, j, k=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &w[i], &h[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i != j) {
				if (h[i] < h[j] && w[i] < w[j]) num[i]++;
			}
		}
	}
	for (i = 0; i < N; i++)printf("%d ", num[i]+1);
}