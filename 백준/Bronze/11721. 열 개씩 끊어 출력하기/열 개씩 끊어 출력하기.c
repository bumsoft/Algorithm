#include <stdio.h>
#include <string.h>
int main()
{
	char list[101];
	scanf("%s", list);
	int len = strlen(list);
	int i, j, k=0;
	for (i = 0; i < len / 10 + 1; i++) {
		for (j = i*10; j < i*10 +10; j++) {
			if (len > j+1) {
				printf("%c", list[j]);
			}
			else if (len == j+1) {
				printf("%c", list[j]); 
				k = 1;
			}
			else k = 1;
		}
		if (k != 1) {
			printf("\n");
		}
	}
}