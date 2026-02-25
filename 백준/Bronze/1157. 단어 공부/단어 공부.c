#include <stdio.h>
#include <string.h>
int main()
{
	char word[1000001];
	scanf("%s", word);
	char alp[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',0};
	char ALP[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',0 };
	int num[26] = { 0, };
	int i,j,most=0,k,p=0;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < strlen(word); j++) {
			if (alp[i] == word[j] || ALP[i] == word[j]) num[i]++;
		}
	}
	for (i = 0; i < 26; i++) {
		if (num[i] == most && num[i] != 0) p = 1;
		if (num[i] > most) {
			most = num[i];
			k = i;
			p = 0;
		}
	}
	if (p == 1) printf("?");
	else printf("%c", ALP[k]);
}