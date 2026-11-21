#include <stdio.h>
int main()
{
	int N,i;
	scanf("%d", &N);
	for (i = 0; i < N / 4; i++) printf("long ");
	printf("int");
}