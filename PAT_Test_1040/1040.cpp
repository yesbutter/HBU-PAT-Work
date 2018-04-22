#include<stdio.h>
#include<string.h>
int main()
{
    char c[100001];
    gets(c);
    int len,i,p=0,t=0,result=0;
    len=strlen(c);
    for(i=0; i<len; i++)
    {
        if(c[i]=='T')
                t++;
    }
for(i=0; i<len; i++)
    {
        if(c[i]=='P')p++;
        if(c[i]=='T')t--;
        if(c[i]=='A')
            result=((p*t)%1000000007+result)%1000000007;
    }
    printf("%d",result);
    return 0;
}