#include<stdio.h>
int main()
{
	int a[100],i,m,n,temp;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	while(m>=n)
	{
		m=m-n;
	}
	temp=n-m;
	for(; temp<n; temp++)
		printf("%d ",a[temp]);
	for(i=0; i<n-m-1; i++)
		printf("%d ",a[i]);
	printf("%d",a[n-m-1]);
}