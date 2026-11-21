#include <stdio.h>
#include <string.h>
typedef struct stack
{
	int buf[10000];
	int top;
} Stack;

int push(Stack *A)
{
	int k;
	scanf("%d", &k);
	(A->top)++;
	(A->buf)[A->top] = k;

}
int pop(Stack *A)
{
	if (A->top == -1) printf("-1\n");
	else {
		printf("%d\n", (A->buf)[A->top]);
		(A->top)--;
	}
}
int top(Stack *A)
{
	if (A->top == -1) printf("-1\n");
	else printf("%d\n", (A->buf)[A->top]);
}

int main()
{
	Stack A;
	A.top = -1;
	int N,i=0;
	char push1[] = { 'p','u','s','h',0 };
	char pop1[] = { 'p','o','p',0};
	char size1[] = { 's','i','z','e',0 };
	char empty1[] = { 'e','m','p','t','y',0};
	char top1[] = { 't','o','p',0 };
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		char order[6];
		scanf("%s", order);
		if (strcmp(push1, order) == 0) {
			push(&A);
		}
		if (strcmp(pop1, order) == 0) {
			pop(&A);
		}
		if (strcmp(size1, order) == 0) {
			printf("%d\n", (A.top) + 1);
		}
		if (strcmp(empty1, order) == 0) {
			if (A.top == -1) printf("1\n");
			else printf("0\n");
		}
		if (strcmp(top1, order) == 0) {
			top(&A);
		}
	}
}