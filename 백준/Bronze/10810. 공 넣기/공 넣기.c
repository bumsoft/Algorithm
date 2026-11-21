#include <stdio.h>
int main()
{
	int list[101] = { 0, };
	int N, M, i, a, b, c;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		for (; a <= b; a++) {
			list[a] = c;
		}
	}
	for (i = 1; i <= N; i++) {
		printf("%d ", list[i]);
	}
}