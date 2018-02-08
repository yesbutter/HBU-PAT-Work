#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<long long> v;

int main()
{
	long long N, p,cnt=0,min,tmp;

	cin >> N >> p;
	for (long long i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	min = v[0];
	for (int j = 0; j < N; j++) {
		for (int i =j+cnt; i < N; i++)//这个跳cnt非常巧妙！！！
		{
			if (v[j]*p < v[i])
			{
				break;
			}
			if (i - j + 1>cnt)
				cnt = i - j + 1;
		}
	}
	cout << cnt;
	system("pause");
	return 0;
}