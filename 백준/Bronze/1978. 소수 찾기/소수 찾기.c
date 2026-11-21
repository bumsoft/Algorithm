#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int N,i,j,k,l=1,count=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &k);
		for (j = 2; j <= sqrt(k); j++) {
			if (k % j == 0) l = 0;
		}
		if (l == 1) count++;
		if (k == 1) count--;
        l=1;
	}
	printf("%d", count);
}