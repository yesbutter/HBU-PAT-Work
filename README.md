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
//数据输入处理，注意不足一秒四舍五入到一秒
#include<iostream>
using namespace std;
int main()
{
	int a, b,h,m,s;
	cin >> a >> b;
	a = b - a;
	if (a % 100 >= 50)
	{
		a = a / 100 + 1;
	}
	else
	{
		a = a / 100;
	}
	s = a % 60;
	a -= s;
	a /= 60;
	m = a % 60;
	a -= m;
	h = a / 60;
	printf("%02d:%02d:%02d", h, m, s);
	return 0;
}
```

#### PAT乙级1027
```c++
//模拟，计算。
#include<stdio.h>
int func(int n)//计算一半需要多少行
{
    int i,temp,p;
    p=(n+1)/2;
    for(i=2,temp=1; temp<=p; i++)
        temp=temp+(2*i-1);
    return i-2;
}
int main()
{
    char c;
    int n,i,j,k,temp,count=0;
    scanf("%d ",&n);
    c=getchar();
    temp=func(n);
    for(i=temp; i>0; i--)//输出上半部分，注意每行不能输出多余的空格
    {
        for(k=temp-i; k>0; k--)
            printf(" ");
        for(j=2*i-1; j>0; j--)
        {
            printf("%c",c);
            count++;
        }
        printf("\n");
    }
    for(i=2; i<=temp; i++)
    {
        for(k=i; k<temp; k++)
            printf(" ");
        for(j=2*i-1; j>0; j--)
        {
            printf("%c",c);
            count++;
        }
        printf("\n");
    }
    printf("%d",n-count);//输出剩余的字符数量
    return 0;
}
```

#### PAT乙级1028
```c++
//注意输入数据处理，题意给出判断的合法年龄
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct person
{
	char name[10];
	int year, month, day;
};
person tmp;

bool judge(person p)//判断年龄是否合法，不合法就拒绝进入
{
	if (p.year > 2014 || p.year<1814)
		return false;
	if (p.year != 2014 && p.year != 1814)
		return true;
	if (p.year == 2014)
	{
		if (p.month > 9)
			return false;
		if (p.month == 9 && p.day > 6)
			return false;
		return true;
	}
	if (p.year == 1814)
	{
		if (p.month < 9)
			return false;
		if (p.month == 9 && p.day < 6)
			return false;
		return true;
	}
}

int cmp(person a, person b)//比较算法
{
	if (a.year != b.year)
		return a.year < b.year;
	if (a.month != b.month)
		return a.month < b.month;
	if(a.day!=b.day)
		return a.day < b.day;
	return 0;
}
int main()
{
	int n;
	vector<person> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d/%d/%d", &tmp.name, &tmp.year, &tmp.month, &tmp.day);
		if (judge(tmp))//输入进行盘但
		{
			v.push_back(tmp);
		}
	}
	sort(v.begin(), v.end(), cmp);
	if (v.size() >= 1)
		cout << v.size() << " " << v[0].name << " " << v[v.size() - 1].name;
	else
		cout << 0;//如果合法不足一个也要输出人数
	system("pause");
	return 0;
}
```

#### PAT乙级1029
```c++
//数据输入判断，判断相应位置如果是1表示已经输入了，如果是0就表示没有输入，表示这个按键坏了
#include <iostream>
#include <string.h>


using namespace std;

