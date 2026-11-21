#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int list[11];
int dp(int N)
{
	switch (N) {
	case 1: return 1;
	case 2: return 2;
	case 3: return 4;
	}
	if (list[N] != 0) return list[N];
	else list[N] = dp(N - 1) + dp(N - 2) + dp(N - 3);
	return list[N];
}

int main()
{
	int T, i,j,N,ans;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		for (j = 0; j < N; j++) list[j] = 0;
		printf("%d\n", dp(N));
	}
}