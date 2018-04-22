#include<stdio.h>
int main()
{
    int n,a[102],c[102],b[102]= {0},i,j,len=0,k;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(i=1; i<=n; i++)
        c[i]=a[i];
    for(i=1; i<=n; i++)
    {
        for(k=1; k<=n; k++)
        {
            if(a[k]>0)a[k]=c[k];
        }
        if(a[i]<0)continue;
        while(a[i]!=1)
        {
            if(i==1||a[i]>0)
            {
                if(a[i]%2==0)
                {
                    a[i]=a[i]/2;
                    for(j=1; j<=n; j++)
                    {
                        if(j==i)
                            continue;
                        if(a[j]==a[i])
                            a[j]=-1;
                    }
                }
                else
                {
                    a[i]=(3*a[i]+1)/2;
                    for(j=1; j<=n; j++)
                    {
                        if(j==i)
                            continue;
                        if(a[j]==a[i])
                            a[j]=-1;
                    }
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if(a[i]>0)
            len++;
    }
    for(k=1; k<=n; k++)
    {
        if(a[k]>0)a[k]=c[k];
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<n-i+1; j++)
        {
            if(a[j+1]>a[j])
            {
                k=a[j+1];
                a[j+1]=a[j];
                a[j]=k;
            }
        }
    }
    for(i=1; i<len; i++)
        printf("%d ",a[i]);
    printf("%d",a[i]);
}
