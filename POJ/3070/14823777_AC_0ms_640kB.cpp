#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Matrix
{
public:
    int s[2][2];
    Matrix(int a=0,int b=0,int c=0,int d=0)
    {
        s[0][0]=a;
        s[0][1]=b;
        s[1][0]=c;
        s[1][1]=d;
    }
    Matrix mul(Matrix a,Matrix b)
    {
        Matrix ans;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ans.s[i][j]=(a.s[i][0]*b.s[0][j]+a.s[i][1]*b.s[1][j])%10000;
        return ans;
    }
    Matrix pow(long long n)
    {
        Matrix ans(1,0,0,1),fib(1,1,1,0);
        while(n>0)
        {
            if(n&1!=0)
                ans=mul(ans,fib);
            fib=mul(fib,fib);
            n>>=1;
        }
        return ans;
    }
};

int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF&&n!=-1)
    {
        Matrix ans;
        ans=ans.pow(n);
        printf("%d\n",ans.s[0][1]);
    }
    return 0;
}
