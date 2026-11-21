#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k;
	char t;
	int list[10] = { 0, };
	
	while (1) {
		scanf("%c", &t);
		if (t == '\n')break;
		list[t - '0']++;
	}
	list[6] += list[9];
	list[9] = 0;
	if (list[6] % 2 == 0) list[6] /= 2;
	else list[6] = list[6] / 2 + 1;
	int max = 0;
	for (i = 0; i < 10; i++) {
		if (max < list[i]) max = list[i];
	}
	printf("%d", max);
}