int main()
{
	char tmp;
	char s1[2049];
	char s2[2049];
	int right[257] = { 0 }, cnt = 0;
	cin.getline(s1, 2049);
	cin.getline(s2, 2049);
	for (int i = 0; i<strlen(s1); i++)
	{
		if (s1[i] >= 'a'&&s1[i] <= 'z')
			s1[i] = s1[i] - 32;
	}
	for (int i = 0; i<strlen(s2); i++)
	{
		if (s2[i] >= 'a'&&s2[i] <= 'z')
			s2[i] = s2[i] - 32;
		right[s2[i]] = 1;//这个按键没有坏
	}
	for (int i = 0; i < strlen(s1); i++)
	{
		if (right[s1[i]] == 0)//初始化为0
		{
			printf("%c", s1[i]);
			right[s1[i]] = 2;//已经输出过的就不再输出
		}
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1030
```c++
//暴力会T的题目，二重循环，加一个跳过，设计很巧妙
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<long long> v;

int main()
{
	long long N, p,cnt=0,min,tmp;

	cin >> N >> p;
	for (long long i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	min = v[0];
	for (int j = 0; j < N; j++) {
		for (int i =j+cnt; i < N; i++)//这个跳cnt非常巧妙！！！		
		{
			//第一次找到的最大如果不能再向后跳cnt个数字的话就继续判断就没有意义
			if (v[j]*p < v[i])
			{
				break;
			}
			if (i - j + 1>cnt)
				cnt = i - j + 1;
		}
	}
	cout << cnt;
	system("pause");
	return 0;
}
```

#### PAT乙级1031
```c++
//根据题意编程，对每一个进行检验
#include<stdio.h>
#define X 58
int main()
{
    int quanzhong[18]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},sum,i,j=0,count=0;
    char check[11]= {'1','0','X','9','8','7','6','5','4','3','2'},idcard[18];
    int n;
    scanf("%d",&n);
    getchar();
    do
    {
        gets(idcard);
        for(i=0,sum=0; i<17; i++)
        {
            sum=(idcard[i]-48)*quanzhong[i]+sum;
        }
        sum=sum%11;
        if(idcard[17]==check[sum])
            count++;
        else puts(idcard);
        j++;
    }
    while(j<n);
    if(count==n)printf("All passed");
    return 0;
}

```

#### PAT乙级1032
```c++
//巧妙利用索引数组，然后遍历找最大值，数组开小会有测试点不过
#include <stdio.h>
int main()
{
    int maxs=0,maxpos=0,i,n,p,chengji,cj[100100]= {0},book[100100]= {0};
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d",&p,&chengji);
        cj[p]=chengji+cj[p];//索引存储
        book[p]=1;
    }
    for(i=1; i<=n; i++)
        if(book[i])
            if(cj[i]>maxs)
            {
                maxs=cj[i];
                maxpos=i;
            }
    printf("%d %d",maxpos,maxs);
    return 0;
}
```

#### PAT乙级1033
```c++
//记录字符是否出现，然后输出
#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;
    int bad[128] = {0};
    while((c = getchar()) != '\n')     
        bad[toupper(c)] = 1;
    while((c = getchar()) != '\n')  
        if(!bad[toupper(c)] && !(isupper(c) && bad['+']))
              putchar(c);
    return 0;
}
```

#### PAT乙级1034
```c++
//模拟，注意处理除0情况
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <cstdio>  
using namespace std;
long long int a, b, c, d;

//辗转相除法：求最大公约数  
long long int gcd(long long int t1, long long int t2) {
	return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}//本来自己写了个,然后超时了= =||  

void func(long long int m, long long int n) {
	int flag1 = 0;
	int flag2 = 0;
	if (n == 0) {
		cout << "Inf";
		return;
	}
	if (m == 0) {
		cout << 0;
		return;
	}

	if (m < 0) {
		m = 0 - m;
		flag1 = 1;
	}
	if (n < 0) {
		n = 0 - n;
		flag2 = 1;
	}
	int flag = 0;
	if (flag1 == 1 && flag2 == 1) {
		flag = 0;
	}
	else if (flag1 == 1 || flag2 == 1) {
		flag = 1;
	}
	if (m == n) {
		if (flag == 1)
			cout << "(-1)";
		else
			cout << "1";
		return;
	}

	long long int x = m % n;
	long long int y = m / n;
	if (x == 0) {
		if (flag == 0)
			cout << y;
		else
			cout << "(-" << y << ")";
		return;
	}
	else {
		long long int t1 = m - y * n;
		long long int t2 = n;
		long long int t = gcd(t1, t2);
		t1 = t1 / t;
		t2 = t2 / t;
		if (flag == 1) {
			cout << "(-";
			if (y != 0)
				cout << y << " " << t1 << "/" << t2;
			else
				cout << t1 << "/" << t2;
			cout << ")";
		}
		else {
			if (y != 0)
				cout << y << " " << t1 << "/" << t2;
			else
				cout << t1 << "/" << t2;
		}
	}
}

void add() {
	long long int m, n;
	m = a * d + b * c;
	n = b * d;
	func(a, b);
	cout << " + ";
	func(c, d);
	cout << " = ";
	func(m, n);
	cout << endl;
}

void min() {
	long long int m, n;
	m = a * d - b * c;
	n = b * d;
	func(a, b);
	cout << " - ";
	func(c, d);
	cout << " = ";
	func(m, n);
	cout << endl;
}

void multi() {
	long long int m, n;
	m = a * c;
	n = b * d;
	func(a, b);
	cout << " * ";
	func(c, d);
	cout << " = ";
	func(m, n);
	cout << endl;
}

void div() {
	long long int m, n;
	m = a * d;
	n = b * c;
	func(a, b);
	cout << " / ";
	func(c, d);
	cout << " = ";
	func(m, n);
	cout << endl;
}

int main() {
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	add();
	min();
	multi();
	div();
	return 0;
}
```

#### PAT乙级1035
```c++

```

#### PAT乙级1036
```c++
//大一集训的代码，模拟控制输出，实际没必要这么复杂
#include<stdio.h>
int main()
{
	char c;
	int flag=1,n,i,j;
	scanf("%d",&n);
	getchar();
	scanf("%c",&c);
	if(n%2==0)/控制行数就可以了，没必要这样去写
	{
		for(i=1; i<=n/2; i++)
		{
			if(i==n/2)flag=1;
			for(j=1; j<=n; j++)
			{
				if(flag==0)
				{
					if(j==1||j==n)
						printf("%c",c);
					else printf(" ");
				}
			}

			for(j=1; j<=n; j++)
			{
				if(flag==1)
					printf("%c",c);
			}
			flag=0;
			printf("\n");
		}
	}
	else
	{
		for(i=1; i<=n/2+1; i++)
		{
			if(i==n/2+1)flag=1;
			for(j=1; j<=n; j++)
			{
				if(flag==0)
				{
					if(j==1||j==n)
						printf("%c",c);
					else printf(" ");
				}

			}

			for(j=1; j<=n; j++)
			{
				if(flag==1)
					printf("%c",c);
			}
			flag=0;
			printf("\n");
		}
	}
	return 0;
}
```

#### PAT乙级1037
```c++
#include<stdio.h>
void swapc(int *a,int *b)
{
    int swap;
    swap=*a;
    *a=*b;
    *b=swap;
}
int main()
{
    int g1,s1,k1,g2,s2,k2,flag=0;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    if(g1-g2>0||(g1-g2==0&&s1-s2>0)||(g1-g2==0&&s1-s2==0&&k1-k2>0))//判断是不是负数
    {
        flag=1;
        swapc(&s1,&s2);
        swapc(&g1,&g2);
        swapc(&k1,&k2);
    }
    if(k2>=k1)//计算输出，还有一种做法都转化到最小的位，然后计算再换算
        k2=k2-k1;
    else
    {
        s2--;
        k2=k2-k1+29;
    }
    if(s2>=s1)
        s2=s2-s1;
    else
    {
        g2--;
        s2=s2-s1+17;
    }
    if(flag==1)printf("-");
    printf("%d.%d.%d",g2-g1,s2,k2);
    return 0;
}
```

#### PAT乙级1038
```c++
//索引数组的巧妙利用
#include<stdio.h>
int main()
{
    int n,i,a[101]={0},temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        a[temp]+=1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        printf("%d",a[temp]);
        if(i!=n-1)printf(" ");
    }
    return 0;
}
```

#### PAT乙级1039
```c++
//索引数组的巧妙利用
#include<stdio.h>
int main()
{
    int len=0,a[128]={0},queshao=0,count=0;
    char temp;
    do
    {
        scanf("%c",&temp);
        a[(int)temp]+=1;//把对应数组放赋值
        len++;
    }while(temp!='\n');
    do
    {
        scanf("%c",&temp);
        if(a[(int)temp])
        {
            a[(int)temp]-=1;
        }
        else queshao++;
        count++;
    }while(temp!='\n');
    if(queshao==0)//判断是不是满足yes
        printf("Yes %d",len-count);
    else printf("No %d",queshao);
    return 0;
}
```

#### PAT乙级1040
```c++
//思路巧妙，理解别人的思路
#include<stdio.h>
#include<string.h>
int main()
{
    char c[100001];
    gets(c);
    int len,i,p=0,t=0,result=0;
    len=strlen(c);
    for(i=0; i<len; i++)
    {
        if(c[i]=='T')
                t++;
    }
    for(i=0; i<len; i++)
   {
        if(c[i]=='P')p++;
        if(c[i]=='T')t--;
        if(c[i]=='A')
            result=((p*t)%1000000007+result)%1000000007;
    }
    printf("%d",result);
    return 0;
}
```

#### PAT乙级1041
```c++
//数据输入处理，利用下标进行输出
#include<iostream>
#include<string>

using namespace std;

struct student {
	string name;
	int no;
};

int main()
{
	student s,v[1002];
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s.name >> tmp >> s.no;
		v[tmp] = s;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		cout << v[tmp].name << " " << v[tmp].no << endl;
	}
	return 0;
}
```

#### PAT乙级1042
```c++
//统计出现次数最多的英文字母
#include <iostream>

using namespace std;

int main()
{
	char tmp;
	int a[257] = { 0 }, max = -1, maxpos = -1;
	while (cin >> tmp)
	{
		if (tmp == '\n')
			break;
		if (tmp >= ' ')
		{
			a[tmp]++;
		}
	}

	for (int i = 'a'; i <= 'z'; i++)
	{
		a[i] += a[i - 32];
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
			maxpos = i;
		}
	}
	printf("%c %d", maxpos, max);
	system("pause");
	return 0;
}
```

#### PAT乙级1043
```c++
//数据输入处理，判断输出
#include<iostream>

using namespace std;

int main()
{
	int p=0,a=0,T=0,e=0,s=0,t=0;//记录对应的出现次数
	char tmp;
	while (cin >> tmp)
	{
		if (tmp == 'P')
			p++;
		if (tmp == 'A')
			a++;
		if (tmp == 'T')
			T++;
		if (tmp == 'e')
			e++;
		if (tmp == 's')
			s++;
		if (tmp == 't')
			t++;
	}

	while (p!=0|| a != 0 || T != 0 || e != 0 || s != 0 || t != 0)
	{
		if (p != 0)
		{
			cout << 'P';
			p--;
		}
		if (a != 0)
		{
			cout << 'A';
			a--;
		}
		if (T != 0)
		{
			cout << 'T';
			T--;
		}
		if (e != 0)
		{
			cout << 'e';
			e--;
		}
		if (s != 0)
		{
			cout << 's';
			s--;
		}
		if (t != 0)
		{
			cout << 't';
			t--;
		}
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1044
```c++
//进制转化，判断是数字还是火星文，注意细节处理。
#include<iostream>
#include<string>
#include<string.h>

std::string low_letter[13]  = { "tret","jan", "feb", "mar", "apr", "may", 
	"jun", "jly", "aug", "sep", "oct", "nov", "dec"};
std::string high_letter[13] = { "tret","tam", "hel", "maa", "huh", "tou", 
	"kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void read(std::string tmp)
{
	if (tmp[0] >= '0'&&tmp[0] <= '9')
	{
		int n = 0;
		for (int i = 0; i < tmp.size(); i++)
			n = n * 10 + tmp[i] - '0';
		if (n < 13)
			std::cout << low_letter[n] << std::endl;
		else if (n % 13==0)//13整数的时候只输出整数部分，比如26就读hel
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
		int low=0, high=0;//字符串处理
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
```

#### PAT乙级1045
```c++

```

#### PAT乙级1046
```c++
//输入判断，输出
#include<stdio.h>
int main()
{
    int jia=0,yi=0,a,b,c,d,n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(b==a+c&&d!=b)/判断
            yi++;
        if(d==a+c&&d!=b)
            jia++;
    }
    printf("%d %d",jia,yi);
    return 0;
}
```

#### PAT乙级1047
```c++
//索引数组，输入判断处理
#include<stdio.h>
int main()
{
    int n,i,a[1000]={0},max=0,maxpos=0,name,number,grades;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d-%d %d",&name,&number,&grades);
        a[name]+=grades;
        if(max<a[name])//进行判断是否大于最大
        {
            maxpos=name;
            max=a[name];
        }
    }
    printf("%d %d",maxpos,max);
    return 0;
}
```

#### PAT乙级1048
```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

void restore(char *a, char *b, int *c, int *d)
{
	for (int i = strlen(a)-1, j = 0; i >= 0; i--, j++)
	{
		c[j] = a[i] - 48;
	}

	for (int i = strlen(b)-1, j = 0; i >= 0; i--, j++)
	{
		d[j] = b[i] - 48;
	}

}

int main()
{
	char key_value[4] = { "JQK" };
	char A[102], B[102];
	int numa[102] = { 0 }, numb[102] = { 0 };
	int cnt = 1;
	scanf("%s %s", A, B);
	restore(A, B, numa, numb);//数据存储到int数组中，相加需要从最低位开始存放所以倒序存储
	
	for (int i = 0, len = strlen(A) >= strlen(B) ? strlen(A) : strlen(B); i < len; i++)//倒序加密
	{
		if (i % 2 == 0)
		{
			numb[i] = (numa[i] + numb[i]) % 13;
		}
		if (i % 2 == 1)
		{
			numb[i] = numb[i] - numa[i];
			if (numb[i] < 0)
			{
				numb[i] += 10;
			}
		}
	}

	for (int i = (strlen(A) >= strlen(B) ? strlen(A) : strlen(B))-1; i >=0; i--)//正序输出
	{
		if (numb[i] > 9)
			cout << key_value[numb[i]-10];
		else
		{
			cout << numb[i];
		}
	}
	/*for (int i = strlen(B) - 1,j=strlen(A)-1; j>=0 && i >= 0; i--,j--,cnt++)
	{//输出复杂的思路
		if (cnt == 2) 
		{
			cnt = 0;
		}
		if (cnt == 1)
		{
			B[i] = (B[i] + A[j] - 96) % 13 + 48;
		}
		if (cnt == 0)
		{
			B[i] = B[i] - A[j];
			if (B[i] < 0)
				B[i] += 10;
			B[i] += 48;
		}
	}
	for (int i = 0; i < strlen(B); i++)
	{
		if (B[i] > '9')
		{
			B[i] = key_value[B[i] - '9' - 1];

		}
	}
	puts(B);*/
	system("pause");
	return 0;

}
```

#### PAT乙级1049
```c++
//数学题
#include <stdio.h>
int main()
{
    int i,n;
    double sum=0,p;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%lf",&p);
        sum+=p*(n-i)*(i+1);
    }
    printf("%.2lf",sum);
}
```

#### PAT乙级1050
```c++
//计算螺旋填充
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10001
int b[MAX];
int a[10001][10001]={0};
void fill(int m,int n);
int comp(const void* a,const void* b);
int main()
{   
    int i, N,n,m;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=sqrt(N);i++){
        if(N%i==0){
            n=i;
        }
    }
    m=N/n;
    qsort(b,N,sizeof(int),comp);
    fill(m,n);
    int j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {   
            printf("%d",a[i][j]);
            if(j!=n)
                putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
void fill(int m,int n)
{
    int i,j;
    int k=0;
    for(i=1;i<=n/2;i++)
    {
        for(j=i;j<=n-i;j++)        //填充区域1
            a[i][j] = b[k++];
        for(j=i;j<=m-i;j++)        //填充区域2
            a[j][n-i+1]=b[k++];
        for(j=n-i+1;j>i;j--)       //填充区域3
            a[m-i+1][j]=b[k++];
        for(j=m-i+1;j>i;j--)       //填充区域4
            a[j][i]=b[k++];
    }
    if(n%2==1)                      //处理多出来的空白部分
    {
        for(i=((n/2)+1);i<=m-(n/2);i++)
            a[i][(n/2)+1]=b[k++];
    }
}
int comp(const void* a,const  void* b)
{
    return  *(int*)b-*(int*)a;
}
```

#### PAT乙级1051
```c++
//注意判断，利用数学函数计算
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double r1, p1, r2, p2, A, B;
	cin >> r1 >> p1 >> r2 >> p2;
	A = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
	B = r1 * r2 * cos(p1) * sin(p2) + r1 * r2 * sin(p1) * cos(p2);
	if (A + 0.005 >= 0 && A < 0)
		printf("0.00");
	else
		printf("%.2f", A);
	if (B >= 0)
		printf("+%.2fi", B);
	else if (B + 0.005 >= 0 && B < 0)
		printf("+0.00i");
	else
		printf("%.2fi", B);
	return 0;
}
```

#### PAT乙级1052
```c++
//数据输入处理，处理字符
#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

void save(char *tmp,vector<string> &v)
{
	string p;
	for (int i = 0; tmp[i] != '\0'; i++)
	{
		if (tmp[i] == '[')//字符解析
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
		if (a[0] <= hand.size() && a[1] <= eye.size() && a[2] <= mouth.size() && a[3] <= eye.size() && a[4] <= hand.size()&&a[0]>0&&a[1]>0 && a[2]>0 && a[3]>0 && a[4]>0)
		{
			cout << hand[a[0] - 1] << "(" << eye[a[1] - 1] << mouth[a[2] - 1] << eye[a[3] - 1] << ")" << hand[a[4] - 1] << endl;
			//printf("%s(%s%s%s)%s\n",hand[a[0]-1], eye[a[1] - 1], mouth[a[2] - 1], eye[a[3] - 1], hand[a[4] - 1]);
		}
		else
		{
			printf("Are you kidding me? @\\/@\n");
		}
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1053
```c++
//数据输入处理
#include<iostream>

using namespace std;

int main()
{
	int n, cnta = 0, cntb = 0, k,cntday=0,p;
	double e, tmp;
	cin >> n >> e >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		cntday = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> tmp;
			if (tmp < e)
			{
				cntday++;
			}
		}
		if (cntday >(k / 2))
		{
			if(k <= p)//要满足条件一才是确认的，注意条件需要满足条件一
				cnta++;
			else
			{
				cntb++;
			}
		}
		
	}
	printf("%.1f%% %.1f%%", ((double)cnta / n*100),((double) cntb / n*100));
	system("pause");
	return 0;
}
```

#### PAT乙级1054
```c++
//输入函数处理
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main()
{
	int n, cnt = 0;
	char a[50], b[50];
	double temp, sum = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", a);
		/*    sscanf() - 从一个字符串中读进与指定格式相符的数据.
		函数原型:
		int sscanf(string str, string fmt, mixed var1, mixed var2 ...);
		int scanf(const char *format[, argument]...);
		说明：
		sscanf与scanf类似，都是用于输入的，只是后者以屏幕(stdin)为输入源，前者以固定字符串为输入源。*/
		sscanf(a, "%lf", &temp);
		sprintf(b, "%.2lf", temp);
		int flag = 0;
		for (int j = 0; j < strlen(a); j++) {
			if (a[j] != b[j]) {
				flag = 1;
			}
		}
		if (flag || temp < -1000 || temp > 1000) {
			printf("ERROR: %s is not a legal number\n", a);
			continue;
		}
		else {
			sum += temp;
			cnt++;
		}
	}
	if (cnt == 1) {
		printf("The average of 1 number is %.2lf", sum);
	}
	else if (cnt > 1) {
		printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
	}
	else {
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
}

```

#### PAT乙级1055
```c++
//数据处理，网上的思路
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
struct node {
	string name;
	int height;
};
int cmp(struct node a, struct node b) {
	return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main() {
	int n, k, m;
	cin >> n >> k;
	vector<node> stu(n);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name;
		cin >> stu[i].height;
	}
	sort(stu.begin(), stu.end(), cmp);
	int t = 0, row = k;
	while (row) {
		if (row == k) {
			m = n - n / k * (k - 1);
		}
		else {
			m = n / k;
		}
		vector<string> stemp(m);
		stemp[m / 2] = stu[t].name;
		// 左边一列
		int j = m / 2 - 1;
		for (int i = t + 1; i < t + m; i = i + 2)
			stemp[j--] = stu[i].name;
		// 右边一列
		j = m / 2 + 1;
		for (int i = t + 2; i < t + m; i = i + 2)
			stemp[j++] = stu[i].name;
		// 输出当前排
		cout << stemp[0];
		for (int i = 1; i < m; i++)
			cout << " " << stemp[i];
		cout << endl;
		t = t + m;
		row--;
	}
	return 0;
}
```

#### PAT乙级1056
```c++
//数字组合
#include<iostream>

using namespace std;

int main()
{
	int n, a[10], sum = 0, book[100] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				book[a[i] * 10 + a[j]] = 1;
			}
		}
	}
	for (int i = 10; i <= 99; i++)
	{
		if (book[i] == 1)
			sum += i;
	}
	cout << sum;
	system("pause");
}
```

#### PAT乙级1057
```c++
//二进制串，数数字
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char temp;
    int sum=0,zero=0,one=0;
    while(~scanf("%c",&temp))
    {
        if(temp>='A'&&temp<='Z')
            sum=sum+temp-'A'+1;
        if(temp>='a'&&temp<='z')
            sum=sum+temp-'a'+1;
    }
    while(sum)
    {
        if(sum%2)one++;
        else zero++;
        sum=sum/2;
    }
    cout<<zero<<" "<<one<<endl;
    return 0;
}

```

#### PAT乙级1058
```c++
//细心题
#include <cstdio>  
#include <vector>  
#include <set>  
using namespace std;
int main() {
	int n, m, temp, k;
	scanf("%d%d", &n, &m);
	vector<set<char>> right(m);
	vector<int> total(m), wrongCnt(m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &total[i], &temp, &k);
		for (int j = 0; j < k; j++) {
			char c;
			scanf(" %c", &c);
			right[i].insert(c);
		}
	}
	for (int i = 0; i < n; i++) {
		int score = 0;
		scanf("\n");
		for (int j = 0; j < m; j++) {
			if (j != 0) scanf(" ");
			scanf("(%d", &k);
			set<char> st;
			char c;
			for (int l = 0; l < k; l++) {
				scanf(" %c", &c);
				st.insert(c);
			}
			scanf(")");
			if (st == right[j]) {
				score += total[j];
			}
			else {
				wrongCnt[j]++;
			}
		}
		printf("%d\n", score);
	}
	int maxWrongCnt = 0;
	for (int i = 0; i < m; i++) {
		if (wrongCnt[i] > maxWrongCnt) {
			maxWrongCnt = wrongCnt[i];
		}
	}
	if (maxWrongCnt == 0)
		printf("Too simple");
	else {
		printf("%d", maxWrongCnt);
		for (int i = 0; i < m; i++) {
			if (wrongCnt[i] == maxWrongCnt) {
				printf(" %d", i + 1);
			}
		}
	}
	return 0;
}
```

#### PAT乙级1059
```c++
#include<iostream>
#include<string.h>

using namespace std;

bool isperime(int a)
{
	if (a <= 1)
		return false;
	for (int i = 2; i*i <=a; i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}
int book[20005];

int main()
{
	int n, tmp, temp;	
	cin >> n;
	memset(book, -1, sizeof(book));
	for (int i =1; i <=n; i++)
	{
		cin >> tmp;
		book[tmp]= i;
	}
	cin >> temp;
	for (int i = 0; i < temp; i++)
	{
		cin >> tmp;
		printf("%04d: ", tmp);
		if (book[tmp] == -2)
		{
			cout << "Checked" << endl;
		}
		if (book[tmp] == -1)
		{
			cout << "Are you kidding?" << endl;
		}
		if (book[tmp] == 1)
		{
			cout << "Mystery Award" << endl;
			book[tmp] = -2;
		}
		if (isperime(book[tmp])&&book[tmp]>1)
		{
			cout << "Minion" << endl;
			book[tmp] = -2;
		}
		if (!isperime(book[tmp]) &&book[tmp]>1)
		{
			cout << "Chocolate" << endl;
			book[tmp] = -2;
		}
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1060
```c++
//输入，排序，判断
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,tmp;
	bool flag=false;
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--)
	{
		if(v[i]<=v.size()-i){
			printf("%d",v.size()-i-1);
			flag=true;
			break;
		}
	}
	if(!flag)
		printf("%d",n);
	system("pause");
	return 0;
}


```

#### PAT乙级1061
```c++
//数据输入判断
#include<stdio.h>
int main()
{
    int people,number,grade[100],right[100],i,sum[100]={0},j,temp;
    scanf("%d %d",&people,&number);
    for(i=0;i<number;i++)
        scanf("%d",&grade[i]);
    for(i=0;i<number;i++)
        scanf("%d",&right[i]);//输入正确选项
    for(j=0;j<people;j++)
        for(i=0;i<number;i++)
    {
        scanf("%d",&temp);
        if(temp==right[i])//判断成绩
            sum[j]+=grade[i];
    }
    for(i=0;i<people;i++)
        printf("%d\n",sum[i]);
    return 0;
}
```

#### PAT乙级1062
```c++
//模拟判断，判断是否是最简分数
#include<stdio.h>
int funb(int a,int b)//最大公约数
{
    if(a<0||b<0)return 0;
    if(a>b)return funb(a-b,b);
    if(b>a)return funb(b-a,a);
    if(a==b)return a;
}
int func(int a,int b)//最小公倍数
{
    int p=a;
    for(p=a;p<=a*b;p++)
        if(p%a==0&&p%b==0)return p;
}
int main()
{
    int n1,n2,m1,m2,k,max,temp,a[1000],count=0,i;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);//数据输入
    max=func(m1,func(k,m2));
    n1=n1*max/m1;
    n2=n2*max/m2;
    if(n2<n1)//比较判断
    {
        temp=n2;
        n2=n1;
        n1=temp;
    }
    for(n1++;n1<n2;n1++)
    {
        if(n1%(max/k)==0)
            if(funb(n1*k/max,k)==1)//判断是否条件
        {
            a[count]=n1*k/max;
            count++;
        }
    }
    for(i=0;i<count;i++)
    {
        printf("%d/%d",a[i],k);
        if(i!=count-1)printf(" ");
    }
    return 0;
}

```

#### PAT乙级1063
```c++
//简单题
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    double max=0,temp,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&a,&b);
        temp=sqrt(a*a+b*b);
        if(temp>max)
            max=temp;
    }
    printf("%0.2lf",max);
    return 0;
}
```

#### PAT乙级1064
```c++
//先求出总和，判断和是否出现过，然后排序输出证号
#include<stdio.h>
#include<string.h>
int func(char c[])//数据转化
{
    int len,i,sum=0;
    len=strlen(c);
    for(i=0;i<len;i++)
        sum+=c[i]-48;
    return sum;
}
int main()
{
    int n,i,book[100]={0},count,temp,j,flag;
    scanf("%d",&n);
    getchar();
    char a[6];
    for(i=0,count=0;i<n;i++)
    {
        scanf("%6s",a);
        temp=func(a);
        for(j=0,flag=1;j<count;j++)
            if(temp==book[j])flag=0;
        if(flag)
        {
            book[count]=temp;
            count++;
        }
    }
    for(i=0;i<count;i++)//排序
        for(j=0;j<count-i-1;j++)
    {
        if(book[j]>book[j+1])
        {
            temp=book[j];
            book[j]=book[j+1];
            book[j+1]=temp;
        }
    }
    printf("%d\n",count);
    for(i=0;i<count;i++)//数据输出
    {
        printf("%d",book[i]);
        if(i!=count-1)printf(" ");
    }
    return 0;
}
```

#### PAT乙级1065
```c++
//下标合理利用，快排
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include <iostream>
#include<vector>
int book[100005], p[100005],book2[100005];
using namespace std;
int main()
{
	vector<int> ans;
	int n, tmp[2];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp[0] >> tmp[1];
		book[tmp[0]] = tmp[1];//出席
		book[tmp[1]] = tmp[0];//出席
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		book2[p[i]] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (book2[book[p[i]]] == 0)
			ans.push_back(p[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)cout << " ";
		printf("%05d", ans[i]);
		//cout << ans[i];
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1066
```c++
//数据输入过滤
#include<iostream>

using namespace std;

int a[501][501];
int main()
{
	int N, M, L, R, P,tmp;
	cin >> N >> M >> L >> R >> P;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			if (tmp >= L && tmp <= R)
				tmp = P;
			a[i][j] = tmp;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j != 0)cout << " ";
			printf("%03d", a[i][j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1067
```c++
//字符串处理
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
	//用getchar(）读取缓冲区多余的回车
	getchar();
	while (cnt<n)
	{
		//输入一行的字符串
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
```

#### PAT乙级1068
```c++
//map，数据存储，四周判断
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int m, n, tol;
vector<vector<int>> v;
int dir[8][2] = { { -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 } };
bool judge(int i, int j) {
	for (int k = 0; k < 8; k++) {
		int tx = i + dir[k][0];
		int ty = j + dir[k][1];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && v[i][j] - v[tx][ty] >= 0 - tol && v[i][j] - v[tx][ty] <= tol) return false;
	}
	return true;
}
int main() {
	int cnt = 0, x = 0, y = 0;
	scanf("%d%d%d", &m, &n, &tol);
	v.resize(n, vector<int>(m));
	map<int, int> mapp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);
			mapp[v[i][j]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapp[v[i][j]] == 1 && judge(i, j) == true) {
				cnt++;
				x = i + 1;
				y = j + 1;
			}
		}
	}
	if (cnt == 1)
		printf("(%d, %d): %d", y, x, v[x - 1][y - 1]);
	else if (cnt == 0)
		printf("Not Exist");
	else
		printf("Not Unique");
	return 0;
}
```

#### PAT乙级1069
```c++
//数据输入，处理判断顺序
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
```

#### PAT乙级1070
```c++
//数据输入，从最小开始进行判断
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,tmp;
	double ans=0;
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	ans=v[0];
	for(int i=1;i<v.size();i++)
	{
		ans=(ans+v[i]*1.0)/2.0;
	}
	printf("%d",(int)ans);
	system("pause");
	return 0;
}
```

#### PAT乙级1071
```c++
//数据输入判断
#include<stdio.h>
int judge(int a,int b,int t)
{
    if(t&&b>a)return 1;
    if(!t&&a>b)return 1;
    return 0;
}
int main()
{
    int T,K,n1,b,t,n2;
    scanf("%d %d",&T,&K);
    while(K--)
    {
        scanf("%d %d %d %d",&n1,&b,&t,&n2);
        if(T<t)
        {
            printf("Not enough tokens.  Total = %d.\n",T);
            continue;
        }
        if(judge(n1,n2,b))
        {
            printf("Win %d!  Total = %d.\n",t,T+t);
            T+=t;
        }
        else
        {
            printf("Lose %d.  Total = %d.\n",t,T-t);
            T-=t;
        }
        if(T==0)break;
    }
    if(T==0)printf("Game Over.");
    return 0;
}

