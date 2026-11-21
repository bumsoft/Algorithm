#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char list[101];
	int i, cnt = 0;
	scanf("%s", list);
	int len = strlen(list);
	for (i = 0; i < len; i++) {
		if (i + 1 < len && list[i] == 'c') {
			if (list[i + 1] == '=' || list[i + 1] == '-') { cnt++; i++; }
			else cnt++;
		}


		else if (i + 1 < len && list[i] == 'd') {
			if (list[i + 1] == '-') { cnt++; i++; }
			else if (list[i + 1] == 'z' && i + 2 < len) {
				if (list[i + 2] == '=') { cnt++; i = i + 2; }
				else cnt++;
			}
			else cnt++;
		}


		else if (i + 1 < len && list[i] == 'l') {
			if (list[i + 1] == 'j') { cnt++; i++; }
			else cnt++;
		}


		else if (i + 1 < len && list[i] == 'n') {
			if (list[i + 1] == 'j') { cnt++; i++; }
			else cnt++;
		}


		else if (i + 1 < len && list[i] == 's') {
			if (list[i + 1] == '=') { cnt++; i++; }
			else cnt++;
		}


		else if (i + 1 < len && list[i] == 'z') {
			if (list[i + 1] == '=') { cnt++; i++; }
			else cnt++;
		}

		else cnt++;
	}


	printf("%d", cnt);
}