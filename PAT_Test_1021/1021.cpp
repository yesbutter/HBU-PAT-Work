#include<stdio.h>
int main()
{
    char a[1000];//�洢1000λ��������N
    int b[11]= {0},i;
    scanf("%s",a);
    for(i=0; a[i]!='\0';i++)
        b[(int)a[i]-48]+=1;//���ַ�����ǿ��ת����int�ͣ�Ȼ�������
    for(i=0; i<=9; i++)
        if(b[i])
            printf("%d:%d\n",i,b[i]);
    return 0;
}