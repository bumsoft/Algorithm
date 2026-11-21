#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, i, j=0, a = 0, b = 0, l, ll,lll;
	long long k, min = -1000000000000000001, max = 1000000000000000001;
	char c;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lld %c", &k, &c);
		if (c == 'v') {
			if (k < max) {
				max = k;
			}
			if (k <= min) {
				j = -1;
				if (a == 0) {
					l = i;
					a++;
				}
			}
			if (max - min == 1) {
				j = -1;
				if (a == 0) {
					l = i;
					a++;
				}
			}

			if (max - min == 2) {
				if (b == 0) {
					ll = i;
					b++;
				}
			}
		}
		else {
			if (k > min) {
				min = k;
			}
			if (max <= k) {
				j = -1;
				if (a == 0) {
					l = i;
					a++;
				}
			}
			if (max - min == 1) {
				j = -1;
				if (a == 0) {
					l = i;
					a++;
				}
			}
			if (max - min == 2) {
				if (b == 0) {
					ll = i;
					b++;
				}
			}
		}
	}

	if (j == -1) printf("Paradox!\n%d", l);
	else if (max - min == 2) printf("I got it!\n%d", ll);
	else printf("Hmm...");
}