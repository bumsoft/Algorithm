#include <stdio.h>
int main()
{
	int i,j;
	while (scanf("%d %d", &i, &j) != EOF) {
		if (i == EOF || j == EOF) return;
		printf("%d\n", i + j);
	}
}