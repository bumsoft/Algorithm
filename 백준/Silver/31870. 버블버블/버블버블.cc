#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
int arr1[1000];
int arr2[1000];
int arr3[1000]; // 뒤집어져있는거


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr1[i];
		arr3[N-i-1] = arr2[i] = arr1[i];
	}
	//오름차순 버블정렬
	int first = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			if (arr1[j] > arr1[j + 1])
			{
				first++;
				int temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}

	//내림차순 버블정렬
	int sec = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr2[j] < arr2[j + 1])
			{
				sec++;
				int temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}

	// 뒤집고 버블정렬
	int thr = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr3[j] > arr3[j + 1])
			{
				thr++;
				int temp = arr3[j];
				arr3[j] = arr3[j + 1];
				arr3[j + 1] = temp;
			}
		}
	}
	cout << min({ first,sec,thr });

	return 0;
}