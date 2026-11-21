#include <stdio.h>
int main()
{
	int list[101];
	int N, M, i, j, a, b, c;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		list[i] = i;
	}
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		if ((b - a) % 2 == 1) {
			for (j = 0; j < (b - a) / 2 + 1; j++) {
				c = list[a + j];
				list[a + j] = list[b - j];
				list[b - j] = c;
			}
		}
		else {
			for (j = 0; j < (b - a) / 2; j++) {
				c = list[a + j];
				list[a + j] = list[b - j];
				list[b - j] = c;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		printf("%d ", list[i]);
	}
}