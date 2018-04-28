#include<iostream>

using namespace std;

int main()
{
	int n, a[100005] = { 0 }, book[100005] = { 0 }, maxs = -1, mins = 0x3f3f3f3f;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int tmp = abs(i - a[i]);
		book[tmp] += 1;
		if (tmp > maxs)
		{
			maxs = tmp;
		}
		if (tmp < mins)
		{
			mins = tmp;
		}
	}
	for (int i = maxs; i >= mins; i--)
	{
		if (book[i] > 1)
		{
			cout << i <<" "<< book[i] << endl;
		}
	}
	system("pause");
	return 0;
}