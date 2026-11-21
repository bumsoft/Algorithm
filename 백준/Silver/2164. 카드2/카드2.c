#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int list[1010000];
int main()
{
	int N,i,j=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) list[i] = i + 1;

	for (i = 0; i <= N; i++) {
		if (list[i] == 0) {
			printf("%d", list[i-1]);
			break;
		}
		j++;
		if (j == 2) {
			list[N] = list[i];
			list[N + 1] = 0;
			N++;
			j = 0;
		}
	}
}