#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* 백준 12931 두 배 더하기*/
/* A=>B가 아닌, B=>A로 가는 과정을 구하는게 해결방법*/
int main()
{
	int N, i, j=0, count = 0;
	int list_A[50] = { 0, };
	int list_B[50] = { 0, };
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &list_B[i]);
	}
	while (1) {
		if (memcmp(list_A, list_B, 4 * N) == 0) break;
		for (i = 0; i < N; i++) {
			if (list_B[i] % 2 == 1) {
				list_B[i]--;
				count++;
			}
		}
		if (memcmp(list_A, list_B, 4 * N) == 0) break;
		for (i = 0; i < N; i++) {
			list_B[i] = list_B[i] / 2;
		}
		count++;
		if (memcmp(list_A, list_B, 4 * N) == 0) break;
	}
	printf("%d", count);
}