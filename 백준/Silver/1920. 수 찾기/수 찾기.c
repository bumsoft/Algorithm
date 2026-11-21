#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	if (num1 < num2) return -1;
	if (num1 > num2) return 1;
	return 0;
}


int main()
{
	int list[100000];
	int N, M, X, i, low, high, mid;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &list[i]);

	qsort(list,N,sizeof(int),compare);

	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &X);
		low = 0;
		high = N - 1;
		int ck=0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (X > list[mid]) {
				low = mid + 1;
			}
			else if (X < list[mid]) {
				high = mid - 1;
			}
			else if (X == list[mid]) {
				printf("1\n");
				ck = 1;
				break;
			}
		}
		if (ck != 1) printf("0\n");
	}
}