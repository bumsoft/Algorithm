#include <stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	//(가로로 자른 횟수) +1 * (세로로 자른 횟수 +1)
	if (N % 2 == 0)
	{
		printf("%d", (N / 2 + 1) * (N / 2 + 1));
	}
	else
	{
		printf("%d", (N / 2 + 2) * (N / 2 + 1));
	}
	return 0;
}