#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

char * add(char *s)
{
	char tmp[2049],s2[2049];
	memset(tmp, '0', sizeof(tmp));
	int len = 0,lenb=0;
	for (len = 0; s[len] != '\0'; len++);
	for (int i = 0,temp; s[i] != '\0'; i++)
	{
		s2[i] = s[len - 1-i];
		temp = s[i] + s[len -1-i] - 96;
		if (temp >= 10)
		{
			temp -= 10;
			tmp[i + 1] += 1;
			if (i == len - 1)
				lenb++;
		}
		tmp[i] += temp;
		if (tmp[i] >= 48 + 10)
		{
			tmp[i] -= 10;
			tmp[i + 1] += 1;
			if (i == len - 1)
				lenb++;
		}
		lenb++;
	}
	s2[len] = '\0';
	tmp[lenb] = '\0';
	for (int i = 0; i < lenb / 2; i++)
	{
		swap(tmp[i], tmp[lenb - i-1]);
	}
	printf("%s + %s = %s\n", s,s2, tmp);
	return tmp;
}

bool judge(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}
int main()
{
	char s[2049];
	int cnt = 0;
	cin >> s;
	while (cnt < 10)
	{
		if (judge(s))
		{
			printf("%s is a palindromic number.\n", s);
			break;
		}
		strcpy(s,add(s));
		if (judge(s))
		{
			printf("%s is a palindromic number.\n", s);
			break;
		}
		cnt++;
	}
	if (cnt == 10)
		printf("Not found in 10 iterations.");
	system("pause");
	return 0;
}