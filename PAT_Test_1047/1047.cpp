#include<stdio.h>
int main()
{
    int n,i,a[1000]={0},max=0,maxpos=0,name,number,grades;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d-%d %d",&name,&number,&grades);
        a[name]+=grades;
        if(max<a[name])
        {
            maxpos=name;
            max=a[name];
        }
    }
    printf("%d %d",maxpos,max);
    return 0;
}