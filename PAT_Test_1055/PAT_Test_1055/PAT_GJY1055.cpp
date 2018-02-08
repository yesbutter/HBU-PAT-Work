
#include "iostream"
#include "iomanip"
#include "string"
#include "cmath"
#include "limits"
#include "algorithm"
using namespace std;
struct Person
{
	string name;
	int highth;
};
bool cmp(Person p, Person q)
{
	if (p.highth != q.highth)
		return p.highth>q.highth;
	else
		return p.name.compare(q.name)<0;
}


Person p[10099];

int main()
{
	string tmp[20];
	int last;
	int tag = 1;
	int quenum;
	int top;
	int u, v;
	int s = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i<n; i++)
		cin >> p[i].name >> p[i].highth;
	quenum = n / k;
	last = n - quenum * k + quenum;
	sort(p, p + n, cmp);
	top = last / 2;
	tmp[top] = p[0].name;
	u = top - 1;
	v = top + 1;
	for (int i = 1; u >= 0 && v <= last - 1; i++)
	{
		if (tag)
		{
			tmp[u] = p[i].name;
			u--;
			tag = 0;
		}
		else
		{
			tmp[v] = p[i].name;
			v++;
			tag = 1;
		}
	}
	if (u<0 && !(v>last - 1))
	{
		tmp[last - 1] = p[last - 1].name;
	}
	else if (v>last - 1 && !(u<0))
	{
		tmp[0] = p[last - 1].name;
	}
	for (int i = 0; i<last; i++)
	{
		cout << tmp[i];
		if (i != last - 1)
			cout << " ";
	}
	cout << endl;
	s = last - 1;
	s++;
	for (int j = 1; j<k; j++)
	{
		tag = 1;
		top = quenum / 2;
		tmp[top] = p[s].name;
		s++;
		for (u = top - 1, v = top + 1;; u--, v++)
		{
			if (tag)
			{
				if (u<0)
					break;
				tmp[u] = p[s].name;
				s++;
				tag = 0;
			}
			else
			{
				if (v>quenum - 1)
					break;
				tmp[v] = p[s].name;
				s++;
				tag = 1;
			}
		}
		if (u<0 && !(v<quenum - 1))
		{
			tmp[quenum - 1] = p[s].name;
			s++;
		}
		else if (v<quenum - 1 && !(u<0))
		{
			tmp[0] = p[s].name;
			s++;
		}
		for (int i = 0; i<quenum; i++)
		{
			cout << tmp[i];
			if (i != quenum - 1)
				cout << " ";
		}
		cout << endl;
		//last = last + quenum ;
	}














	system("pause");
	return 0;
}
