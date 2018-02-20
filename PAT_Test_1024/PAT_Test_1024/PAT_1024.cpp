#include<iostream>
#include<string>

using namespace std;

int main()
{
	string A,B;
	int e=0;
	cin >> A;
	int i = A.find('E');

	for (int k = i; k < A.size(); k++)
	{
		if (A[k] >= '0'&&A[k] <= '9')
		{
			e = e * 10 + A[k]-48;
		}
	}

	for (int k = 0; k < i; k++)
	{
		B += A[k];
	}

	if (A[i + 1] == '-')
	{
		if (A[0] == '-')
		{
			cout << A[0];
		}
		cout << "0.";
		for (int i = 0; i < e-1; i++)
		{
			cout << 0;
		}

		for (int i = 1; i < A.find('E'); i++)
		{
			if (A[i] != '.')
			{
				cout << A[i];
			}
		}
	}
	else
	{
		if (B[0] == '-')
		{
			cout << B[0];
		}
		cout <<B[1];
		for (int i = 3; i < B.size(); i++,e--)
		{
			if (e == 0)
			{
				cout << ".";
			}
			cout << B[i];
		}
		while (e > 0)
		{
			cout << "0";
			e--;
		}
	}




	system("pause");
	return 0;
}