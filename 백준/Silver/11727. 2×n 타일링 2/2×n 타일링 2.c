#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[1001] = { 0, };
int dp(int n)
{
	switch (n) {
	case 0: return 0;
	case 1: return 1;
	case 2: return 3;
	}
	if (s[n] != 0) return s[n];
	s[n] = dp(n - 1)%10007 + 2*(dp(n - 2)%10007);
	return s[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", dp(n)%10007);
}