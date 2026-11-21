#include <stdio.h>
int main()
{
	int N,i,a,b;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i+1,a + b);
	}
}