#include <stdio.h>
int main(void)
{
    int n,s1,s2,s3,t1,t2,t3;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        t1=n,t2=n,t3=n;
        s1=0,s2=0,s3=0;
        while(t1>0)
        {
            s1+=t1%10;
            t1/=10;
        }
        while(t2>0)
        {
            s2+=t2%16;
            t2/=16;
        }
        while(t3>0)
        {
            s3+=t3%12;
            t3/=12;
        }
        if(s1==s2&&s1==s3) printf("%d is a Sky Number.\n",n);
        else printf("%d is not a Sky Number.\n",n);
    }
    return 0;
}