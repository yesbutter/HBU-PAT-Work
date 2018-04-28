#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include <iostream>
#include<vector>
int book[100005], p[100005],book2[100005];
using namespace std;
int main()
{
	vector<int> ans;
	int n, tmp[2];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp[0] >> tmp[1];
		book[tmp[0]] = tmp[1];
		book[tmp[1]] = tmp[0];
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		book2[p[i]] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (book2[book[p[i]]] == 0)
			ans.push_back(p[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)cout << " ";
		printf("%05d", ans[i]);
		//cout << ans[i];
	}
	system("pause");
	return 0;
}