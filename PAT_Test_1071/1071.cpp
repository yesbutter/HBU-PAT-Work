#include<stdio.h>
int judge(int a,int b,int t)
{
    if(t&&b>a)return 1;
    if(!t&&a>b)return 1;
    return 0;
}
int main()
{
    int T,K,n1,b,t,n2;
    scanf("%d %d",&T,&K);
    while(K--)
    {
        scanf("%d %d %d %d",&n1,&b,&t,&n2);
        if(T<t)
        {
            printf("Not enough tokens.  Total = %d.\n",T);
            continue;
        }
        if(judge(n1,n2,b))
        {
            printf("Win %d!  Total = %d.\n",t,T+t);
            T+=t;
        }
        else
        {
            printf("Lose %d.  Total = %d.\n",t,T-t);
            T-=t;
        }
        if(T==0)break;
    }
    if(T==0)printf("Game Over.");
    return 0;
}
