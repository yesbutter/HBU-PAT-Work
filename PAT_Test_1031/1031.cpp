#include<stdio.h>
#define X 58
int main()
{
    int quanzhong[18]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},sum,i,j=0,count=0;
    char check[11]= {'1','0','X','9','8','7','6','5','4','3','2'},idcard[18];
    int n;
    scanf("%d",&n);
    getchar();
    do
    {
        gets(idcard);
        for(i=0,sum=0; i<17; i++)
        {
            sum=(idcard[i]-48)*quanzhong[i]+sum;
        }
        sum=sum%11;
        if(idcard[17]==check[sum])
            count++;
        else puts(idcard);
        j++;
    }
    while(j<n);
    if(count==n)printf("All passed");
    return 0;
}
