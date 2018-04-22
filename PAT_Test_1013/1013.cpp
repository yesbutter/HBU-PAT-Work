#include<stdio.h>
int isper(int n)
{
    int i;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int Func(int n,int sum)
{
    int hang=10;
    while(sum>=0)
    {
        if(hang==0)hang=10;
        int flag=0;
        do
        {
            n++;
            flag=isper(n);
        }
        while(flag==0);
        if(flag==1)
        {
            hang--;
            if(sum>=1&&hang!=0)printf("%d ",n);
            if(sum>=1&&hang==0)printf("%d\n",n);
            if(sum==0)printf("%d",n);
        }
        sum--;
    }
    return 0;
}
int main()
{
    int n,sum,temp,d=1;
    scanf("%d %d",&n,&sum);
    sum=sum-n;
    temp=n;
    while(temp>1)
    {
        int flag;
        do
        {
            d++;
            flag=0;
            flag=isper(d);
        }
        while(flag==0);
        temp--;
    }

    n=d;
    Func(n,sum);
    return 0;
}
