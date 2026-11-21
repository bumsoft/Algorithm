#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
int main()
{
	int i, j;
	char ALPA[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',0 };
	int alpa[26] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	char S[101];
	scanf("%s", S);
	for (i = 0; i < 26; i++) {
		for (j = 0; j < strlen(S); j++) {
			if (ALPA[i] == S[j] && alpa[i]==-1) alpa[i] = j;
		}
	}
	for (i = 0; i < 26; i++) printf("%d ", alpa[i]);
}