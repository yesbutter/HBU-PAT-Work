#include <iostream>

using namespace std;

int main()
{
	char tmp;
	int a[257] = { 0 }, max = -1, maxpos = -1;
	while (cin >> tmp)
	{
		if (tmp == '\n')
			break;
		if (tmp >= ' ')
		{
			a[tmp]++;
		}
	}

	for (int i = 'a'; i <= 'z'; i++)
	{
		a[i] += a[i - 32];
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
			maxpos = i;
		}
	}
	printf("%c %d", maxpos, max);
	system("pause");
	return 0;
}