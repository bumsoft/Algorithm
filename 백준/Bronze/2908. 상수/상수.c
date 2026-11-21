#include <stdio.h>
#include <stdlib.h>	
int main()
{
	char A[4], B[4];
	int i, j;
	scanf("%s %s", A, B);
	int c = A[0];
	A[0] = A[2];
	A[2] = c;
	c = B[0];
	B[0] = B[2];
	B[2] = c;
	int a = atoi(A);
	int b = atoi(B);
	if (a > b) printf("%d", a);
	else printf("%d", b);
}