#include <stdio.h>
int main()
{
	int A, B, C;
	int i, j;
	int list[10] = { 0, };
	scanf("%d %d %d", &A, &B, &C);
	int X = A * B * C;
	char x[9];
	sprintf(x, "%d", X);
	for (i = 0; i < 10; i++) {
		for (j = 0; j < strlen(x); j++) {
			if (i == x[j] - '0') list[i]++;
		}
	}
	for (i = 0; i < 10; i++) printf("%d\n", list[i]);
}