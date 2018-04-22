#include<stdio.h>
int main()
{
	char c;
	int flag=1,n,i,j;
	scanf("%d",&n);
	getchar();
	scanf("%c",&c);
	if(n%2==0)
	{
		for(i=1; i<=n/2; i++)
		{
			if(i==n/2)flag=1;
			for(j=1; j<=n; j++)
			{
				if(flag==0)
				{
					if(j==1||j==n)
						printf("%c",c);
					else printf(" ");
				}
			}

			for(j=1; j<=n; j++)
			{
				if(flag==1)
					printf("%c",c);
			}
			flag=0;
			printf("\n");
		}
	}
	else
	{
		for(i=1; i<=n/2+1; i++)
		{
			if(i==n/2+1)flag=1;
			for(j=1; j<=n; j++)
			{
				if(flag==0)
				{
					if(j==1||j==n)
						printf("%c",c);
					else printf(" ");
				}

			}

			for(j=1; j<=n; j++)
			{
				if(flag==1)
					printf("%c",c);
			}
			flag=0;
			printf("\n");
		}
	}
	return 0;
}