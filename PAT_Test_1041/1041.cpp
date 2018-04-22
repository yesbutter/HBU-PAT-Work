#include<iostream>
#include<string>

using namespace std;

struct student {
	string name;
	int no;
};

int main()
{
	student s,v[1002];
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s.name >> tmp >> s.no;
		v[tmp] = s;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		cout << v[tmp].name << " " << v[tmp].no << endl;
	}
	return 0;
}