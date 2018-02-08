#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct Student
{
	char name[10];
	int high;
};

bool cmp1(Student a, Student b)
{
	return a.high < b.high;
}

int amian()
{
	vector<Student> v1,v2[11];
	Student tmp;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		scanf("%s%d", &tmp.name, &tmp.high);
		v1.push_back(tmp);
	}
	sort(v1.begin(), v1.end(), cmp1);

	for (int i = 0; i < N/K; i++)
	{

	}

	return 0;
}