#define _CRT_SECURE_NO_WARNINGS


/* 백준 2893 설탕 배달(실버IV)  #그리드알고리즘 #다이나믹프로그래밍 */
#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)
#define MAX 5001
#define INF 10000

int data[MAX] = { 0, };

int pack(int n)
{
    switch (n)
    {
    case 0: return 0;
    case 1: return INF;
    case 2: return INF;
    case 3: return 1;
    case 4: return INF;
    default:
        if (data[n] != 0)
            return data[n];
        return    data[n] = MIN(pack(n - 3), pack(n - 5)) + 1;
    }
}
int main(void)
{
    int n = 0, ans = 0;

    scanf("%d", &n);
    ans = pack(n);

    if (ans < INF)
        printf("%d", ans);
    else
        printf("-1");

    return 0;
}