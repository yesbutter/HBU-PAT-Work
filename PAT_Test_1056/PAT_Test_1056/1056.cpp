#include<iostream>

using namespace std;

int main()
{
	int n, a[10], sum = 0, book[100] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				book[a[i] * 10 + a[j]] = 1;
			}
		}
	}
	for (int i = 10; i <= 99; i++)
	{
		if (book[i] == 1)
			sum += i;
	}
	cout << sum;
	system("pause");
}