#include<stdio.h>
int main()
{
    int n,i,a[101]={0},temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        a[temp]+=1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        printf("%d",a[temp]);
        if(i!=n-1)printf(" ");
    }
    return 0;
}