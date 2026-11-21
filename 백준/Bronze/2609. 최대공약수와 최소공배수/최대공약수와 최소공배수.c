#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
	int A,B,a, b, k,n;
	scanf("%d %d", &A, &B);
	a = A;
	b = B;
	if (a < b) {
		k = a;
		a = b;
		b = k;
	}
	while (b!=0) {
		n = a % b;
		a = b;
		b = n;
	}
	printf("%d\n", a);
	printf("%d", A * B / a);
}