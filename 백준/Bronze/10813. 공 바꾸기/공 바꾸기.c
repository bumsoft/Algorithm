#include <stdio.h>
int main()
{
	int list[101];
	int N, M, i, a, b, c;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		list[i] = i;
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		c = list[a];
		list[a] = list[b];
		list[b] = c;
	}
	for (i = 1; i <= N; i++) {
		printf("%d ", list[i]);
	}
}