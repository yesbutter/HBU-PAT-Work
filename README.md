#### PAT乙级1001
```c++
#include<stdio.h>
int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	while(n!=1)
	{
		if(n%2==0)
		n=n/2;
		else n=(3*n+1)/2;
		count++;
	}
	printf("%d",count);
 } 
```

#### PAT乙级1002
```c++
//求一个数字的个各位数字
#include<string>
#include<iostream>
using namespace std;
int main()
{
    long n=0,a[1000],lenn;//实际考虑题目，是一个100位数字，所以最大相加不会超过三位数
    string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"},tmp;
    cin>>tmp;
    for(int i=0;i<tmp.size();i++)
    {
        n+=tmp[i]-'0';
    }
    if(n==0)
        cout<<num[0];
    for(lenn=0;n!=0;lenn++)
    {
        a[lenn]=n%10;
        n/=10;
    }
    for(int i=lenn-1;i>=0;i--)
    {
        if(i!=lenn-1)
            cout<<" ";
        cout<<num[a[i]];
    }
    return 0;
}

```

#### PAT乙级1003
```c++

#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
void check()
{
    char ch[105];
    int idxT,idxP,len;
    scanf("%s",ch);
    string s=string(ch);
    len=s.length();
    idxP=s.find('P',0);
    idxT=s.find('T',0);
    if(idxP==string::npos||idxT==string::npos||(idxP>=idxT-1))
    {
        printf("NO\n");
    }
    else
    {
        string a(s,0,idxP);
        string b(s,idxP+1,idxT-idxP-1);
        string c(s,idxT+1,len-idxT-1);
        string ans=a+b+c;
        if(ans.find_first_not_of('A')!=string::npos)
        {
            printf("NO\n");
        }
        else
        {
            if(idxP==0&&len-idxT-1==0)
                printf("YES\n");
            else if(idxP*(idxT-idxP-1)==len-idxT-1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(;n--;)
    {
        check();
    }
    return 0;
}
```

#### PAT乙级1004
```c++
//pat典型结构体排序，写这个算法的时候还没有接触acm。
#include<stdio.h>
struct student1
{
	char name[11];
	char number[11];
	int cj;
};
int main()
{
	int n,i,maxpos=0,minpos=0,max,min;
	scanf("%d",&n);
	struct student1 a[n];
	for(i=0;i<n;i++)
	{
		scanf("%s",&a[i].name);
		scanf("%s",&a[i].number);
		scanf("%d",&a[i].cj);
	}
	max=a[0].cj;
	min=a[0].cj;
	for(i=1;i<n;i++)
	{
		if(a[i].cj>max)
		{
			max=a[i].cj;
			maxpos=i;
		}
		if(a[i].cj<min)
		{
			min=a[i].cj;
			minpos=i;
		}
	}
	printf("%s %s\n",a[maxpos].name,a[maxpos].number);
	printf("%s %s",a[minpos].name,a[minpos].number);
}

```

#### PAT乙级1005
```c++
#include<stdio.h>
int main()
{
    int n,a[102],c[102],b[102]= {0},i,j,len=0,k;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);//数据输入
    for(i=1; i<=n; i++)
        c[i]=a[i];//数组复制，其实在上面赋值，就不用再循环了，写的啰嗦了。
    for(i=1; i<=n; i++)
    {
        for(k=1; k<=n; k++)//数组重赋值，因为会改变数组a的内容，所以重新赋值了。
        {
            if(a[k]>0)a[k]=c[k];//如果是‘覆盖’的数就不再赋值了。
        }
        if(a[i]<0)continue;//对覆盖的数进行跳过
        while(a[i]!=1)//3n+1猜想
        {
            if(i==1||a[i]>0)
            {
                if(a[i]%2==0)
                {
                    a[i]=a[i]/2;
                    for(j=1; j<=n; j++)//暴力去遍历，数据量比较弱就没超时。
                    {
                        if(j==i)
                            continue;
                        if(a[j]==a[i])
                            a[j]=-1;
                    }
                }
                else
                {
                    a[i]=(3*a[i]+1)/2;
                    for(j=1; j<=n; j++)//暴力去遍历，数据量比较弱就没超时。
                    {
                        if(j==i)
                            continue;
                        if(a[j]==a[i])
                            a[j]=-1;
                    }
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if(a[i]>0)
            len++;
    }
    for(k=1; k<=n; k++)
    {
        if(a[k]>0)a[k]=c[k];
    }
    for(i=1; i<=n; i++)//经典的冒泡排序，有基础多余的。
    {
        for(j=1; j<n-i+1; j++)
        {
            if(a[j+1]>a[j])
            {
                k=a[j+1];
                a[j+1]=a[j];
                a[j]=k;
            }
        }
    }
    for(i=1; i<len; i++)
        printf("%d ",a[i]);
    printf("%d",a[i]);
}

```

