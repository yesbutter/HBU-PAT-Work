#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	char ans[1024], tmp[4];
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%s", tmp);
			if (tmp[2] == 'T')
			{
				ans[i] = tmp[0] - 'A' + '1';
			}
		}
	}
	ans[n] = '\0';
	printf("%s", ans);
	system("pause");
	return 0;
}