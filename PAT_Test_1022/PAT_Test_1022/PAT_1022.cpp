#include<iostream>
#include<string>

using namespace std;

/*
void restore(string A,string B,int *a,int *b)
{
	for (int i = A.length() - 1,j=0; i >= 0; i--)
	{
		a[j++] = A[i]-48;
	}

	for (int i = B.length() - 1, j = 0; i >= 0; i--)
	{
		b[j++] = B[i]-48;
	}
}*/

int main()
{
	/*int numa[1001] = { 0 }, numb[1002] = { 0 }, D;
	memset(numa, 0, sizeof(numa));
	memset(numb, 0, sizeof(numb));
	string A, B;
	cin >> A >> B >> D;
	restore(A, B, numa, numb);

	for (int i = 0; i < 1001; i++)
	{
		numa[i] += numb[i];
		while (numa[i]>=D)
		{
			numa[i] -= D;
			numa[i + 1] += 1;
		}
	}

	for (int i = 1000, flag = 0; i >= 0; i--)
	{
		if (numa[i] != 0) 
		{
			flag = 1;
		}
		if (flag == 1)
			cout << numa[i];
	}
	system("pause");
	return 0;*/
	int A, B, D, numa[40] = { 0 }, N, i = 0, flag = 0;
	cin >> A >> B >> D;
	N = A + B;
	while (N != 0)
	{
		numa[i++] = N % D;
		N = N / D;
	}
	for (int i = 39; i >= 0; i--)
	{
		if (numa[i] != 0)
		{
			flag = 1;
		}
		if (flag == 1)
		{
			cout << numa[i];
		}
	}
	if (flag == 0)
	{
		cout << 0;
	}
	system("pause");
	return 0;

}