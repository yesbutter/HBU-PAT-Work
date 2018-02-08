#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	int front;
	int data;
	int next;
};

Node node[100050];

int main()
{
	int firstposition, N, K;
	vector<Node> v;
	cin >> firstposition >> N >> K;
	for (int i = 0,tmp1,tmp2,tmp3; i < N; i++)
	{
		cin >> tmp1 >> tmp2 >> tmp3;
		node[tmp1].front = tmp1;
		node[tmp1].data = tmp2;
		node[tmp1].next = tmp3;
	}

	while (firstposition!=-1)
	{
		v.push_back(node[firstposition]);
		firstposition = node[firstposition].next;
	}

	for (int i = 0,t=v.size()/K; i < t; i++)
		reverse(v.begin() + i * K, v.begin() + (i + 1)*K);
	for (int i = 0; i<v.size() - 1; i++) {       
		printf("%05d %d %05d\n", v[i].front, v[i].data, v[i+1].front);
	}
	printf("%05d %d %d\n", v[v.size() - 1].front, v[v.size() - 1].data, -1);

	system("pause");

	return 0;
}