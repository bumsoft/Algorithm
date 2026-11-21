#include <stdio.h>
int main()
{
	int day=0, k=0, A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	k = (V / (A - B)) * (A - B) - (A-B);
	for (; k + A > V;) {
		k -= A - B;
	}
	day = k/(A-B);
	while (1) {
		if (k < V) {
			k += A;
			day++;
			if (k >= V) break;
			k -= B;
		}
	}
	printf("%d", day);
}