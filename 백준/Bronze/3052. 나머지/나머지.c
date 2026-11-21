#include <stdio.h>
int main()
{
	int i, j, k=0;
	int list[42] = { 0, };
	for (i = 0; i < 10; i++) {
		scanf("%d", &j);
		list[j % 42] = 1;
	}
	for (i = 0; i < 42; i++) {
		if (list[i] == 1) k++;
	}
	printf("%d", k);
}