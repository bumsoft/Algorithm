#include <iostream>
using namespace std;

long N, A, Pa, B, Pb;

int main()
{
	cin >> N >> A >> Pa >> B >> Pb;

	long temp = 0;
	long max = 0;

	long cntAA = 0;
	long cntBB = 0;

	long ansA=0;
	long ansB=0;
	for(int i=0;i<N;i++)
	{
		cntAA = (N - i) / Pa;
		cntBB = i / Pb;
		temp = cntAA * A + cntBB * B;

		if (temp > max)
		{
			max = temp;
			ansA = cntAA;
			ansB = cntBB;
		}
	}
	cout << ansA << ' ' << ansB;
}