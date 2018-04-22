#include<stdio.h>
int main()
{
    int people,number,grade[100],right[100],i,sum[100]={0},j,temp;
    scanf("%d %d",&people,&number);
    for(i=0;i<number;i++)
        scanf("%d",&grade[i]);
    for(i=0;i<number;i++)
        scanf("%d",&right[i]);
    for(j=0;j<people;j++)
        for(i=0;i<number;i++)
    {
        scanf("%d",&temp);
        if(temp==right[i])
            sum[j]+=grade[i];
    }
    for(i=0;i<people;i++)
        printf("%d\n",sum[i]);
    return 0;
}