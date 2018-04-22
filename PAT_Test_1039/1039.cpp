#include<stdio.h>
int main()
{
    int len=0,a[128]={0},queshao=0,count=0;
    char temp;
    do
    {
        scanf("%c",&temp);
        a[(int)temp]+=1;
        len++;
    }while(temp!='\n');
    do
    {
        scanf("%c",&temp);
        if(a[(int)temp])
        {
            a[(int)temp]-=1;
        }
        else queshao++;
        count++;
    }while(temp!='\n');
    if(queshao==0)
        printf("Yes %d",len-count);
    else printf("No %d",queshao);
    return 0;
}