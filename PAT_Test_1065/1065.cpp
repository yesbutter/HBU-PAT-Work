#include<stdio.h>
struct couple//记录情侣
{
    int man;
    int woman;
    int flag;
};
int main()
{
    int n,m,i,j,book[1000],count=0,temp[10000],flag1=0,p,flag2=0,flag3=0;//n,m分别表示情侣对数和参加派对总人数
    scanf("%d",&n);
    struct couple people[n];
    for(i=0; i<n; i++)
        scanf("%d %d",&people[i].man,&people[i].woman);
    scanf("%d",&m);
    for(i=0; i<n; i++)
        people[i].flag=0;
    for(i=0; i<m; i++)
        scanf("%d",&temp[i]);
    for(i=0; i<n; i++)//是否有情侣在参加派对的人员里面，如果有成对的将结构体里面的flag置为2.
    {
        for(j=0; j<m; j++)
        {
            if((temp[j]==people[i].man||temp[j]==people[i].woman)&&people[i].flag)
                people[i].flag=2;
            if((temp[j]==people[i].man||temp[j]==people[i].woman)&&!people[i].flag)
                people[i].flag=1;
        }
    }
    for(j=0; j<m; j++)//循环判断输出条件是否满足，分成俩种情况，一种是参加宴会的人有对象，判断对象是否也同时参加派对，另外一种是没有对象。
    {
        flag1=0,flag2=0,flag3=0;
        for(i=0; i<n; i++)
        {
            if(temp[j]==people[i].man||temp[j]==people[i].woman)
            {
                if(people[i].flag!=2)flag1=1;
            }
            if(temp[j]!=people[i].man)flag2++;
            if(temp[j]!=people[i].woman)flag3++;
        }
        if(flag1||(flag2==flag3&&flag2==n))//判断输出条件是否满足，如果满足存入数组。
        {
            book[count]=temp[j];
            count++;
        }
    }
    for(i=0; i<count; i++)//冒泡排序
        for(j=0; j<count-i-1; j++)
        {
            if(book[j]>book[j+1])
            {
                p=book[j];
                book[j]=book[j+1];
                book[j+1]=p;
            }
        }
    printf("%d\n",count);
    for(i=0; i<count; i++)
    {
        printf("%d",book[i]);
        if(i!=count-1)printf(" ");
    }
    return 0;
}