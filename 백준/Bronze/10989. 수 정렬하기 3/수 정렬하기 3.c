#include <stdio.h>
int main()
{
  int N,x, i,j;
  int list[10001]={0,};
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&x);
    list[x]++;
  }
  for(i=1;i<=10000;i++){
    if(list[i]!=0){
      for(j=0;j<list[i];j++) printf("%d\n",i);
    }
  }
}