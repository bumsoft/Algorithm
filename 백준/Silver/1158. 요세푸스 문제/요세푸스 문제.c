#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i,j,count,ck, N, K, list[5000];
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		list[i] = i + 1;
	}
	printf("<");
	ck = 0;
	count = 0;
	for (i = 0; i < N; i++) {
		if (list[i] != 0 && count < K) {
			count++;
			if (count == K) {
				printf("%d", list[i]);
				list[i] = 0;
				ck++;
				count = 0;
				if (ck == N) { 
					printf(">");
					break;
				}
				else printf(", ");
			}
		}
		if (i + 1 == N) i = -1;
	}
}