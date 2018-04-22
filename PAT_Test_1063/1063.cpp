#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    double max=0,temp,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&a,&b);
        temp=sqrt(a*a+b*b);
        if(temp>max)
            max=temp;
    }
    printf("%0.2lf",max);
    return 0;
}