```

#### PAT乙级1072
```c++
//索引，访问
#include <bits/stdc++.h>
int main()
{
    char name[10];
    int M,N,book[10000]= {0},temp,i,peo=0,count=0,flag=0,out[10],outcount=0;;
    scanf("%d %d",&N,&M);
    while(M--)
    {
        scanf("%d",&temp);
        book[temp]=1;//违禁物品
    }
    while(N--)
    {
        flag=0,outcount=0;;
        scanf("%s %d",name,&i);
        while(i--)
        {
            scanf("%d",&temp);
            if(book[temp])
            {
                out[outcount++]=temp;
                flag=1;
            }
        }
        count+=outcount;
        i=0;
        if(flag)
        {
            printf("%s: ",name);
            while(i<outcount)
            {
                if(i!=0)printf(" ");
                printf("%04d",out[i++]);
            }
            printf("\n");
            peo++;
        }
    }
    printf("%d %d",peo,count);
    return 0;
}

```

#### PAT乙级1073
```c++
//细心题
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
```

#### PAT乙级1074
```c++
//进制转化
#include <bits/stdc++.h>

using namespace std;
void Inverted(char *a,int *numa)
{
    for(int i=strlen(a)-1,j=0; i>=0; i--,j++)
        numa[j]=a[i]-'0';
}
int main()
{
    int temp,numa[25]= {0},numb[25]= {0},numc[25]= {0},flag=0,i;//a存放进制
    char a[25],b[25],c[25];
    cin>>a>>b>>c;
    Inverted(a,numa);
    Inverted(b,numb);
    Inverted(c,numc);
    for(int i=0; i<25; i++)
        if(numa[i]==0)
            numa[i]=10;
    for(int i=0; i<25; i++)
    {
        temp=numb[i]+numc[i]+flag;
        numb[i]=temp%numa[i];
        flag=temp/numa[i];
    }
    for(i=24;i>=0; i--)
    {
        if(numb[i]!=0)break;
        if(numb[i]==0)numb[i]=-1;
    }
    if(i==-1)printf("0");//数据判断
    for(; i>=0; i--)
        printf("%d",numb[i]);
    return 0;
}

