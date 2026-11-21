#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char S[1000001];

int main()
{
	int N, M, i, j, k,count=0,ll;
	scanf("%d %d %s", &N, &M,S);
	int n = 2 * N + 1;
	for (i = 0; i < M; i++) {
		if (S[i] == 'I') {
			k = 1;
			ll = 1;
			for (j = i + 1; ; j++) {
				if (k == 1) {
					if (S[j] != 'O') break;
					else { k = 0; ll++; }
				}
				else if (k == 0) {
					if (S[j] != 'I') { ll--; break; }
					else { k = 1; ll++; }
				}
			}
			if (ll == n) { count++; i = j - 1; }
			else if (ll > n) { count += 1 + (ll - n) / 2; i = j - 1; }
			else i = j - 1;
		}
	}
	printf("%d", count);
}