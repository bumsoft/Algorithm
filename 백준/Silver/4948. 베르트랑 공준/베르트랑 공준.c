#include <stdio.h>
#include <math.h>
#define max 246912
int all[246913] = { 1,1, };

int main()
{
	int N, i, j,cnt;
	double m = sqrt(max);
	for (i = 2; i <= m; i++) {
		if (all[i] == 0) {
			for (j = 2; i * j <= max; j++)all[i*j] = 1;
		}
	}
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		cnt = 0;
		for (i = N + 1; i <= 2 * N; i++) {
			if (all[i] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
}