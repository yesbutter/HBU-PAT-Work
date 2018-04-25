#include<iostream>

using namespace std;

int main()
{
	int n, cnta = 0, cntb = 0, k,cntday=0,p;
	double e, tmp;
	cin >> n >> e >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		cntday = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> tmp;
			if (tmp < e)
			{
				cntday++;
			}
		}
		if (cntday >(k / 2))
		{
			if(k <= p)//要满足条件一才是确认的
				cnta++;
			else
			{
				cntb++;
			}
		}
		
	}
	printf("%.1f%% %.1f%%", ((double)cnta / n*100),((double) cntb / n*100));
	system("pause");
	return 0;
}