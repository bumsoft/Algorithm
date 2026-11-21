#define _CRT_SECURE_NO_WARNINGS
/* 백준 2893 설탕 배달(실버IV)  #그리드알고리즘 #다이나믹프로그래밍 */
#include <stdio.h>
int main()
{
	int T, H, W, N, i, j, k;
	int room[99][99], r;
	scanf("%d", &T);
	for (k = 0; k < T; k++) {
		scanf("%d %d %d", &H, &W, &N);
		r = 1;
		for (i = 0; i < W; i++) {
			for (j = 0; j < H; j++) {
				room[j][i] = r;
				r++;
			}
		}
		for (i = 0; i < W; i++) {
			for (j = 0; j < H; j++) {
				if (room[j][i] == N) {
					if (i + 1 < 10) printf("%d0%d\n", j + 1, i + 1);
					else printf("%d%d\n", j + 1, i + 1);
				}
			}
		}
	}
}