#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct STUDENT
{
	char id[18];
	int de;
	int cai;
}Student;

bool Cmp(STUDENT s1, STUDENT s2)
{
	if ((s2.de + s2.cai) != (s1.de + s1.cai))
	{
		return (s2.de + s2.cai) < (s1.de + s1.cai);
	}
	else if (s2.de !=s1.de)
	{
		return s1.de>s2.de;
	}
	else
	{
		return strcmp(s1.id,s2.id)<0;//注意返回值，如果写成strcmp (s1.id,s2.id);就会错误！
	}
}

int main()
{

	int n,low,high,cnt=0;
	scanf("%d%d%d", &n, &low, &high);
	STUDENT stu;
	vector<STUDENT> v1,v2,v3,v4;
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d%d", stu.id, &stu.de, &stu.cai);
		if (stu.de >= high && stu.cai >= high)
			v1.push_back(stu);
		else if (stu.de >= high && stu.cai >= low)
			v2.push_back(stu);
		else if (stu.de >= low && stu.de < high&&stu.cai >= low && stu.cai < high&&stu.de >= stu.cai)
			v3.push_back(stu);
		else if (stu.de >= low && stu.de < high&&stu.cai >= low && stu.de < stu.cai)
			v4.push_back(stu);
		else
			cnt++;
	}

	sort(v1.begin(), v1.end(), Cmp);
	sort(v2.begin(), v2.end(), Cmp);
	sort(v3.begin(), v3.end(), Cmp);
	sort(v4.begin(), v4.end(), Cmp);

	cout << n - cnt << endl;

	vector<Student>::iterator iter;//迭代器遍历vector 
	
	for (iter =v1.begin(); iter !=v1.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	for (iter = v2.begin(); iter != v2.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	for (iter = v3.begin(); iter != v3.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	for (iter = v4.begin(); iter != v4.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	system("pause");
	return 0;

}