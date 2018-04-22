#include<iostream>
using namespace std;
int main()
{
	int a, b,h,m,s;
	cin >> a >> b;
	a = b - a;
	if (a % 100 >= 50)
	{
		a = a / 100 + 1;
	}
	else
	{
		a = a / 100;
	}
	s = a % 60;
	a -= s;
	a /= 60;
	m = a % 60;
	a -= m;
	h = a / 60;
	printf("%02d:%02d:%02d", h, m, s);
	system("pause");
	return 0;
}