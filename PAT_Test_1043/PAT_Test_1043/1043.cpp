#include<iostream>

using namespace std;

int main()
{
	int p=0,a=0,T=0,e=0,s=0,t=0;
	char tmp;
	while (cin >> tmp)
	{
		if (tmp == 'P')
			p++;
		if (tmp == 'A')
			a++;
		if (tmp == 'T')
			T++;
		if (tmp == 'e')
			e++;
		if (tmp == 's')
			s++;
		if (tmp == 't')
			t++;
	}

	while (p!=0|| a != 0 || T != 0 || e != 0 || s != 0 || t != 0)
	{
		if (p != 0)
		{
			cout << 'P';
			p--;
		}
		if (a != 0)
		{
			cout << 'A';
			a--;
		}
		if (T != 0)
		{
			cout << 'T';
			T--;
		}
		if (e != 0)
		{
			cout << 'e';
			e--;
		}
		if (s != 0)
		{
			cout << 's';
			s--;
		}
		if (t != 0)
		{
			cout << 't';
			t--;
		}
	}
	system("pause");
	return 0;
}