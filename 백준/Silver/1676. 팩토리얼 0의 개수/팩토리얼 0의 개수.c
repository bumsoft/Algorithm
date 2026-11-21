#include <stdio.h>
int main()
{
	int N, i, k, cnt = 0;
	scanf("%d", &N);

	for (i = N; i > 0; i--) {
		k = i;
		while (k % 5 == 0) {
			k = k / 5;
			cnt++;
		}
	}
	printf("%d", cnt);
}