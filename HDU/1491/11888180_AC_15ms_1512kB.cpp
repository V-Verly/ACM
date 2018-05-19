#include <stdio.h>
int sum(int m,int d);
int main(void)
{
    int m,d,t,s,s0;
    s0=sum(10,21);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&d);
        s=sum(m,d);
        if(s<s0) printf("%d\n",s0-s);
        else if(s==s0) printf("It's today!!\n");
        else printf("What a pity, it has passed!\n");
    }
}
int sum(int m,int d)
{
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int t,i;
    t=0;
    for(i=0;i<m;i++)
        t=t+a[i];
    t=t+d;
    return t;
}