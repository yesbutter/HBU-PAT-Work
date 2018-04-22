#include<stdio.h>
void swapc(int *a,int *b)
{
    int swap;
    swap=*a;
    *a=*b;
    *b=swap;
}
int main()
{
    int g1,s1,k1,g2,s2,k2,flag=0;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    if(g1-g2>0||(g1-g2==0&&s1-s2>0)||(g1-g2==0&&s1-s2==0&&k1-k2>0))
    {
        flag=1;
        swapc(&s1,&s2);
        swapc(&g1,&g2);
        swapc(&k1,&k2);
    }
    if(k2>=k1)
        k2=k2-k1;
    else
    {
        s2--;
        k2=k2-k1+29;
    }
    if(s2>=s1)
        s2=s2-s1;
    else
    {
        g2--;
        s2=s2-s1+17;
    }
    if(flag==1)printf("-");
    printf("%d.%d.%d",g2-g1,s2,k2);
    return 0;
}