```

#### PAT乙级1075
```c++
//分开进行分类
#include<bits/stdc++.h>

using namespace std;
struct Node
{
    int next;//尾地址
    int data;//值
} node[100000];
int main()
{
    int start,n,k,num,cnt=0;
    scanf("%d%d%d",&start,&n,&k);//k是扫描比较的数字
    for(int i = 0; i < n; i++)//数据输入
    {
        scanf("%d",&num);
        scanf("%d%d",&node[num].data,&node[num].next);
    }
    for(int i=start;;)
    {
        if(node[i].data<0)
        {
            if(cnt==0)
                printf("%05d %d ",i,node[i].data);
            if(cnt!=0)
                printf("%05d\n%05d %d ",i,i,node[i].data);
            cnt++;
        }
        if(node[i].next==-1)break;
        if(node[i].next!=-1)i=node[i].next;
    }
    for(int i=start;;)
    {
        if(node[i].data<=k&&node[i].data>=0)
        {
            if(cnt==0)
                printf("%05d %d ",i,node[i].data);
            if(cnt!=0)
                printf("%05d\n%05d %d ",i,i,node[i].data);
            cnt++;
        }
        if(node[i].next==-1)break;
        if(node[i].next!=-1)i=node[i].next;
    }
    for(int i=start;;)
    {
        if(node[i].data>k)
        {

            if(cnt==0)
                printf("%05d %d ",i,node[i].data);
            if(cnt!=0)
                printf("%05d\n%05d %d ",i,i,node[i].data);
            cnt++;
        }
        if(node[i].next==-1)break;
        if(node[i].next!=-1)i=node[i].next;
    }
    printf("-1");
    return 0;
}

