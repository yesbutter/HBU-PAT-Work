#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
// LNK1561.cpp  
// LNK1561 expected  
// add a main function to resolve this error  

int main()
{
	long n, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, i, temp, count2 = 0, count3 = 0, count4 = 0;
	scanf("%ld", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%ld", &temp);
		if (temp % 5 == 0)
		{
			if (temp % 2 == 0)
				a1 = a1 + temp;
		}
		if (temp % 5 == 1)
		{
			if (count2 % 2 == 0)
				a2 = a2 + temp;
			else a2 = a2 - temp;
			count2++;
		}
		if (temp % 5 == 2)
		{
			count3++;
		}
		if (temp % 5 == 3)
		{
			a4 = a4 + temp;
			count4++;
		}
		if (temp % 5 == 4)
		{
			if (temp>a5)
				a5 = temp;
		}
	}
	if (a1 == 0) printf("N ");
	else printf("%ld ", a1);
	if (count2 == 0) printf("N ");//判断条件应该是count2这类数字是否出现过
	else printf("%ld ", a2);
	if (count3 == 0) printf("N ");
	else printf("%ld ", count3);
	if (a4 == 0) printf("N ");
	else printf("%.1f ", a4*1.0 / count4);
	if (a5 == 0) printf("N\n");
	else printf("%ld\n", a5);
	system("pause");
	return 0;
}
