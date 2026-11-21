#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, B;
        scanf("%d %d", &N, &B);
        int* A = (int*)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        qsort(A, N, sizeof(int), compare);
        int count = 0;
        int budget = B;
        for (int i = 0; i < N; i++) {
            if (A[i] <= budget) {
                count++;
                budget -= A[i];
            } else {
                break;
            }
        }
        printf("Case #%d: %d\n", t, count);
        free(A);
    }
    return 0;
}
