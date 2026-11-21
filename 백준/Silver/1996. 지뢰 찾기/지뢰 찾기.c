#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char map[1005][1005];
int main()
{
	int N,i,j;
	scanf("%d", &N);
	for (i = 0; i < 1005; i++) {
		for (j = 0; j < 1005; j++) {
			map[i][j] = 0;
		}
	}
	char maps[1005][1005];
	for (i = 0; i < 1005; i++) {
		for (j = 0; j < 1005; j++) {
			maps[i][j] = 0;
		}
	}
	for (i = 2; i < N+2; i++) {
		scanf("%s", &map[i][2]);
	}
	for (i = 2; i < N + 2; i++) {
		for (j = 2; j < N + 2; j++) {
			if (map[i][j] - '0' == 1) {
				maps[i][j] = 1;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 2) {
				maps[i][j] = 2;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 3) {
				maps[i][j] = 3;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 4) {
				maps[i][j] = 4;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 5) {
				maps[i][j] = 5;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 6) {
				maps[i][j] = 6;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 7) {
				maps[i][j] = 7;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 8) {
				maps[i][j] = 8;
				map[i][j] = 100;
			}
			else if (map[i][j] - '0' == 9) {
				maps[i][j] = 9;
				map[i][j] = 100;
			}
		}
	}
	for (i = 2; i < N + 2; i++) {
		for (j = 2; j < N + 2; j++) {
			if (map[i][j] == '.') {
				map[i][j] = maps[i - 1][j - 1] + maps[i - 1][j] + maps[i - 1][j + 1] + maps[i][j - 1] + maps[i][j + 1] + maps[i + 1][j - 1] + maps[i + 1][j] + maps[i + 1][j + 1];
				if (map[i][j] >= 10) map[i][j] = 'M';
			}
		}
	}
	for (i = 2; i < N + 2; i++) {
		for (j = 2; j < N + 2; j++) {
			if (map[i][j] == 100) maps[i][j] = '*';
			else if (map[i][j] == 'M') maps[i][j] = 'M';
			else maps[i][j] = map[i][j];
		}
	}


	for (i = 2; i < N + 2; i++) {
		for (j = 2; j < N + 2; j++) {
			if (maps[i][j] == '*') printf("%c", maps[i][j]);
			else if (maps[i][j] == 'M') printf("%c", maps[i][j]);
			else printf("%d", maps[i][j]);
		}
		printf("\n");
	}
}