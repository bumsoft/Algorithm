#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int list[500000];
int flist[8001] = { 0, };
int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int N, i, sum=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &list[i]);
		sum += list[i];
		flist[list[i] + 4000]++;
	}
	qsort(list, N, sizeof(int), compare);
	int max = 0;
	int min = 4001;
	int temp,ck=0;
	for (i = 0; i < 8001; i++) { 
		if (flist[i] > max) max = flist[i];
	}
	for (i = 0; i < 8001; i++) {
		if (flist[i] == max &&i-4000<min) {
			min = i - 4000;
			temp = i;
		}
	}
	int mmin = 4001;
	for (i = 0; i < 8001; i++) {
		if (i == temp)continue;
		if (flist[i] == max && i - 4000 < mmin) {
			mmin = i - 4000;
			ck = 1;
			break;
		}
	}
	double s = (double)sum / (double)N;
	if (s<0 && s>-0.5) s = 0;
	printf("%.0lf\n", s);//산술평균
	printf("%d\n", list[N / 2]);//중앙값
	printf("%d\n", (ck == 0) ? min : mmin);
	printf("%d", list[N - 1] - list[0]);
}