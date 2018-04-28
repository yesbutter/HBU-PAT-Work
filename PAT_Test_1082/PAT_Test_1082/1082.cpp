#include<iostream>

using namespace std;

int main()
{
	int idmin, idmax,mins=0x3f3f3f3f,maxs=-1,n,a[3];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[0] >> a[1] >> a[2];
		int tmp = a[1] * a[1] + a[2] * a[2];
		if (tmp < mins)
		{
			idmin = a[0];
			mins = tmp;
		}
		if (tmp > maxs)
		{
			idmax = a[0];
			maxs = tmp;
		}
	
	}
	printf("%04d %04d", idmin, idmax);
	system("pause");
	return 0;

}