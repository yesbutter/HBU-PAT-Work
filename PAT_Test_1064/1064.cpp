#include<stdio.h>
#include<string.h>
int func(char c[])
{
    int len,i,sum=0;
    len=strlen(c);
    for(i=0;i<len;i++)
        sum+=c[i]-48;
    return sum;
}
int main()
{
    int n,i,book[100]={0},count,temp,j,flag;
    scanf("%d",&n);
    getchar();
    char a[6];
    for(i=0,count=0;i<n;i++)
    {
        scanf("%6s",a);
        temp=func(a);
        for(j=0,flag=1;j<count;j++)
            if(temp==book[j])flag=0;
        if(flag)
        {
            book[count]=temp;
            count++;
        }
    }
    for(i=0;i<count;i++)
        for(j=0;j<count-i-1;j++)
    {
        if(book[j]>book[j+1])
        {
            temp=book[j];
            book[j]=book[j+1];
            book[j+1]=temp;
        }
    }
    printf("%d\n",count);
    for(i=0;i<count;i++)
    {
        printf("%d",book[i]);
        if(i!=count-1)printf(" ");
    }
    return 0;
}