#### PAT乙级1006
```c++
//按照题意输出就行
#include<stdio.h>
int main()
{
  int n,i,a,b,c;
  scanf("%d",&n);//题目保证n小于1000
  a=n/100;
  c=n%10;
  b=(n-a*100)/10;
  for(i=1;i<=a;i++)
    printf("B");
  for(i=1;i<=b;i++)
    printf("S");
  for(i=1;i<=c;i++)
    printf("%d",i);
  return 0;
}
```

#### PAT乙级1007
```c++
//暴力
#include<stdio.h>
int isimpre(int n)//经典素数判断
{
	int i;
	for(i=2; i*i<=n; i++)//for(int i=2;i<(int)sqrt(n);i++)
		if(n%i==0)return 0;
	return 1;
}
int main()
{
	int i,n,sum=0;
	scanf("%d",&n);
	for(i=5; i<=n; i++)
	{
		if(isimpre(i)==1&&isimpre(i-2)==1)//暴力去找。
			sum++;
	}
	printf("%d\n",sum);
}
```

#### PAT乙级1008
```c++
//处理下标就可以了，实际没必要移动数组，只需要输出即可。
#include<stdio.h>
int main()
{
	int a[100],i,m,n,temp;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	while(m>=n)//下标处理
	{
		m=m-n;
	}
	temp=n-m;
	for(; temp<n; temp++)
		printf("%d ",a[temp]);
	for(i=0; i<n-m-1; i++)
		printf("%d ",a[i]);
	printf("%d",a[n-m-1]);
	return 0;
}
```

#### PAT乙级1009
```c++
//很有意思的一道题，把每个单词作为一个整体，实际考虑输入之后进行用split分割‘ ’
//，然后倒序输出即可，我采用的是模拟。
#include<stdio.h>
#include<string.h>
int main()
{
	char zhenghua[100]={0};
	int i,j,n=0,len;
	gets(zhenghua);
	len=strlen(zhenghua);
	j=len;
	for(i=0; i<len; i++)
	{
		if(zhenghua[i]==' ')
			n++;
	}
	if(n==0)
		puts(zhenghua);//如果没有空格直接输出
	for(; len>0; len--)//从后到前遍历
	{
		if(zhenghua[len]==' ')//碰到空格代表有单词组成
		{
			for(i=len+1; i<j; i++)
				printf("%c",zhenghua[i]); 
			printf(" ");
			j=len;
			n--;
		}
	}
	j++;
	for(i=0;i<j;i++)//输出最后一个单词
	{
		if(zhenghua[i]==' ')
		{
			j=i;
			for(i=0;i<j;i++)
			{
				printf("%c",zhenghua[i]);
			}
		}
	}
	return 0;
}
//数据相加会溢出整形，但实际用更大的数来存就没问题了
#include <stdio.h>
#include <inttypes.h>
int main()
{
    int T;

long int A, B, C;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        scanf("%ld %ld %ld", &A, &B, &C);
        printf("Case #%d: %s\n", i + 1, A + B > C ? "true" : "false");
    }

    return 0;
}
```

