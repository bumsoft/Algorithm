#include <stdio.h>
int list[10] = { 0, };
int main()
{
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)scanf("%d", &list[i]);
	int kk=0;
	for (i = 1; i <= N; i++) {
		if (K / list[N - i] > 0) { kk += K / list[N - i]; K -= (K / list[N - i]) * list[N - i]; }
	}
	printf("%d", kk);
}