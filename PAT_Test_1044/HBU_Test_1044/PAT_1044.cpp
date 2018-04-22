#include<iostream>
#include<string>
#include<string.h>

std::string low_letter[13]  = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
std::string high_letter[13] = { "tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void read(std::string tmp)
{
	if (tmp[0] >= '0'&&tmp[0] <= '9')
	{
		int n = 0;
		for (int i = 0; i < tmp.size(); i++)
			n = n * 10 + tmp[i] - '0';
		if (n < 13)
			std::cout << low_letter[n] << std::endl;
		else if (n % 13==0)//13整数的时候只输出整数部分
		{
			std::cout << high_letter[n/13] << std::endl;
		}
		else
		{
			std::cout << high_letter[n / 13] << " " << low_letter[n % 13] << std::endl;
		}
	}
	else
	{
		int low=0, high=0;
		if (tmp.size() > 5)
		{			
			std::string s1, s2;
			int position = tmp.find(" ");
			s1= tmp.substr(0, position);
			s2 = tmp.substr(position+1, tmp.size()-1);
			for (int i = 0; i < 13; i++)
			{
				if (s2 == low_letter[i])
				{
					low = i;
				}
				if (s1 == high_letter[i])
				{
					high = i;
				}
			}
		}
		else
		{
			high = 0;
			for (int i = 0; i < 13; i++)
			{
				if (tmp==low_letter[i])
				{
					low = i;
				}
				if (tmp == high_letter[i])
				{
					low = i*13;
				}
			}
		}
		std::cout << low + high * 13 << std::endl;
	}

}

int main()
{
	int T;
	std::string tmp;
	std::cin >> T;
	getchar();
	while (T--)
	{
		getline(std::cin, tmp);
		read(tmp);

	}
	system("pause");
	return 0;
}