#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
	vector<set<char> >v(1001);
	char a;
	int n,m,i,j,x,y,max=0,p[101][5]={0};
	double score[101];
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>score[i]>>x>>y;
		while(y--)
		{
			scanf(" %c",&a);
			v[i].insert(a);
		}
	}
	while(n--)
	{
		double sum=0;
		scanf("\n");
		for(i=0;i<m;i++)
		{
			int flag=1;
			set<char>s,g=v[i];
			set<char>::iterator it,ot;
			if(i!=0) scanf(" ");
			scanf("(%d",&x);
			while(x--)
			{
				scanf(" %c",&a);
				s.insert(a);
			}
			scanf(")");
			if(s==v[i]) sum=sum+score[i]; //���ѡ������ȷ����ȫһ�£���õ�����ȫ��������
			else //�������ж��Ƿ��д�ѡ��ѡ����У����÷֣����ޣ��ø���һ�������
			{
				for(it=s.begin();it!=s.end();it++) //�����������޴�ѡ��ѡ�
				{
					if(v[i].find(*it)==v[i].end())
					{
						flag=0; //���ѡ���ѡ�������ȷѡ���flag=0����ǡ�
						p[i][*it-'a']++; //ͳ�ƴ�ѡѡ����ִ�����
						if(p[i][*it-'a']>max)
							max=p[i][*it-'a'];
					}
				}
				for(ot=g.begin();ot!=g.end();ot++) //������������©ѡ��ѡ�
				{
					if(s.find(*ot)==s.end())
					{
						p[i][*ot-'a']++; //ͳ��©ѡѡ����ִ�����
						if(p[i][*ot-'a']>max)
							max=p[i][*ot-'a'];
					}
				}
				if(flag==1) sum=sum+score[i]/2.0; //���flag=1,˵��δ�д�ѡ��ѡ��(ֻ��©ѡ),�ɵø���һ�������
			}
		}
		printf("%.1f\n",sum);
	}
	if(max==0)
	{
		puts("Too simple"); return 0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<5;j++)
		{
			if(p[i][j]==max)
				printf("%d %d-%c\n",max,i+1,j+'a');
		}
	}
	return 0;
}