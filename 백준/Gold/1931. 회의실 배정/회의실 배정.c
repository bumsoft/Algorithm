#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//끝나는 시간 기준으로 정렬
typedef struct a
{
	int start;
	int end;
}A;

int compare(const void *a, const void *b)
{
	//A aa = *(A *)a; //aa가 list요소하나
	//A bb = *(A *)b;

	//(*(A*)a).start  (A*)a->start
	if ((*(A *)a).end > (*(A *)b).end) return 1;
	else if ((*(A *)a).end == (*(A *)b).end) {
		if ((*(A *)a).start > (*(A *)b).start) return 1;
		else if ((*(A *)a).start == (*(A *)b).start)return 0;
		else return -1;
	}
	else return -1;
}

int main()
{
	int N, i, j;
	A list[100000];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &list[i].start, &list[i].end);
	}
	qsort(list, N, sizeof(list[0]), compare); //end기준으로 정렬

	//처음 선택 후 start가 end보다 크면 선택
	int e = list[0].end, count=1;
	for (i = 1; i < N; i++) {
		if (list[i].start >= e) {
			count++;
			e = list[i].end;
		}
	}
	printf("%d", count);
}