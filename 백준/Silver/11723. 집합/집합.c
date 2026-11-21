#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int N, i,j, S[21] = { 0 };
	char order[7];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", order);

		if (strcmp(order, "add")==0) {
			scanf("%d", &j);
			S[j] = 1; //
		}
		else if (strcmp(order, "remove") == 0) {
			scanf("%d", &j);
			S[j] = 0;
		}
		else if (strcmp(order, "check") == 0) {
			scanf("%d", &j);
			if (S[j] == 1)printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(order, "toggle") == 0) {
			scanf("%d", &j);
			if (S[j] == 1) S[j] = 0;
			else S[j] = 1;
		}
		else if (strcmp(order, "all") == 0) {
			for (j = 1; j < 21; j++) S[j] = 1;
		}
		else if (strcmp(order, "empty") == 0) {
			for (j = 1; j < 21; j++) S[j] = 0;
		}
	}
}