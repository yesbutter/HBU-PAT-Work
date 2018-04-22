#include<stdio.h>
int funb(int a,int b)
{
    if(a<0||b<0)return 0;
    if(a>b)return funb(a-b,b);
    if(b>a)return funb(b-a,a);
    if(a==b)return a;
}
int func(int a,int b)
{
    int p=a;
    for(p=a;p<=a*b;p++)
        if(p%a==0&&p%b==0)return p;
}
int main()
{
    int n1,n2,m1,m2,k,max,temp,a[1000],count=0,i;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    max=func(m1,func(k,m2));
    n1=n1*max/m1;
    n2=n2*max/m2;
    if(n2<n1)
    {
        temp=n2;
        n2=n1;
        n1=temp;
    }
    for(n1++;n1<n2;n1++)
    {
        if(n1%(max/k)==0)
            if(funb(n1*k/max,k)==1)
        {
            a[count]=n1*k/max;
            count++;
        }
    }
    for(i=0;i<count;i++)
    {
        printf("%d/%d",a[i],k);
        if(i!=count-1)printf(" ");
    }
    return 0;
}
