#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct Student
{
	string name;
	int p = -1;
	int m = -1;
	int n = -1;
	int end = -1;
};

bool cmp(Student s1, Student s2)
{
	if (s1.end != s2.end)
		return s1.end > s2.end;
	else return s1.name.compare(s2.name)<0;
}


int main()
{
	map<string, int> m; //也可以采用 map<string,Student>的方式，可以优化算法的时间！
	vector<Student> v;
	string tmp;
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0, p = 0; i < a; i++)
	{
		cin >> tmp >> p;
		if (p >= 200)
		{
			Student temp;
			temp.name = tmp;
			temp.p = p;
			v.push_back(temp);
			m.insert(map<string, int>::value_type(tmp, v.size() - 1));
		}
	}

	for (int i = 0, M; i < b; i++)
	{
		cin >> tmp >> M;
		map<string, int>::iterator iter;
		iter = m.find(tmp);
		if (iter != m.end())
		{
			v[iter->second].m = M;
		}
	}

	for (int i = 0, M; i < c; i++)
	{
		cin >> tmp >> M;
		map<string, int>::iterator iter;
		iter = m.find(tmp);
		if (iter != m.end())
		{
			v[iter->second].n = M;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].m > v[i].n)
		{
			v[i].end = (int)(v[i].m*0.4 + v[i].n*0.6 + 0.5);
		}
		else
		{
			v[i].end = v[i].n;
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].end >= 60)
		{
			cout << v[i].name << " " << v[i].p << " " << v[i].m << " " << v[i].n << " " << v[i].end << endl;
		}
		else
		{
			break;
		}
	}

	system("pause");

	return 0;

}