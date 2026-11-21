#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int n1 = N, n2 = N, n3 = N, n4 = N;
	double subject[1000] = { 0, };
	for (N; N != 0; N--) {
		scanf("%d", &subject[n1 - N]);
	}
	double big = 0;
	for (n1; n1 != 0; n1--) {
		if (subject[n1 - 1] > big) big = subject[n1 - 1];
	}
	double total = 0;
	for (n2; n2 != 0; n2--) {
		subject[n2 - 1] = subject[n2 - 1] / big * 100;
		total = total + subject[n2 - 1];
	}
	printf("%f", total / (double)n3);
}