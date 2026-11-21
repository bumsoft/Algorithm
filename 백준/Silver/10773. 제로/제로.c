#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int push(int* list, int *top, int k ) {
	(*top)++;
	*(list+ *top) = k;
}
int pop(int* top, int k){
	if (*top == -1) return;
	else (*top)--;
}
int main()
{
	int KK, i, j, k, top = -1, * list, sum = 0;
	scanf("%d", &KK);
	list = (int*)malloc(KK * sizeof(int));
	for (i = 0; i < KK; i++) {
		scanf("%d", &k);
		if (k != 0) push(list,&top, k);
		else pop(&top,k);
	}
	for (i = 0; i <= top; i++) {
		sum += *(list+i);
	}
	printf("%d", sum);
}