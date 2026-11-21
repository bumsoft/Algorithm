#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
	int x;
	int y;
}A;
//y에 대해 정렬
int compare(const void *a, const void *b)
{
	if ((*(A *)a).y > (*(A *)b).y)  return 1;
	else if ((*(A *)a).y == (*(A *)b).y) {
		if ((*(A *)a).x > (*(A *)b).x) return 1;
		else if ((*(A *)a).x == (*(A *)b).x) return 0;
		else return -1;
	}
	else return -1;


}

int main()
{
	int N,i,j;
	A list[100000];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}
	qsort(list, N, sizeof(A), compare);
	for (i = 0; i < N; i++) printf("%d %d\n", list[i].x, list[i].y);
}