#include <stdio.h>
#include <string.h>
int main()
{
	char S[21];
	int T,R,i,j,k;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %s", &R, S);
		for (j = 0; j < strlen(S); j++) {
			for (k = 0; k < R; k++) {
				printf("%c", S[j]);
			}
		}
     printf("\n");
	}
}