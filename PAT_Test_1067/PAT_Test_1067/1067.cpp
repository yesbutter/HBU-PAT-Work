#include<iostream>
#include<string>

using namespace std;

int judge(int a, int b)
{
	for (int i = 0; a != 0; i++)
	{
		if (a % 10 != b % 10)
			return 0;
		a /= 10;
		b /= 10;
	}
	return 1;
}

int main()
{
	string pass, tmp;
	int n,cnt=0;
	cin >> pass >> n;
	//��getchar(����ȡ����������Ļس�
	getchar();
	while (cnt<n)
	{
		//����һ�е��ַ���
		getline(cin, tmp);
		if (tmp == "#")
			break;
		if (tmp != pass)
		{
			cout << "Wrong password: " << tmp << endl;
		}
		if (tmp == pass)
		{
			cout << "Welcome in" << endl;
			break;
		}
		cnt++;
	}
	if (cnt == n)
		cout << "Account locked";
	system("pause");
	return 0;
}