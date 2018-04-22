#include<stdio.h>
int main()
{
  int n,i,a,b,c;
  scanf("%d",&n);
  a=n/100;
  c=n%10;
  b=(n-a*100)/10;
  for(i=1;i<=a;i++)
    printf("B");
  for(i=1;i<=b;i++)
    printf("S");
  for(i=1;i<=c;i++)
    printf("%d",i);
  return 0;
}