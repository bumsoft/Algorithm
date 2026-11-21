#include <stdio.h>
int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long c = a - b;
	if (c >= 0) printf("%lld", c);
	else printf("%lld", c * -1);
}