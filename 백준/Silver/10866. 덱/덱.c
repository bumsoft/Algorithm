#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct deque
{
	int c;
	struct deque *prev;
	struct deque *next;
}Deque;

void push_front(Deque **front,Deque**back,int X,int *count)
{
	Deque *p;
	if (*count == 0) { /*없으면 그냥 새로만들기*/
			*front = (Deque *)malloc(sizeof(Deque));
			*back = *front;
			(*front)->c = X;
			(*count)++;
			(*front)->prev = NULL;
			(*front)->next = NULL;
	}
	else { /*이미 있는 덱에 넣기*/
		(*front)->prev = (Deque *)malloc(sizeof(Deque));
		p = *front;
		*front = (*front)->prev;
		(*front)->c = X;
		(*count)++;
		(*front)->next = p;
	}
}
void push_back(Deque **front, Deque **back, int X, int *count)
{
	Deque *p;
	if (*count == 0) { /*없으면 그냥 새로만들기*/
		*front = (Deque *)malloc(sizeof(Deque));
		*back = *front;
		(*front)->c = X;
		(*count)++;
		(*front)->prev = NULL;
		(*front)->next = NULL;
	}
	else { /*이미 있는 덱에 넣기*/
		(*back)->next = (Deque *)malloc(sizeof(Deque));
		p = *back;
		*back = (*back)->next;
		(*back)->c = X;
		(*count)++;
		(*back)->prev = p;
	}
}
void pop_front(Deque **front, Deque **back, int *count)
{
	if (*count == 0) printf("-1\n");
	else {
		printf("%d\n", (*front)->c);
		(*count)--;
		if (*count == 0) {
			*front = NULL;
			*back = NULL;
		}
		else {
			*front = (*front)->next;
		}
	}
}
void pop_back(Deque **front, Deque **back, int *count)
{
	if (*count == 0) printf("-1\n");
	else {
		printf("%d\n", (*back)->c);
		(*count)--;
		if (*count == 0) {
			*front = NULL;
			*back = NULL;
		}
		else {
			*back = (*back)->prev;
		}
	}
}
int main()
{
	int N, r, X,count=0;
	char order[15];
	Deque *front = NULL, *back = NULL;
	scanf("%d", &N);
	for (r = 0; r < N; r++) {
		scanf("%s", order);
		if (strcmp(order, "push_front") == 0) {
			scanf("%d", &X);
			push_front(&front,&back,X,&count);

		}
		else if (strcmp(order, "push_back") == 0) {
			scanf("%d", &X);
			push_back(&front, &back, X, &count);
		}
		else if (strcmp(order, "pop_front") == 0) {
			pop_front(&front, &back, &count);
		}
		else if (strcmp(order, "pop_back") == 0) {
			pop_back(&front, &back, &count);
		}
		else if (strcmp(order, "size") == 0) {
			printf("%d\n", count);
		}
		else if (strcmp(order, "empty") == 0) {
			if (count == 0) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(order, "front") == 0) {
			if (count == 0) printf("-1\n");
			else {
				printf("%d\n", front->c);
			}
		}
		else if (strcmp(order, "back") == 0) {
			if (count == 0) printf("-1\n");
			else {
				printf("%d\n", back->c);
			}
		}
	}
}
