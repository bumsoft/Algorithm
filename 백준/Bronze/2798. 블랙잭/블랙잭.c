#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N, M, i, j, l, s, max = 0;
	int list[100] = { 0, };
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &list[i]);
		if (list[i] + 1 > M) list[i] = 0;
	}
	for (i = 0; i < N; i++) {
		if (list[i] == 0) continue;
		for (j = 0; j < N; j++) {
			if (i == j || list[j]==0) continue;
			for (l = 0; l < N; l++) {
				if (l == i || l == j)continue;
				if (list[l] == 0)continue;
				s = list[i] + list[j] + list[l];
				if (s > max&&s<=M) max = s;
			}
		}
	}
	printf("%d", max);
}