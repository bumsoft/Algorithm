#define _CRT_SECURE_NO_WARNINGS
/* 백준 10845 큐(실버IV)  #큐 */
#include <stdio.h>
#include <string.h>
typedef struct queue
{
	int front;
	int back;
	int list[10001];
}Queue;

int main()
{
	Queue A;
	int N,n,r;
	char order[6];
	A.front = 0;
	A.back = 0;
	scanf("%d", &N);
	for (r = 0; r < N; r++) {
		scanf("%s", order);
		if (strcmp(order,"push")==0) {
			scanf("%d", &n);
			A.list[A.back] = n;
			A.back++;
		}
		else if (strcmp(order,"pop")==0) {
			if (A.front == A.back) printf("-1\n");
			else {
				printf("%d\n", A.list[A.front]);
				A.front++;
			}
		}
		else if (strcmp(order,"size")==0) {
			printf("%d\n", A.back - A.front);
		}
		else if (strcmp(order,"empty")==0) {
			if (A.front == A.back) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(order,"front")==0) {
			if (A.front == A.back) printf("-1\n");
			else printf("%d\n", A.list[A.front]);
		}
		else {
			if (A.front == A.back) printf("-1\n");
			else printf("%d\n", A.list[A.back-1]);
		}
	}
}