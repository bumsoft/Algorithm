#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) break;
		if (a > b) {
			if (a > c) {
				if (a * a == b * b + c * c)printf("right\n");
				else printf("wrong\n");
			}
			else {
				if (c * c == a * a + b * b) printf("right\n");
				else printf("wrong\n");
			}
		}
		else { //a<b
			if (b > c) {
				if (b * b == a * a + c * c) printf("right\n");
				else printf("wrong\n");
			}
			else {
				if (c * c == a * a + b * b)printf("right\n");
				else printf("wrong\n");
			}
		}
	}
}