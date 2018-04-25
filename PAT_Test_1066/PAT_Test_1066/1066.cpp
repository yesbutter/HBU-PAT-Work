#include<iostream>

using namespace std;

int a[501][501];
int main()
{
	int N, M, L, R, P,tmp;
	cin >> N >> M >> L >> R >> P;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			if (tmp >= L && tmp <= R)
				tmp = P;
			a[i][j] = tmp;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j != 0)cout << " ";
			printf("%03d", a[i][j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}