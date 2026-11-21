#include <bits/stdc++.h>
using namespace std;
int N, ma, zero, pl;
int matrix[2187][2187];
void cut(int xstart, int ystart, int n)
	{
		int temp = matrix[ystart][xstart];
		bool d = true;
		for(int i=ystart;i<ystart+n;i++)
		{
			for(int j=xstart;j<xstart+n;j++)
			{
				if(matrix[i][j]!=temp)
				{
					d = false;
					break;
				}
			}
			if(!d) break;
		}
		if(d)
		{
			switch(temp)
			{
			case -1: ma++;return;
			case 0: zero++;return;
			case 1:pl++;return;
			}
		}
		cut(xstart,ystart,n/3);
		cut(xstart+n/3,ystart,n/3);
		cut(xstart+2*n/3,ystart,n/3);
		
		cut(xstart,ystart+n/3,n/3);
		cut(xstart+n/3,ystart+n/3,n/3);
		cut(xstart+2*n/3,ystart+n/3,n/3);
		
		cut(xstart,ystart+2*n/3,n/3);
		cut(xstart+n/3,ystart+2*n/3,n/3);
		cut(xstart+2*n/3,ystart+2*n/3,n/3);
		
	}
int main() 
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>> matrix[i][j];
		}
	}
	cut(0,0,N);
	cout << ma << endl << zero << endl << pl;
}
