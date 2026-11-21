#include <stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = N-1; i>=0; i--) {
		printf("%d\n", N - i);
	}
}