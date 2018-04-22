#include<stdio.h>
int func(int n)
{
    int i,temp,p;
    p=(n+1)/2;
    for(i=2,temp=1; temp<=p; i++)
        temp=temp+(2*i-1);
    return i-2;
}
int main()
{
    char c;
    int n,i,j,k,temp,count=0;
    scanf("%d ",&n);
    c=getchar();
    temp=func(n);
    for(i=temp; i>0; i--)
    {
        for(k=temp-i; k>0; k--)
            printf(" ");
        for(j=2*i-1; j>0; j--)
        {
            printf("%c",c);
            count++;
        }
        printf("\n");
    }
    for(i=2; i<=temp; i++)
    {
        for(k=i; k<temp; k++)
            printf(" ");
        for(j=2*i-1; j>0; j--)
        {
            printf("%c",c);
            count++;
        }
        printf("\n");
    }
    printf("%d",n-count);
    return 0;
}