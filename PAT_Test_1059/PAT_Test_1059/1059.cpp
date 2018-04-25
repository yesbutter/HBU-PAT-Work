#include<iostream>
#include<string.h>

using namespace std;

bool isperime(int a)
{
	if (a <= 1)
		return false;
	for (int i = 2; i*i <=a; i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}
int book[20005];

int main()
{
	int n, tmp, temp;	
	cin >> n;
	memset(book, -1, sizeof(book));
	for (int i =1; i <=n; i++)
	{
		cin >> tmp;
		book[tmp]= i;
	}
	cin >> temp;
	for (int i = 0; i < temp; i++)
	{
		cin >> tmp;
		printf("%04d: ", tmp);
		if (book[tmp] == -2)
		{
			cout << "Checked" << endl;
		}
		if (book[tmp] == -1)
		{
			cout << "Are you kidding?" << endl;
		}
		if (book[tmp] == 1)
		{
			cout << "Mystery Award" << endl;
			book[tmp] = -2;
		}
		if (isperime(book[tmp])&&book[tmp]>1)
		{
			cout << "Minion" << endl;
			book[tmp] = -2;
		}
		if (!isperime(book[tmp]) &&book[tmp]>1)
		{
			cout << "Chocolate" << endl;
			book[tmp] = -2;
		}
	}
	system("pause");
	return 0;
}