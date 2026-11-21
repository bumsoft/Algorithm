#include <stdio.h>
int main()
{
	int a, n, c, d, e, total = 0;
	scanf("%d %d", &a, &n);
	for (c = 0; c < n; c++) {
		scanf("%d %d",&d,&e);
		total += d * e;
	}
	if (total == a) printf("Yes");
	else printf("No");
}