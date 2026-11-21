#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct a
{
	int x;
	int y;
}A;

int compare(const void *a, const void *b)
{
	A q = *(A *)a;
	A w = *(A *)b;
	if (q.x > w.x) return 1;
	else if (q.x == w.x) {
		if (q.y > w.y) return 1;
		else if (q.y == w.y) return 0;
		else return -1;
	}
	else return -1;
}

int main()
{
	int i, j, N;
	A list[100000];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d",&list[i].x, &list[i].y);
	}
	qsort(list,N,sizeof(A),compare);
	for (i = 0; i < N; i++) {
		printf("%d %d\n", list[i].x, list[i].y);
	}
}