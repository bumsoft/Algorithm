#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, N, l,a;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		char list[51];
		scanf("%s", list);
		l = strlen(list);
		a = 0;
		for (j = 0; j < l; j++) {
			if (list[j] == '(') a++;
			else a--;
			if (a < 0) break;
		}
		if (a == 0) printf("YES\n");
		else printf("NO\n");
	}
}