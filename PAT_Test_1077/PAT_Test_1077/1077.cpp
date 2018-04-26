#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, M,tmp;
	vector<int> v,vs;
	cin >> n >> M;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp >=0 && tmp <=M)
			{
				v.push_back(tmp);
			}
		}
		sort(v.begin() + 1, v.end());
		for (int i = 2; i < v.size() - 1; i++)
		{
			sum += v[i];
		}
		sum /= v.size() - 3;
		vs.push_back((sum + v[0])*1.0 / 2 + 0.5);
	}
	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}
	system("pause");
	return 0;
}