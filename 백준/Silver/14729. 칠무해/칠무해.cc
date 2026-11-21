#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N; scanf("%d",&N);
	double temp;
	priority_queue<double> PQ;
	while (N--)
	{
		scanf("%lf",&temp);
		PQ.push(-temp);
	}
	for (int i = 0; i < 7; i++)
	{
		printf("%.3lf\n", -PQ.top());
		PQ.pop();
	}
}