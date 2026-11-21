#include <stdio.h>
int main()
{
	int data[100];
	int N, V=0, i,j=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &V);
	for (i = 0; i < N; i++) {
		if (V == data[i]) j++;
	}
	printf("%d", j);
}