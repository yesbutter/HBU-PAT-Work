#include<stdio.h>
#include<string.h>
int main()
{
	char zhenghua[80]={0};
	int i,j,n=0,len;
	gets(zhenghua);
	len=strlen(zhenghua);
	j=len;
	for(i=0; i<len; i++)
	{
		if(zhenghua[i]==' ')
			n++;
	}
		if(n==0)
	puts(zhenghua);
	for(; len>0; len--)
	{
		if(zhenghua[len]==' ')
		{
			for(i=len+1; i<j; i++)
				printf("%c",zhenghua[i]); 
			printf(" ");
			j=len;
			n--;
		}
	}
	j++;
	for(i=0;i<j;i++)
	{
		if(zhenghua[i]==' ')
		{
			j=i;
			for(i=0;i<j;i++)
			{
				printf("%c",zhenghua[i]);
			}
		}
	}
	return 0;
}