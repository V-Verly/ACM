#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod=10007;

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
                ans.s[i][j]=(a.s[i][0]*b.s[0][j]+a.s[i][1]*b.s[1][j])%mod;
        return ans;
    }
    int fib(long long n)
    {
        Matrix ans(1,0,0,1),fib(1,1,1,0);
        while(n>0)
        {
            if(n&1!=0)
                ans=mul(ans,fib);
            fib=mul(fib,fib);
            n>>=1;
        }
        return ans.s[0][0];
    }
};

int quickpower(int n)
{
	int ans=1,base=2;
	while(n>0)
	{
		if(n&1)
			ans=ans*base%mod;
		base=base*base%mod;
		n>>=1;
	}
	return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        Matrix a;
        printf("%d\n",((quickpower(n)-2*a.fib(n))%mod+mod)%mod);
    }
    return 0;
}
