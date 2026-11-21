#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[100000];
int main()
{
	int t,T, i, n,temp;
    char c;
    scanf("%d", &T);
	for (t = 0; t < T; t++) {
		char order[100001];
        
		scanf("%s %d", order,&n);

        if (n != 0) {
            scanf(" %c", &c);
            for (int i = 0; i < n; i++) {
                scanf("%d", &temp); 
                getchar();
                num[i] = temp;
            }
        }
        else
            scanf(" %c %c", &c, &c);
        int l = strlen(order);
        int ck = 0, front = 0, back = n - 1;
        for (i = 0; i < l; i++) {
            if (order[i] == 'R' && ck == 0) ck = -1;
            else if (order[i] == 'R' && ck == -1) ck = 0;
            else if (order[i] == 'D' && ck == 0) { front++; if (front-1 > back) { printf("error\n"); ck = 7; break; } }
            else if (order[i] == 'D' && ck == -1) { back--; if (front > back+1) { printf("error\n"); ck = 7; break; } }
        }
        if (ck == 7)continue;
        else if (back - front == -1) { printf("[]\n"); continue; }
        else if (ck == 0) {
            printf("[");
            for (i = front; i < back; i++)printf("%d,", num[i]);
            printf("%d]\n", num[back]);
        }
        else if (ck == -1) {
            printf("[");
            for (i = back; i > front; i--)printf("%d,", num[i]);
            printf("%d]\n", num[front]);
        }
	}
}