```

#### PAT乙级1076
```c++
//数据输入处理
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	char ans[1024], tmp[4];
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%s", tmp);
			if (tmp[2] == 'T')
			{
				ans[i] = tmp[0] - 'A' + '1';
			}
		}
	}
	ans[n] = '\0';
	printf("%s", ans);
	system("pause");
	return 0;
}
```

#### PAT乙级1077
```c++
//数据筛选处理
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, M,tmp;
	vector<int> v,vs;
	cin >> n >> M;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		v.clear();
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp >=0 && tmp <=M)
			{
				v.push_back(tmp);
			}
		}
		sort(v.begin() + 1, v.end());
		for (int i = 2; i < v.size() - 1; i++)
		{
			sum += v[i];
		}
		sum /= v.size() - 3;
		vs.push_back((sum + v[0])*1.0 / 2 + 0.5);
	}
	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1078
```c++
//字符串处理
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
```

#### PAT乙级1079
```c++
//字符串处理，大数组在外面申请
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

char tmp[2049],s2[2049];
char s[2049];
char * add(char *s)//相加
{
	memset(tmp, '0', sizeof(tmp));
	int len = 0,lenb=0;
	for (len = 0; s[len] != '\0'; len++);
	for (int i = 0,temp; s[i] != '\0'; i++)
	{
		s2[i] = s[len - 1-i];
		temp = s[i] + s[len -1-i] - 96;
		if (temp >= 10)
		{
			temp -= 10;
			tmp[i + 1] += 1;
			if (i == len - 1)
				lenb++;
		}
		tmp[i] += temp;
		if (tmp[i] >= 48 + 10)
		{
			tmp[i] -= 10;
			tmp[i + 1] += 1;
			if (i == len - 1)
				lenb++;
		}
		lenb++;
	}
	s2[len] = '\0';
	tmp[lenb] = '\0';
	for (int i = 0; i < lenb / 2; i++)
	{
		swap(tmp[i], tmp[lenb - i-1]);
	}
	printf("%s + %s = %s\n", s,s2, tmp);
	return tmp;
}

bool judge(char *s)//判断回文
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}
int main()
{
	int cnt = 0;
	cin >> s;
	while (cnt < 10)
	{
		if (judge(s))
		{
			printf("%s is a palindromic number.\n", s);
			break;
		}
		strcpy(s,add(s));
		if (judge(s))
		{
			printf("%s is a palindromic number.\n", s);
			break;
		}
		cnt++;
	}
	if (cnt == 10)
		printf("Not found in 10 iterations.");
	system("pause");
	return 0;
}
```

