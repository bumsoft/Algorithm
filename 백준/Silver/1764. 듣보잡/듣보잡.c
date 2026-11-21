#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sound[500000][21];
char all[500000][21];
char temp[21];

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
int main()
{
	int N, M,i,j,k=0,ck;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", sound[i]);
	//듣도 못한 명단 사전순 정렬.
	qsort(sound, N, sizeof(sound[0]), compare);
	int start, end,mid;
	for (i = 0; i < M; i++) {
		scanf("%s", temp); // 보도못한 사람을 듣도못한 명단에서 이분탐색.
		start = 0, end = N - 1, mid = (start + end) / 2;
		ck = 0;
		while (start <= end) {
			if (strcmp(temp, sound[mid]) > 0) {
				start = mid + 1;
				mid = (start + end) / 2;
			}
			else if (strcmp(temp, sound[mid]) < 0) {
				end = mid - 1;
				mid = (start + end) / 2;
			}
			else {
				ck = 1;
				break;
			}
		}
		if (ck == 1) {
			strcpy(all[k], temp);
			k++;
		}
	}
	qsort(all, k, sizeof(all[0]), compare);
	printf("%d\n", k);
	for (i = 0; i < k; i++) printf("%s\n", all[i]);
}