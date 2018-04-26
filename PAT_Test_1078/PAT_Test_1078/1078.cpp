#include<iostream>

using namespace std;

int readint(char *s, int &position)
{
	int result = 0;
	for (; s[position] != '\0'; position++)
	{
		if (s[position] > '9' || s[position] < '0')
			break;
		result = result * 10 + (s[position] - '0');
	}
	return result;
}

int readsum(char *s, int &position)
{
	int cnt =1;
	char tmp = s[position++];
	for (; s[position] != '\0'; position++)
	{
		if (s[position] == tmp)
			cnt++;
		else
			break;
	}
	position--;
	return cnt;
}
void decode(char *s)
{
	int cnt = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9') {
			cnt = readint(s, i);
			for (int j = 0; j < cnt; j++)
				cout << s[i];
		}
		else
		{
			cout << s[i];
		}
	}
}

void c_code(char *s)
{
	int cnt = 0;
	//char ans[2049];
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != '\0'&&s[i + 1] == s[i])
		{
			int sum = 0;
			char tmp = s[i];
			sum = readsum(s, i);
			//while (sum != 0)
			//{
			//	ans[cnt++] = sum%10 + '0';
			//	sum /= 10;
			//}
			cout << sum << tmp;
			//ans[cnt++] = tmp;
		}
		else
		{
			//ans[cnt++] = s[i];
			cout << s[i];
		}
	}
	//for (int i = 0; i < cnt; i++)
		//cout << ans[i];
}
int main()
{
	char type, s[2049];
	type = getchar();
	getchar();
	cin.getline(s, 2049);
	if (type == 'C')
		c_code(s);
	else if (type == 'D')
		decode(s);
	system("pause");
	return 0;
}