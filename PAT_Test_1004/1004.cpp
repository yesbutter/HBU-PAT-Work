//pat典型结构体排序
#include<stdio.h>
struct student1
{
	char name[11];
	char number[11];
	int cj;
};
int main()
{
	int n,i,maxpos=0,minpos=0,max,min;
	scanf("%d",&n);
	struct student1 a[n];
	for(i=0;i<n;i++)
	{
		scanf("%s",&a[i].name);
		scanf("%s",&a[i].number);
		scanf("%d",&a[i].cj);
	}
	max=a[0].cj;
	min=a[0].cj;
	for(i=1;i<n;i++)
	{
		if(a[i].cj>max)
		{
			max=a[i].cj;
			maxpos=i;
		}
		if(a[i].cj<min)
		{
			min=a[i].cj;
			minpos=i;
		}
	}
	printf("%s %s\n",a[maxpos].name,a[maxpos].number);
	printf("%s %s",a[minpos].name,a[minpos].number);
}
