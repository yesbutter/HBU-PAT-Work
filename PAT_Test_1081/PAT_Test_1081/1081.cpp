#include<iostream>
#include<string>
using namespace std;

int judge(string s)
{
	int flag = 0,flag1=0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			flag = 1;
		}
		else if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z'))
		{
			flag1 = 2;
		}
		else if (s[i] != '.')
		{
			return -1;
		}
	}
	return flag + flag1;
}
int main()
{
	int cnt;
	string s;
	cin >> cnt;
	getchar();
	while (cnt--)
	{
		getline(cin, s);
		int tmp = judge(s);
		if (s.length() < 6)
		{
			cout << "Your password is tai duan le." << endl;
		}
		else if (tmp == -1)
		{
			cout << "Your password is tai luan le." << endl;
		}
		else if (tmp == 2)
		{
			cout << "Your password needs shu zi." << endl;
		}
		else if (tmp == 1)
		{
			cout << "Your password needs zi mu." << endl;
		}
		else if (tmp == 3)
		{
			cout << "Your password is wan mei." << endl;
		}
	}
	system("pause");
	return 0;
}