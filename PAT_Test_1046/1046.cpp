#include<stdio.h>
int main()
{
    int jia=0,yi=0,a,b,c,d,n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(b==a+c&&d!=b)
            yi++;
        if(d==a+c&&d!=b)
            jia++;
    }
    printf("%d %d",jia,yi);
    return 0;
}