#include <iostream>
#include <cstring>
using namespace std;

char S[1000001];
char T[27];
int t[26];
int main()
{
	cin >> S;
	cin >> T;
	int Slen = strlen(S);
	int Tlen = strlen(T);
	
	for (int i = 0; i < Slen; i++) {
		for (int j = 0; j < Tlen; j++) {
			if (S[i] == T[j]) {
				if (j == 0)t[0]++;
				else if (t[j] >= t[j - 1]) break;
				else t[j]++;
			}
		}
	}
	cout << t[Tlen-1];
}