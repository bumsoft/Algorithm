#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define big(a,b) = (a>b)?a:b;

void search(char list[][101], int i, int j, int N)
{
	char t = list[i][j];
	list[i][j] = 'a';
	//상
	if (i > 0 && list[i - 1][j] == t) {
		search(list, i - 1, j, N);
	}
	//하
	if (i < N - 1 && list[i + 1][j] == t) {
		search(list, i + 1, j, N);
	}
	//좌
	if (j > 0 && list[i][j - 1] == t) {
		search(list, i, j - 1, N);
	}
	//우
	if (j < N - 1 && list[i][j + 1] == t) {
		search(list, i, j + 1, N);
	}
	else {
		return;
	}
}
int main()
{
	int N, i, j, k,count=0,count2=0;
	char list[101][101];
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%s", list[i]);
	char clist[101][101];
	for (i = 0; i < N; i++) {
		strcpy(clist[i], list[i]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (clist[i][j] == 'R') clist[i][j] = 'G';
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if(list[i][j]!='a'){
				count++;
				search(list, i, j, N);
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (clist[i][j] != 'a') {
				count2++;
				search(clist, i, j, N);
			}
		}
	}
	printf("%d %d", count,count2);
}