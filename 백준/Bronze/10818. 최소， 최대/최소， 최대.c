#include <stdio.h>
int list[1000000];
int main()
{
	int N,big=-1000000,small=1000000;
	scanf("%d", &N);
	for (int j = 0; j < N; j++) scanf("%d", &list[j]);
	for (int i = 0; i < N; i++) {
		if (small > list[i]) small = list[i];
		if (big < list[i]) big = list[i];
	}
	printf("%d %d", small,big);
}