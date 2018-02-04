#include<stdio.h>
#include<string.h>
#include <cstdio>
#include<iostream>

void find_days(char a[], char b[])
{
	int tmp;
	char day[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	for (int i = 0; i < strlen(a) && i < strlen(b); i++)
	{
		if (a[i] >= 'A'&&a[i] <= 'G'&&a[i] == b[i])
		{
			std::cout << day[b[i] - 'A'] << " ";
			a[i] = b[i] = '$';
			tmp = i;
			break;
		}
	}

	for (int i = tmp; i < strlen(b) && i < strlen(a); i++)
	{
		if (((b[i] >= '0'&&b[i] <= '9') && a[i] == b[i]))
		{
			printf("%02d:", a[i]-'0');
			break;
		}
		if ((b[i] >= 'A'&&b[i] <= 'N') && a[i] == b[i])
		{
			printf("%02d:", a[i] - 'A' + 10);
			break;
		}
	}
}

void find_seconds(char *a, char *b)
{
	for (int i = 0; i <strlen(a)&&i<strlen(b); i++)
	{
		if (a[i] == b[i]&&((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')))
		{
			printf("%02d", i);
			break;
		}
	}
}

int main()
{
	char daya[62], dayb[62], timea[62], timeb[62];//61字符数组有俩个测试点没过！！！
	int i, j;
	fgets(daya,62,stdin);
	fgets(dayb, 62, stdin);
	fgets(timea, 62, stdin);
	fgets(timeb, 62, stdin);
	find_days(daya, dayb);
	find_seconds(timea, timeb);
	system("pause");
	return 0;
}
