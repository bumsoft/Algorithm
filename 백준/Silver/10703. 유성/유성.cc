#include <bits/stdc++.h>
using namespace std;
using ll = long long;


char img[3000][3000];
int R, S;

int meteor_s = -1; //유성시작높이
int meteor_e = -1; //유성끝높이

int land_s = -1; //땅 시작높이
int land_e; //땅 끝 높이

int meteor[3000]; //각 열별 유성의 가장 낮은 위치
int land[3000];


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> S;

	land_e = R-1;
	for (int i = 0; i < S; i++)
	{
		meteor[i] = -1;
		land[i] = -1;
	}
	
	bool line_check;
	for (int i = 0; i < R; i++)
	{
		line_check = false;
		for (int j = 0; j < S; j++)
		{
			cin >> img[i][j];
			if (img[i][j] == 'X') line_check = true; //행에 유성 있는지 여부

			if (img[i][j] == 'X' && meteor_s == -1) //첫 X
			{
				meteor_s = i;
			}

			if (img[i][j] == 'X')
			{
				meteor[j] = i;
			}
			///////////////////////////
			//land
			if (img[i][j] == '#')
			{
				if (land[j] == -1)
				{
					land[j] = i;
				}
				if (land_s == -1) land_s = i;
			}
		}
		if (meteor_e == -1 && meteor_s != -1 && !line_check) //행에 유성이 없고, 이전 행에 있었음
		{
			meteor_e = i - 1;
		}
	}

	int move = 30000;

	for (int i = 0; i < S; i++)
	{
		if (meteor[i] == -1) continue;
		move = min(land[i] - meteor[i], move);
	}
	move--;
	//move만큼 유성을 옮겨야함
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < S; j++)
		{
			if (i-move >= 0 && img[i-move][j] == 'X')
			{
				cout << img[i - move][j];
				continue;
			}
			if (img[i][j]=='#')
			{
				cout << '#';
			}
			else
			{
				cout << '.';
			}
		}
		cout << '\n';
	}
}