#### PAT乙级1010
```c++
#include <cstdio>
using namespace std;
int main() {
	int a, b;
	bool isfirst = true;
	while(~scanf("%d %d", &a, &b)) {//输入到文本结束
	if(b == 0) continue;
		if(!isfirst)
	printf(" ");
		else
	isfirst = false;
	printf("%d %d", a * b, b - 1);//读取到数据就进行输出
	}
	if(isfirst) {//零多项式情况
	printf("0 0");
	}
	return 0;
}
```

#### PAT乙级1011
```c++
//数据相加会溢出整形，但实际用更大的数来存就没问题了
#include <stdio.h>
#include <inttypes.h>
int main()
{
    int T;
    long int A, B, C;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        scanf("%ld %ld %ld", &A, &B, &C);
        printf("Case #%d: %s\n", i + 1, A + B > C ? "true" : "false");
    }

    return 0;
}
```

#### PAT乙级1012
```c++
//注意细心处理每一个数字就可以了
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>

int main()
{
	long n, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, i, temp, count2 = 0, count3 = 0, count4 = 0;
	scanf("%ld", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%ld", &temp);
		if (temp % 5 == 0)//按照题意进行判断分类
		{
			if (temp % 2 == 0)
				a1 = a1 + temp;
		}
		if (temp % 5 == 1)
		{
			if (count2 % 2 == 0)
				a2 = a2 + temp;
			else a2 = a2 - temp;
			count2++;
		}
		if (temp % 5 == 2)
		{
			count3++;
		}
		if (temp % 5 == 3)
		{
			a4 = a4 + temp;
			count4++;
		}
		if (temp % 5 == 4)
		{
			if (temp>a5)
				a5 = temp;
		}
	}
	if (a1 == 0) printf("N ");//按照题意输出
	else printf("%ld ", a1);
	if (count2 == 0) printf("N ");//判断条件应该是count2这类数字是否出现过
	else printf("%ld ", a2);
	if (count3 == 0) printf("N ");
	else printf("%ld ", count3);
	if (a4 == 0) printf("N ");
	else printf("%.1f ", a4*1.0 / count4);
	if (a5 == 0) printf("N\n");
	else printf("%ld\n", a5);
	system("pause");
	return 0;
}
```

#### PAT乙级1013
```c++
//向后找素数就可以了
#include<stdio.h>
int isper(int n)//经典素数判断
{
    int i;
    for(i=2; i*i<=n; i++)//i*i<=n换成i<=(int)sqrt(n)更好
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
    int n,sum,temp=1,m=0,count=0;
    scanf("%d %d",&n,&sum);
    for(;m<=sum;temp++)
    {
    	if(isper(temp))m++;//向后数数，实际保存这个信息更好，之后还要进行判断。
    	if(m>n&&isper(temp))
    	{
    		printf("%d",temp);
    		count++;
    		if(count%10!=0&&m-1!=sum)printf(" ");
    		if(count%10==0&&m-1!=sum) printf("\n");
		}
	}
	return 0;
}
```

#### PAT乙级1014
```c++
//细心题
#include<stdio.h>
#include<string.h>
#include <cstdio>
#include<iostream>

void find_days(char a[], char b[])//找日期
{
	int tmp;
	char day[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	for (int i = 0; i < strlen(a) && i < strlen(b); i++)//遍历
	{
		if (a[i] >= 'A'&&a[i] <= 'G'&&a[i] == b[i])
		{
			std::cout << day[b[i] - 'A'] << " ";
			a[i] = b[i] = '$';
			tmp = i;
			break;
		}
	}

	for (int i = tmp; i < strlen(b) && i < strlen(a); i++)
	{
		if (((b[i] >= '0'&&b[i] <= '9') && a[i] == b[i]))
		{
			printf("%02d:", a[i]-'0');//按照格式输出
			break;
		}
		if ((b[i] >= 'A'&&b[i] <= 'N') && a[i] == b[i])
		{
			printf("%02d:", a[i] - 'A' + 10);
			break;
		}
	}
}

void find_seconds(char *a, char *b)
{
	for (int i = 0; i <strlen(a)&&i<strlen(b); i++)//遍历
	{
		if (a[i] == b[i]&&((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')))
		{
			printf("%02d", i);
			break;
		}
	}
}

int main()
{
	char daya[62], dayb[62], timea[62], timeb[62];//61字符数组有俩个测试点没过！！！，数组还是尽量比题目大。
	int i, j;
	fgets(daya,62,stdin);
	fgets(dayb, 62, stdin);
	fgets(timea, 62, stdin);
	fgets(timeb, 62, stdin);
	find_days(daya, dayb);
	find_seconds(timea, timeb);
	system("pause");
	return 0;
}

```

