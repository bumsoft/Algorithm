#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int list[1000000];
int compare(const void*a,const void*b)
{
  return *(int*)b - *(int*)a;
}


int main()
{
  int N, i,j,k;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&list[i]);
  qsort(list,N,sizeof(int),compare);
  for(i=0;i<N;i++)printf("%d\n",list[i]);
}