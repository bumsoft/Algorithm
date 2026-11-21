#include <stdio.h>
int main()
{
	int C, N, i, j,sum=0;
	double aver;
	int list[1000];
	scanf("%d", &C);
	for (i = 0; i < C; i++) {
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			scanf("%d", &list[j]);
			sum += list[j];
		}
		int cnt = 0;
		aver = (double)sum / (double)N;
		for (j = 0; j < N; j++) {
			if (list[j] > aver) cnt++;
		}
		printf("%.3lf%%\n", (double)cnt / (double)N * 100);
		sum = 0;
	}
}