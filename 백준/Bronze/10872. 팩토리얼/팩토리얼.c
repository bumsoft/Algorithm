#include <stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	int x = 1;
	for (int i = 0; i < N; i++) {
		x *= N - i;
	}
	printf("%d", x);
}