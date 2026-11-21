#include <stdio.h>
#include <math.h>
int main()
{
	int n, m, i,j;
	scanf("%d %d", &n, &m);
	char all[1000001] = { 0 };
	all[0] = 1;
	all[1] = 1;
	for (i=2; i <= sqrt(m); i++) {
		if (all[i] == 0) {
			for (j = 2; i * j <= m; j++) all[i * j] = 1;
		}
	}
	for (; n <= m; n++) {
		if (all[n] == 0) printf("%d\n", n);
	}
}