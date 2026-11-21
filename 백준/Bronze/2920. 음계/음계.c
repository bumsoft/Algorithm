#include <stdio.h>
#include <string.h>
int main()
{
	int asc[] = { 1,2,3,4,5,6,7,8};
	int dsc[] = { 8,7,6,5,4,3,2,1};
	int input[8];
	int i,V=0;
	for (i = 0; i < 8; i++) scanf("%d", &input[i]);

	for (i = 0; i < 8; i++) {
		if (input[i] == asc[i]) V += 10;
		else if (input[i] == dsc[i]) V += 1000;
		else V = -10000;
	}
	if (V == 80) printf("ascending");
	else if (V == 8000) printf("descending");
	else printf("mixed");
}