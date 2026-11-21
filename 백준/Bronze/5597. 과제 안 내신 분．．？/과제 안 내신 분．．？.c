#include <stdio.h>
int main()
{
	int i, j;
	int list[31] = { 1, };
	for (i = 1; i <= 28; i++) {
		scanf("%d", &j);
		list[j] = 1;
	}
	for (i = 1; i <= 30; i++) {
		if (list[i] == 0) printf("%d\n", i);
	}
}