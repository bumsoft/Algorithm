#include <stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	int NN = N;
	int count = 0;
	int n1,n2,n3,n4;
	while (1) {
		n1 = N / 10;
		n2 = N % 10;
		n3 = n1 + n2;
		count++;
		n4 = n2*10 + n3 % 10;
		N = n4;
		if (n4 == NN) break;
	}
	printf("%d", count);
}