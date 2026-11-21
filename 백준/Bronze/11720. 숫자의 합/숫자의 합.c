#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N, i, sum = 0;
	char list[100] = {0,};
	scanf("%d %s", &N, list);
	for (i = 0; i < N; i++) sum += list[i]-48;
	printf("%d", sum);
}