#### PAT乙级1015
```c++
//经典pat排序问题，按照要求进行写cmp，注意需要分类排序，总的排序会超时。。。。。。
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct STUDENT
{
	char id[18];
	int de;
	int cai;
}Student;

bool Cmp(STUDENT s1, STUDENT s2)
{
	if ((s2.de + s2.cai) != (s1.de + s1.cai))
	{
		return (s2.de + s2.cai) < (s1.de + s1.cai);
	}
	else if (s2.de !=s1.de)
	{
		return s1.de>s2.de;
	}
	else
	{
		return strcmp(s1.id,s2.id)<0;//注意返回值，如果写成strcmp (s1.id,s2.id);就会错误有排序的错误
	}
}

int main()
{

	int n,low,high,cnt=0;
	scanf("%d%d%d", &n, &low, &high);
	STUDENT stu;
	vector<STUDENT> v1,v2,v3,v4;//4类人分别进行排序，总的进行排序会超时
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d%d", stu.id, &stu.de, &stu.cai);
		if (stu.de >= high && stu.cai >= high)
			v1.push_back(stu);
		else if (stu.de >= high && stu.cai >= low)
			v2.push_back(stu);
		else if (stu.de >= low && stu.de < high&&stu.cai >= low && stu.cai < high&&stu.de >= stu.cai)
			v3.push_back(stu);
		else if (stu.de >= low && stu.de < high&&stu.cai >= low && stu.de < stu.cai)
			v4.push_back(stu);
		else
			cnt++;
	}

	sort(v1.begin(), v1.end(), Cmp);
	sort(v2.begin(), v2.end(), Cmp);
	sort(v3.begin(), v3.end(), Cmp);
	sort(v4.begin(), v4.end(), Cmp);

	cout << n - cnt << endl;//按题意输出

	vector<Student>::iterator iter;//迭代器遍历vector 
	
	for (iter =v1.begin(); iter !=v1.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	for (iter = v2.begin(); iter != v2.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	for (iter = v3.begin(); iter != v3.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	for (iter = v4.begin(); iter != v4.end(); iter++)
	{
		printf("%s %d %d\n", iter->id, iter->de, iter->cai);
	}
	system("pause");
	return 0;

}
```

#### PAT乙级1016
```c++
//模拟，实际做了复杂了，func和funb可以合并的
#include <stdio.h>
int powc(int a,int b)//double的pow会有精度的问题，所以自己写了一个int的
{
    int i;
    for(i=1;i<b;i++)
        a*=10;
    return a;
}
int func(long a,int la)//寻找个位数字la在a出现的次数
{
    int len,t,time;
    long temp=a;
    for(len=0;temp>=1;len++)
        temp/=10;
    for(time=0;len>0;len--)
    {
        t=a/powc(10,len-1);
        if(len==1)t=a;
        a=a-t*powc(10,len-1);
        if(t==la)time++;
    }
    return time;
}
int funb(int a,int time)//组成新数字
{
    int i,t;
    t=a;
    for(i=1;i<time;i++)
    {
        a=10*a+t;
    }
    if(time==1)a=t;
    if(time==0)a=0;
    return a;
}
int main()
{
    long a,b;
    int la,lb;
    scanf("%ld %d %ld %d",&a,&la,&b,&lb);
    printf("%d",funb(la,func(a,la))+funb(lb,func(b,lb)));//输出数据相加
    return 0;
}

```