#### PAT乙级1080
```c++
//数据分类处理，经典的排序
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
struct Student
{
	string name;
	int p = -1;
	int m = -1;
	int n = -1;
	int end = -1;
};
bool cmp(Student s1, Student s2)
{
	if (s1.end != s2.end)
		return s1.end > s2.end;
	else return s1.name.compare(s2.name)<0;
}
int main()
{
	map<string, int> m;
	vector<Student> v;
	string tmp;
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0, p = 0; i < a; i++)
	{
		cin >> tmp >> p;
		if (p >= 200)
		{
			Student temp;
			temp.name = tmp;
			temp.p = p;
			v.push_back(temp);
			m.insert(map<string, int>::value_type(tmp, v.size() - 1));
		}
	}

	for (int i = 0, M; i < b; i++)
	{
		cin >> tmp >> M;
		map<string, int>::iterator iter;
		iter = m.find(tmp);
		if (iter != m.end())
		{
			v[iter->second].m = M;
		}
	}
	for (int i = 0, M; i < c; i++)
	{
		cin >> tmp >> M;
		map<string, int>::iterator iter;
		iter = m.find(tmp);
		if (iter != m.end())
		{
			v[iter->second].n = M;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].m > v[i].n)
		{
			v[i].end = (int)(v[i].m*0.4 + v[i].n*0.6 + 0.5);
		}
		else
		{
			v[i].end = v[i].n;
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].end >= 60)
		{
			cout << v[i].name << " " << v[i].p << " " << v[i].m << " " << v[i].n << " " << v[i].end << endl;
		}
		else
		{
			break;
		}
	}
	system("pause");
	return 0;

}
```

