#include<iostream>

using namespace std;

int main()
{
	int temp, book[11] = { 0 },cnt=0;
	while (cin >> temp)
	{
		book[cnt++] = temp;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (book[i] != 0)
		{
			cout << i;
			book[i] -= 1;
			break;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		while (book[i] != 0)
		{
			cout << i;
			book[i] -= 1;
		}
	}

	system("pause");
	return 0;
}