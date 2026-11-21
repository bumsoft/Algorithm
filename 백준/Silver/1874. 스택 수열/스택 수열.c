#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char pp[200001];
typedef struct stack
{
	int list[100000];
	int head;
}Stack;

int main()
{
	Stack A;
	A.head = 0;
	int n, l[100000],i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) A.list[i] = 0;
	for (i = 0; i < n; i++) scanf("%d", &l[i]);
	int ll = 0, p = 0;
	for (i = 1; i <= n; i++) {
		if (i < l[ll]) {
			A.list[A.head] = i;
			(A.head)++;
			pp[p] = '+';
			p++;
		}
		else if (i == l[ll]) {
			pp[p] = '+';
			p++;
			pp[p] = '-';
			p++;
			ll++;
		}
		else if (i > l[ll]) {
			if (A.list[A.head - 1] == l[ll]) {
				pp[p] = '-';
				p++;
				ll++;
				(A.head)--;
				i--;
			}
			else {
				printf("NO");
				return 0;
			}
		}
	}
	while (ll<n) {
		if (A.list[A.head - 1] == l[ll]) {
			pp[p] = '-';
			p++;
			ll++;
			(A.head)--;
		}
		else {
			printf("NO");
			return 0;
		}
	}
	int len = strlen(pp); 
	for (i = 0; i < len; i++) printf("%c\n", pp[i]);
}