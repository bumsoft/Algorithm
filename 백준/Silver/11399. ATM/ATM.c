#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i, N, list[1000],sum=0,ans=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	qsort(list, N, sizeof(int), compare);
	for (i = 0; i < N; i++) {
		sum += list[i];
		ans += sum;
	}
	printf("%d", ans);
}