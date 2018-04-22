#include <stdio.h>
int main()
{
    int i,n;
    double sum=0,p;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%lf",&p);
        sum+=p*(n-i)*(i+1);
    }
    printf("%.2lf",sum);
}