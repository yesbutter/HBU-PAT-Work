#include <iostream>
#include <string.h>


using namespace std;

int main()
{
	char tmp;
	char s1[2049];
	char s2[2049];
	int right[257] = { 0 }, cnt = 0;
	cin.getline(s1, 2049);
	cin.getline(s2, 2049);
	for (int i = 0; i<strlen(s1); i++)
	{
		if (s1[i] >= 'a'&&s1[i] <= 'z')
			s1[i] = s1[i] - 32;
	}
	for (int i = 0; i<strlen(s2); i++)
	{
		if (s2[i] >= 'a'&&s2[i] <= 'z')
			s2[i] = s2[i] - 32;
		right[s2[i]] = 1;
	}
	for (int i = 0; i < strlen(s1); i++)
	{
		if (right[s1[i]] == 0)
		{
			printf("%c", s1[i]);
			right[s1[i]] = 2;
		}
	}
	system("pause");
	return 0;
}