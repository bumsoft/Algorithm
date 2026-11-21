#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparelen(const void *a, const void *b)
{
	if (strlen((char *)a) == strlen((char *)b)) {
		return strcmp((char *)a, (char *)b);
	}
	else if (strlen((char *)a) > strlen((char *)b)) {
		return 1;
	}
	else if (strlen((char *)a) < strlen((char *)b)) {
		return -1;
	}
}
int main()
{
	int N, i;

	scanf("%d", &N);
	char list[20000][51];
	for (i = 0; i < N; i++) {
		scanf("%s", list[i]);
	}
	qsort(list, N, sizeof(list[0]), comparelen);
	for (i = 0; i < N; i++) {
		if (i != 0 && strcmp(list[i],list[i - 1]) == 0);
		else printf("%s\n",list[i]);
	}
}