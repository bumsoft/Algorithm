#include <stdio.h>
#include <string.h>
int main()
{
	int M, N;
	scanf("%d %d", &N, &M);
	int i, j, k,l;
	char board[50][51];
	for (i = 0; i < N; i++) {
			scanf("%s", board[i]);
	}
	char board_copy[50][51];
	for (i = 0; i < N; i++) {
		strcpy(board_copy[i], board[i]);
	}
	for (i = 0; i < N; i+=2) {
		for (j = 0; j < M; j+=2) {
			if (board[i][j] != 'W') {
				board[i][j] = 'K';
			}
		}
		for (j = 1; j < M; j += 2) {
			if (board[i][j] != 'B') {
				board[i][j] = 'K';
			}
		}
	}
	for (i = 1; i < N; i += 2) {
		for (j = 0; j < M; j += 2) {
			if (board[i][j] != 'B') {
				board[i][j] = 'K';
			}
		}
		for (j = 1; j < M; j += 2) {
			if (board[i][j] != 'W') {
				board[i][j] = 'K';
			}
		}
	}
	for (i = 0; i < N; i += 2) {
		for (j = 0; j < M; j += 2) {
			if (board_copy[i][j] != 'B') {
				board_copy[i][j] = 'K';
			}
		}
		for (j = 1; j < M; j += 2) {
			if (board_copy[i][j] != 'W') {
				board_copy[i][j] = 'K';
			}
		}
	}
	for (i = 1; i < N; i += 2) {
		for (j = 0; j < M; j += 2) {
			if (board_copy[i][j] != 'W') {
				board_copy[i][j] = 'K';
			}
		}
		for (j = 1; j < M; j += 2) {
			if (board_copy[i][j] != 'B') {
				board_copy[i][j] = 'K';
			}
		}
	}
	int min=100;
	int count = 0;
	for (i = 0; i <= N - 8; i++) {
		for (j = 0; j <= M - 8; j++) {
			for (k = i; k < i + 8; k++) {
				for (l = j; l < j + 8; l++) {
					if (board[k][l] == 'K') count++;
				}
			}
			if (min > count) min = count;
			count = 0;
		}
	}
	for (i = 0; i <= N - 8; i++) {
		for (j = 0; j <= M - 8; j++) {
			for (k = i; k < i + 8; k++) {
				for (l = j; l < j + 8; l++) {
					if (board_copy[k][l] == 'K') count++;
				}
			}
			if (min > count) min = count;
			count = 0;
		}
	}
	printf("%d", min);
}