#### PAT乙级1017
```c++
//大数相除，模拟除法的过程。题目保证a是一位数，简化了计算
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int a;
    cin >> a;
    int len = s.length();
    int t = 0;
    int temp = 0;
    t = (s[0] - '0') / a;
    if ((t != 0 && len > 1) || len == 1) {
        cout << t;
    }
    temp = (s[0] - '0') % a;
    for (int i = 1; i < len; i++) {//模拟除法
        t = (temp * 10 + s[i] - '0') / a;
        cout << t;
        temp = (temp * 10 + s[i] - '0') % a;
    }
    cout << " " << temp;
    return 0;
}
```

#### PAT乙级1018
```c++
//模拟判断
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int jiawin = 0, yiwin = 0;
    int jia[3] = {0}, yi[3] = {0};
    for (int i = 0; i < n; i++) {
        char s, t;
        cin >> s >> t;
        if (s == 'B' && t == 'C') {//对输入进行判断
            jiawin++;
            jia[0]++;
        } else if (s == 'B' && t == 'J') {
            yiwin++;
            yi[2]++;
        } else if (s == 'C' && t == 'B') {
            yiwin++;
            yi[0]++;
        } else if (s == 'C' && t == 'J') {
            jiawin++;
            jia[1]++;
        } else if (s == 'J' && t == 'B') {
            jiawin++;
            jia[2]++;
        } else if (s == 'J' && t == 'C') {
            yiwin++;
            yi[1]++;
        }
    }
    cout << jiawin << " " << n - jiawin - yiwin << " " << yiwin << endl << yiwin << " " << n - jiawin - yiwin << " " << jiawin << endl;
    int maxjia = jia[0] >= jia[1] ? 0 : 1;
    maxjia = jia[maxjia] >= jia[2] ? maxjia : 2;
    int maxyi = yi[0] >= yi[1] ? 0 : 1;
    maxyi = yi[maxyi] >= yi[2] ? maxyi : 2;
    char str[4] = {"BCJ"};
    cout << str[maxjia] << " " << str[maxyi];
    return 0;
}
```

#### PAT乙级1019
```c++
//趣味题，注意输出格式
#include<stdio.h>
int powc(int a)
{
    int temp=1,i=1;
    for(i=1; i<=a; i++)
        temp*=10;
    return temp;
}
void func(char a[],int temp)//实际输入字符串就可以了，这个是数字转化为字符串
{
    int i,t;
    for(i=0; i<4; i++)
    {
        t=temp/powc(3-i);
        temp=temp-powc(3-i)*t;
        a[i]=t+48;
    }
}
int aveper(char a[],int flag)//俩数相加
{
    int b[5],i,j,temp;
    for(i=0; i<4; i++)
        b[i]=a[i]-48;
    for(i=0; i<3; i++)
        for(j=0; j<4-i-1; j++)
        {
            if(flag==1)
            {
                if(b[j]>b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
            if(flag==0)
            {
                if(b[j]<b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }
    temp=b[0]*1000+b[1]*100+b[2]*10+b[3];
    return temp;
}
int main()
{
    int sum,judge;
    char a[4];
    scanf("%d",&judge);
    if(judge>9999)return 0;
    func(a,judge);
    do//do,while循环
    {
        sum=aveper(a,0)-aveper(a,1);
        printf("%04d - %04d = %04d\n",aveper(a,0),aveper(a,1),sum);
        if(sum==0||sum==6174)break;
        func(a,sum);
    }
    while(1);
    return 0;
}

```

