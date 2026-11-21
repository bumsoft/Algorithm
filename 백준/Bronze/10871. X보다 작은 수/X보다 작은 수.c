#include <stdio.h>
int main()
{
	int list[10000];
	int N, X, i;
	scanf("%d %d", &N, &X);
	for (i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	for (i = 0; i < N; i++) {
		if (list[i] < X) printf("%d ", list[i]);
	}
}