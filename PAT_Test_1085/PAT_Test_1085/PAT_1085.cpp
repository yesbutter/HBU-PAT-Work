#include "iostream"
#include "vector"
#include "string"
#include "map"
#include <algorithm>
using namespace std;

struct node
{
	string school;
	double grade;
	int peocount;
	node(string school, int grade)
	{
		this->school = school;
		this->grade = grade;
		peocount = 1;
	}
};

void format(string &n)
{
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] >= 'A'&&n[i] <= 'Z')
			n[i] += 32;
	}
}
int cmp(node a, node b)
{
	if ((int)a.grade != (int)b.grade)
		return a.grade > b.grade;
	if (a.peocount != b.peocount)
		return (int)a.peocount < (int)b.peocount;
	return a.school<=b.school;
}
int main()
{
	map<string, int> m;
	vector<node> v;
	string name, g;
	int grade, cnt = 1,n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> g >> grade >> name;
		format(name);
		if (m.count(name)==0)
		{
			m.insert(make_pair(name, cnt++));
			int position = m[name] - 1;
			double gr;
			if (g[0] == 'A')
				gr = grade;
			else if (g[0] == 'B')
				gr = grade / 1.5;
			else if (g[0] == 'T')
				gr = grade * 1.5;
			node tmp(name, gr);
			v.push_back(tmp);
			
		}
		else
		{
			int position = m[name] - 1;
			double gr;
			if (g[0] == 'A')
				gr = grade;
			else if (g[0] == 'B')
				gr = grade / 1.5;
			else if (g[0] == 'T')
				gr = grade * 1.5;
			node tmp(name,gr);
			v[position].grade += gr;
			v[position].peocount += 1;
		}
	}
	sort(v.begin(), v.end(), cmp);
	cout << v.size() << endl;
	for (int i = 0,tmp; i < v.size(); i++)
	{
		if (i != 0 && (int)v[i].grade == (int)v[i - 1].grade)
			printf("%d %s %d %d\n", tmp, v[i].school.c_str(), (int)v[i].grade, v[i].peocount);
		else {
			printf("%d %s %d %d\n", i + 1, v[i].school.c_str(), (int)v[i].grade, v[i].peocount);
			tmp = i + 1;
		}
	}
	system("pause");
	return 0;
}