#### PAT乙级1020
```c++
//贪心算法，排序，贪心去找当前单价最大的
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
//小坑库存和销售量可能是小数
struct  node
{
	double cnt;
	double p;
};
bool cmp(node a, node b)
{
	return a.p <= b.p;
}
using namespace std;
int main()
{
	int n, D;
	double ans = 0;
	scanf("%d%d", &n, &D);
	vector<node> v;
	node tmp;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &tmp.cnt);
		v.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &tmp.cnt);
		v[i].p = 1.0*tmp.cnt / v[i].cnt;//计算单价
	}
	sort(v.begin(), v.end(),cmp);//排序找单价最大的
	for (int i = v.size() - 1; i >= 0; i--)//按要求判断
	{
		if (D > v[i].cnt)
		{
			ans += v[i].cnt*v[i].p;
			D -= v[i].cnt;
		}
		else if (D <= v[i].cnt)
		{
			ans += v[i].p*D;
			break;
		}
	}
	printf("%.2lf", ans);
	return 0;
}
```

#### PAT乙级1021
```c++
//实际没必要存储a只需要一位一位的读取判断即可，用一个索引的概念
#include<stdio.h>
int main()
{
    char a[1000];//存储1000位的正整数N
    int b[11]= {0},i;
    scanf("%s",a);
    for(i=0; a[i]!='\0';i++)
        b[(int)a[i]-48]+=1;//将字符数组强制转化成int型，然后相减。
    for(i=0; i<=9; i++)
        if(b[i])
            printf("%d:%d\n",i,b[i]);
    return 0;
}
```

#### PAT乙级1022
```c++
//注意题目给出的范围进行分析
#include<iostream>
#include<string>

using namespace std;

/*字符串转化到整形数组存储每一位
void restore(string A,string B,int *a,int *b)
{
	for (int i = A.length() - 1,j=0; i >= 0; i--)
	{
		a[j++] = A[i]-48;
	}

	for (int i = B.length() - 1, j = 0; i >= 0; i--)
	{
		b[j++] = B[i]-48;
	}
}*/

int main()
{
	/*没看题意认为整形存不下，实际是可以的，做了一个转化操作，实际没必要
	int numa[1001] = { 0 }, numb[1002] = { 0 }, D;
	memset(numa, 0, sizeof(numa));
	memset(numb, 0, sizeof(numb));
	string A, B;
	cin >> A >> B >> D;
	restore(A, B, numa, numb);

	for (int i = 0; i < 1001; i++)
	{
		numa[i] += numb[i];
		while (numa[i]>=D)
		{
			numa[i] -= D;
			numa[i + 1] += 1;
		}
	}

	for (int i = 1000, flag = 0; i >= 0; i--)
	{
		if (numa[i] != 0) 
		{
			flag = 1;
		}
		if (flag == 1)
			cout << numa[i];
	}
	system("pause");
	return 0;
	*/
	int A, B, D, numa[40] = { 0 }, N, i = 0, flag = 0;
	cin >> A >> B >> D;
	N = A + B;
	while (N != 0)//numa存每一位，进行相加。
	{
		numa[i++] = N % D;
		N = N / D;
	}
	for (int i = 39; i >= 0; i--)
	{
		if (numa[i] != 0)
		{
			flag = 1;
		}
		if (flag == 1)
		{
			cout << numa[i];
		}
	}
	if (flag == 0)
	{
		cout << 0;
	}
	system("pause");
	return 0;

}
```

#### PAT乙级1023
```c++
//处理特殊情况即可
#include<iostream>

using namespace std;

int main()
{
	int temp, book[11] = { 0 },cnt=0;
	while (cin >> temp)//从低位到高位的个数
	{
		book[cnt++] = temp;
	}

	for (int i = 1; i <= 9; i++)//寻找第一位最高位
	{
		if (book[i] != 0)
		{
			cout << i;
			book[i] -= 1;
			break;
		}
	}

	for (int i = 0; i <= 9; i++)//直接输出剩余数字
	{
		while (book[i] != 0)
		{
			cout << i;
			book[i] -= 1;
		}
	}

	system("pause");
	return 0;
}
```

