#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int k,kk,i,j;
	while (1) {
		int ck = 0;
		char A[6];
		scanf("%s", A);
		if (A[0] == '0') break;

		k = strlen(A);
		kk = k / 2;
		for (i = 0; i < kk; i++) {
			if (A[i] != A[k-1 - i]) {
				ck = 1;
				break;
			}
		}
		if (ck == 1)printf("no\n");
		else printf("yes\n");
	}
}