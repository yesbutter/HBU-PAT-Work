#include<stdio.h>
int powc(int a)
{
    int temp=1,i=1;
    for(i=1; i<=a; i++)
        temp*=10;
    return temp;
}
void func(char a[],int temp)
{
    int i,t;
    for(i=0; i<4; i++)
    {
        t=temp/powc(3-i);
        temp=temp-powc(3-i)*t;
        a[i]=t+48;
    }
}
int aveper(char a[],int flag)
{
    int b[5],i,j,temp;
    for(i=0; i<4; i++)
        b[i]=a[i]-48;
    for(i=0; i<3; i++)
        for(j=0; j<4-i-1; j++)
        {
            if(flag==1)
            {
                if(b[j]>b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
            if(flag==0)
            {
                if(b[j]<b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }
    temp=b[0]*1000+b[1]*100+b[2]*10+b[3];
    return temp;
}
int main()
{
    int sum,judge;
    char a[4];
    scanf("%d",&judge);
    if(judge>9999)return 0;
    func(a,judge);
    do
    {
        sum=aveper(a,0)-aveper(a,1);
        printf("%04d - %04d = %04d\n",aveper(a,0),aveper(a,1),sum);
        if(sum==0||sum==6174)break;
        func(a,sum);
    }
    while(1);
    return 0;
}
