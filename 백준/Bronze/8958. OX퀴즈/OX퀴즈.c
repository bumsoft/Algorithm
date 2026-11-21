#include <stdio.h>
#include <string.h>
int main()
{
	int N,i,j,k;
	char list[80];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", list);
		int score = 0,scoreck,scorel=0;
		for (j = 0; j < strlen(list); j++) {
			if (list[j] == 'O') {
				score++;
				scoreck = 1;
				if (scoreck == 1) score += scorel;
				scorel++;
			}
			if (list[j] == 'X') {
				scoreck = 0;
				scorel = 0;
			}
		}
		printf("%d\n", score);
	}
}