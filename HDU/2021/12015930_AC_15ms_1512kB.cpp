#include <stdio.h>
int r(int a);
int main(void)
{
    int n,s,i,a;
        while(scanf("%d",&n)!=EOF&&n!=0)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            s+=r(a);
        }
        printf("%d\n",s);
    }
    return 0;
}
int r(int a)
{
    int s=0;
    s+=a/100,a%=100;
    s+=a/50,a%=50;
    s+=a/10,a%=10;
    s+=a/5,a%=5;
    s+=a/2,a%=2;
    s+=a;
    return s;
}