#### PAT乙级1081
```c++
//字符串处理
#include<iostream>
#include<string>
using namespace std;

int judge(string s)//数据判断
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
```

#### PAT乙级1082
```c++
//数据处理，判断最大和最小
#include<iostream>

using namespace std;

int main()
{
	int idmin, idmax,mins=0x3f3f3f3f,maxs=-1,n,a[3];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[0] >> a[1] >> a[2];
		int tmp = a[1] * a[1] + a[2] * a[2];
		if (tmp < mins)
		{
			idmin = a[0];
			mins = tmp;
		}
		if (tmp > maxs)
		{
			idmax = a[0];
			maxs = tmp;
		}
	
	}
	printf("%04d %04d", idmin, idmax);
	system("pause");
	return 0;

}
```

#### PAT乙级1083
```c++
//输入，判断
#include<iostream>

using namespace std;

int main()
{
	int n, a[100005] = { 0 }, book[100005] = { 0 }, maxs = -1, mins = 0x3f3f3f3f;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int tmp = abs(i - a[i]);
		book[tmp] += 1;
		if (tmp > maxs)
		{
			maxs = tmp;
		}
		if (tmp < mins)
		{
			mins = tmp;
		}
	}
	for (int i = maxs; i >= mins; i--)
	{
		if (book[i] > 1)
		{
			cout << i <<" "<< book[i] << endl;
		}
	}
	system("pause");
	return 0;
}
```

