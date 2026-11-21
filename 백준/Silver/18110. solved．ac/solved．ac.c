#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int list[300000];
int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int n, i, j;
	double sum = 0;
	scanf("%d", &n);
	if (n == 0) { printf("0"); return 0; }
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	qsort(list, n, sizeof(int), compare);
	double a;
	a = (double)n * 0.15;
	if (a - (int)a >= 0.5) a = (int)a + 1;
	else a = (int)a;
	for (i = 0; i < a; i++) { list[i] = 0; list[n - 1 - i] = 0; }
	for (i = 0; i < n; i++) sum += list[i];
	
	//for (i = 0; i < n; i++)printf("%d ", list[i]);
	double ans = sum / (n - 2 * a);
	if (ans - (int)ans >= 0.5) ans = (int)ans + 1;
	else ans = (int)ans;
	printf("%.lf", ans);
}