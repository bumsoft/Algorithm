#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k=0;
	char string[1000001];
	gets(string);
	for (i = 0; i < strlen(string); i++) {
		if (string[i] != 32 && string[i + 1] == 32) k++;
		else if (string[i] != 32 && string[i + 1] == NULL)k++;
	}
	printf("%d", k);
}