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
			if(s==v[i]) sum=sum+score[i]; //如果选择与正确答案完全一致，则得到该题全部分数。
			else //否则，需判断是否有错选的选项，若有，不得分，若无，得该题一半分数。
			{
				for(it=s.begin();it!=s.end();it++) //遍历该题有无错选的选项。
				{
					if(v[i].find(*it)==v[i].end())
					{
						flag=0; //如果选择的选项不属于正确选项，用flag=0做标记。
						p[i][*it-'a']++; //统计错选选项出现次数。
						if(p[i][*it-'a']>max)
							max=p[i][*it-'a'];
					}
				}
				for(ot=g.begin();ot!=g.end();ot++) //遍历该题有无漏选的选项。
				{
					if(s.find(*ot)==s.end())
					{
						p[i][*ot-'a']++; //统计漏选选项出现次数。
						if(p[i][*ot-'a']>max)
							max=p[i][*ot-'a'];
					}
				}
				if(flag==1) sum=sum+score[i]/2.0; //如果flag=1,说明未有错选的选项(只是漏选),可得该题一半分数。
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