#### PAT乙级1084
```c++
//读题，递归问题转化到循环，注意大数组要在外面声明
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

char s[120490];
char tmp[120490];
char* fun(char *s)
{
	int lenb = 0;
	for (int i = 0,len=strlen(s); i < len; i++)
	{
		int t=1;
		while (i < len - 1 && s[i] == s[i + 1])
		{
			i++;
			t++;
		}
		tmp[lenb++] = s[i];
		while (t != 0)
		{
			tmp[lenb++] = t % 10+'0';
			t /= 10;
		}
	}
	tmp[lenb] = '\0';
	return tmp;
}
int main()
{
	int t;
	cin >> s[0] >> t;
	s[1] = '\0';
	for (int i = 1; i < t; i++)
	{
		strcpy(s , fun(s));
	}
	printf("%s", s);
	return 0;
}
```

#### PAT乙级1085
```c++
//经典排序题
#include "iostream"
#include "vector"
#include "string"
#include "map"
#include <algorithm>
using namespace std;

struct node
{
	string school;
	double grade;
	int peocount;
	node(string school, int grade)
	{
		this->school = school;
		this->grade = grade;
		peocount = 1;
	}
};

void format(string &n)
{
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] >= 'A'&&n[i] <= 'Z')
			n[i] += 32;
	}
}
int cmp(node a, node b)
{
	if ((int)a.grade != (int)b.grade)
		return a.grade > b.grade;
	if (a.peocount != b.peocount)
		return (int)a.peocount < (int)b.peocount;
	return a.school<=b.school;
}
int main()
{
	map<string, int> m;
	vector<node> v;
	string name, g;
	int grade, cnt = 1,n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> g >> grade >> name;
		format(name);
		if (m.count(name)==0)
		{
			m.insert(make_pair(name, cnt++));
			int position = m[name] - 1;
			double gr;
			if (g[0] == 'A')
				gr = grade;
			else if (g[0] == 'B')
				gr = grade / 1.5;
			else if (g[0] == 'T')
				gr = grade * 1.5;
			node tmp(name, gr);
			v.push_back(tmp);
			
		}
		else
		{
			int position = m[name] - 1;
			double gr;
			if (g[0] == 'A')
				gr = grade;
			else if (g[0] == 'B')
				gr = grade / 1.5;
			else if (g[0] == 'T')
				gr = grade * 1.5;
			node tmp(name,gr);
			v[position].grade += gr;
			v[position].peocount += 1;
		}
	}
	sort(v.begin(), v.end(), cmp);
	cout << v.size() << endl;
	for (int i = 0,tmp; i < v.size(); i++)
	{
		if (i != 0 && (int)v[i].grade == (int)v[i - 1].grade)
			printf("%d %s %d %d\n", tmp, v[i].school.c_str(), (int)v[i].grade, v[i].peocount);
		else {
			printf("%d %s %d %d\n", i + 1, v[i].school.c_str(), (int)v[i].grade, v[i].peocount);
			tmp = i + 1;
		}
	}
	system("pause");
	return 0;
}
```
