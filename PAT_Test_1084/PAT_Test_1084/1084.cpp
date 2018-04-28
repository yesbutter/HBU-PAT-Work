#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

char* fun(char *s)
{
	int lenb = 0;
	char tmp[120490];
	for (int i = 0,len=strlen(s); i < len; i++)
	{
		int t=1;
		while (i < len - 1 && s[i] == s[i + 1])
		{
			i++;
			t++;
		}
		tmp[lenb++] = s[i];
		while (t != 0)
		{
			tmp[lenb++] = t % 10+'0';
			t /= 10;
		}
	}
	tmp[lenb] = '\0';
	return tmp;
}
int main()
{
	char s[120490];
	int t;
	cin >> s[0] >> t;
	s[1] = '\0';
	for (int i = 1; i < t; i++)
	{
		strcpy(s , fun(s));
	}
	printf("%s", s);
	system("pause");
	return 0;
}