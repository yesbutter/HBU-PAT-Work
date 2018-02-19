#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

void restore(char *a, char *b, int *c, int *d)
{
	for (int i = strlen(a)-1, j = 0; i >= 0; i--, j++)
	{
		c[j] = a[i] - 48;
	}

	for (int i = strlen(b)-1, j = 0; i >= 0; i--, j++)
	{
		d[j] = b[i] - 48;
	}

}

int main()
{
	char key_value[4] = { "JQK" };
	char A[102], B[102];
	int numa[102] = { 0 }, numb[102] = { 0 };
	int cnt = 1;
	scanf("%s %s", A, B);

	restore(A, B, numa, numb);
	
	for (int i = 0, len = strlen(A) >= strlen(B) ? strlen(A) : strlen(B); i < len; i++)
	{
		if (i % 2 == 0)
		{
			numb[i] = (numa[i] + numb[i]) % 13;
		}
		if (i % 2 == 1)
		{
			numb[i] = numb[i] - numa[i];
			if (numb[i] < 0)
			{
				numb[i] += 10;
			}
		}
	}

	for (int i = (strlen(A) >= strlen(B) ? strlen(A) : strlen(B))-1; i >=0; i--)
	{
		if (numb[i] > 9)
			cout << key_value[numb[i]-10];
		else
		{
			cout << numb[i];
		}
	}
	/*for (int i = strlen(B) - 1,j=strlen(A)-1; j>=0 && i >= 0; i--,j--,cnt++)
	{
		if (cnt == 2) 
		{
			cnt = 0;
		}
		if (cnt == 1)
		{
			B[i] = (B[i] + A[j] - 96) % 13 + 48;
		}
		if (cnt == 0)
		{
			B[i] = B[i] - A[j];
			if (B[i] < 0)
				B[i] += 10;
			B[i] += 48;
		}
	}
	for (int i = 0; i < strlen(B); i++)
	{
		if (B[i] > '9')
		{
			B[i] = key_value[B[i] - '9' - 1];

		}
	}
	puts(B);*/
	system("pause");
	return 0;

}