#include<iostream>
#include<vector>
#include<string>

using namespace std;

void save(char *tmp,vector<string> v)
{
	string p;
	for (int i = 0; tmp[i] != '\0'; i++)
	{
		if (tmp[i] == '[')
		{
			i++;
			p = "";
			while (tmp[i] != ']')
			{
				p += tmp[i++];
			}
			v.push_back(p);
		}
	}
}
int main()
{
	char tmp[2049];
	vector<string> hand, eye, mouth;
	cin.getline(tmp, 2049);
	save(tmp, hand);
	cin.getline(tmp, 2049);
	save(tmp, eye);
	cin.getline(tmp, 2049);
	save(tmp, mouth);

	int n,a[5];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
		if (a[0] < hand.size() && a[1] < eye.size() && a[2] < mouth.size() && a[3] < eye.size() && a[4] < hand.size())
		{
			printf("%s(%s%s%s)%s\n",hand[a[0]-1], eye[a[1] - 1], mouth[a[2] - 1], eye[a[3] - 1], hand[a[4] - 1]);
		}
		else
		{
			printf("Are you kidding me? @\\/@\n");
		}
	}
	return 0;
}
