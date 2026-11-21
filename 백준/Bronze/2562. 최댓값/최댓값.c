#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a,big=0,num=0;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &a);
		if (big < a) {
			big = a;
			num = i;
		}

	}
	printf("%d\n%d", big, num);
}