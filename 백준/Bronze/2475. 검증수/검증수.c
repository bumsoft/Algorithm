#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int list[5],i,j=0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &list[i]);
	}
	for (i = 0; i < 5; i++) {
		j += list[i] * list[i];
	}
	printf("%d", j % 10);
}