//求一个数字的个各位数字
#include<string>
#include<iostream>
using namespace std;
int main()
{
    long n=0,a[1000],lenn;
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
