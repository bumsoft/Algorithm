#define _CRT_SECURE_NO_WARNINGS
/* 백준 1966 프린터 큐(실버III)  #큐 */
#include <stdio.h>
#include <string.h>
typedef struct queue
{
	int name[10000];
	int value[10000];
}Queue;

int main()
{
	Queue A;
	int T, N, M, i, j, k, ck, count,R;
	scanf("%d", &T);
	for (R = 0; R < T; R++) {
		count = 0;
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; i++) {
			A.name[i] = i;
			scanf("%d", &A.value[i]);
		}
		A.name[M] = 1000;
		k = N;
		for (i = 0; i < k; i++) {
			ck = 0;
			for (j = i+1; j < k; j++) {
				if (A.value[i] < A.value[j]) {
					ck = 1;
					break;
				}
			}
			if (ck == 1) {
				A.value[k] = A.value[i];
				A.name[k] = A.name[i];
				A.name[i] = 0;
				k++;
			}
			else {
				count++;
				if (A.name[i] == 1000) {
					printf("%d\n", count);
					break;
				}
			}
		}
	}
}