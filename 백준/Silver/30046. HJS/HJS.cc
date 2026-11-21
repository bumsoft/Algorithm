#include <iostream>

using namespace std;

char P[300001];
char Q[300001];
char R[300001];
int now;
int len;
int main()
{
	cin >> len;
	cin >> P;
	cin >> Q;
	cin >> R;
	char temp,temp2;
	while (now < len)
	{
		//다 다른경우
		if ((P[now] != Q[now]) && (P[now] != R[now]))
		{
			if (Q[now] != R[now])
			{
				cout << "HJS! HJS! HJS!";
				return 0;
			}
		}

		// P Q R 다 같은경우
		if ((P[now] == Q[now]) && (P[now] == R[now]))
		{
			now++;
			continue;
		}
		//P Q 만 같은 경우
		else if ((P[now] == Q[now]) && (P[now] != R[now]))
		{
			temp = R[now];
			temp2 = P[now];
			now++;

			while (now < len)
			{
				if (P[now] != Q[now])
				{
					if ((P[now] == temp) && (temp2 == Q[now]))
					{
						cout << "Hmm...";
						return 0;
					}
					cout << "HJS! HJS! HJS!";
					return 0;
				}
				now++;
			}
		}
		//P R이 같은 경우
		else if ((P[now] == R[now]) && (P[now] != Q[now]))
		{
			cout << "Hmm...";
			return 0;
		}
		//Q R이 같은 경우
		else
		{
			temp = P[now];
			temp2 = Q[now];
			now++;
			while (now < len)
			{
				if (R[now] != Q[now])
				{
					if ((R[now] == temp) && (Q[now] == temp2))
					{
						cout << "Hmm...";
						return 0;
					}
					cout << "HJS! HJS! HJS!";
					return 0;
				}
				now++;
			}
		}
	}
	cout << "Hmm...";
}