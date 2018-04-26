#include <iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	int M, N, S, cnt = 0, flag = 0;
	map<string, int> m;
	string tmp;
	cin >> M >> N >> S;
	//cout << M << " " << N << " " << S << endl;
	for (int i = 1; i <= M; i++)
	{
		cin >> tmp;
		//cout<<tmp<<endl;
		cnt++;
		if ((cnt - S) % N == 0 && (cnt - S) >= 0)
		{
			if (m[tmp] == 0)
			{
				m[tmp] = 1;
				cout << tmp << endl;
				flag = 1;
			}
			else
			{
				cnt--;
			}
		}
	}
	if (flag == 0)
		cout << "Keep going...";
	system("pause");
	return 0;
}