#### PAT乙级1024
```c++
//模拟，转化科学记数法为普通数字
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string A,B;
	int e=0;
	cin >> A;
	int i = A.find('E');//寻找E的位置

	for (int k = i; k < A.size(); k++)//寻找指数
	{
		if (A[k] >= '0'&&A[k] <= '9')
		{
			e = e * 10 + A[k]-48;
		}
	}

	for (int k = 0; k < i; k++)//寻找整数部分
	{
		B += A[k];
	}

	if (A[i + 1] == '-')//判断是不是负数，进行输出
	{
		if (A[0] == '-')
		{
			cout << A[0];
		}
		cout << "0.";
		for (int i = 0; i < e-1; i++)
		{
			cout << 0;
		}

		for (int i = 1; i < A.find('E'); i++)
		{
			if (A[i] != '.')
			{
				cout << A[i];
			}
		}
	}
	else
	{
		if (B[0] == '-')
		{
			cout << B[0];
		}
		cout <<B[1];
		for (int i = 3; i < B.size(); i++,e--)
		{
			if (e == 0)
			{
				cout << ".";
			}
			cout << B[i];
		}
		while (e > 0)
		{
			cout << "0";
			e--;
		}
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1025
```c++
//有意思的模拟链表，进行反转
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
		reverse(v.begin() + i * K, v.begin() + (i + 1)*K);//强大的直接调用函数进行处理，注意处理边界即可
	for (int i = 0; i<v.size() - 1; i++) {       
		printf("%05d %d %05d\n", v[i].front, v[i].data, v[i+1].front);
	}
	printf("%05d %d %d\n", v[v.size() - 1].front, v[v.size() - 1].data, -1);

	system("pause");

	return 0;
}
```

#### PAT乙级1026
```c++

```

#### PAT乙级1027
```c++

```

#### PAT乙级1028
```c++

```

#### PAT乙级1029
```c++

```

#### PAT乙级1030
```c++

```

#### PAT乙级1031
```c++

```

#### PAT乙级1032
```c++

```

#### PAT乙级1033
```c++

```

#### PAT乙级1034
```c++

```

#### PAT乙级1035
```c++

```

#### PAT乙级1036
```c++

```

#### PAT乙级1037
```c++

```

#### PAT乙级1038
```c++

```

#### PAT乙级1039
```c++

```

#### PAT乙级1040
```c++

```

#### PAT乙级1041
```c++

```

#### PAT乙级1042
```c++

```

#### PAT乙级1043
```c++

```

#### PAT乙级1044
```c++

```

#### PAT乙级1045
```c++

```

#### PAT乙级1046
```c++

```

#### PAT乙级1047
```c++

```

#### PAT乙级1048
```c++

```

#### PAT乙级1049
```c++

```

#### PAT乙级1050
```c++

```

#### PAT乙级1051
```c++

```

#### PAT乙级1052
```c++

```

#### PAT乙级1053
```c++

```

#### PAT乙级1054
```c++

```

#### PAT乙级1055
```c++

```

#### PAT乙级1056
```c++

```

#### PAT乙级1057
```c++

```

#### PAT乙级1058
```c++

```

#### PAT乙级1059
```c++

```

#### PAT乙级1060
```c++

```

#### PAT乙级1061
```c++

```

#### PAT乙级1062
```c++

```

#### PAT乙级1063
```c++

```

#### PAT乙级1064
```c++

```

#### PAT乙级1065
```c++

```

#### PAT乙级1066
```c++

```

#### PAT乙级1067
```c++

```

#### PAT乙级1068
```c++

```

#### PAT乙级1069
```c++

```

#### PAT乙级1070
```c++

```

#### PAT乙级1071
```c++

```

#### PAT乙级1072
```c++

```

#### PAT乙级1073
```c++

```

#### PAT乙级1074
```c++

```

#### PAT乙级1075
```c++

```

#### PAT乙级1076
```c++

```

#### PAT乙级1077
```c++

```

#### PAT乙级1078
```c++

```

#### PAT乙级1079
```c++

```

#### PAT乙级1080
```c++

```

#### PAT乙级1081
```c++

```

#### PAT乙级1082
```c++

```

#### PAT乙级1083
```c++

```

#### PAT乙级1084
```c++

```

#### PAT乙级1085
```c++

```
