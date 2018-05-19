#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod=1e9+9;
const int maxn=1e5+10;
char s[maxn];

long long pow(long long a,long long b)
{
    long long ans=1,base=a;
    while(b)
    {
        if(b&1)
            ans*=base;
        base*=base;
        base%=mod;
        ans%=mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    long long n,a,b,k;
    scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
    scanf("%s",s);
    long long A=pow(a,n),B=1;
    long long inva=pow(a,mod-2),invb=pow(b,mod-2);    //
    long long ans=0,sum;
    for(int i=0;i<k;i++)
    {
        if(s[i]=='+') ans+=A*B;
        else ans-=A*B;
        A=A*inva%mod;
        B=B*b%mod;
    }
    long long q=pow(inva,k)*pow(b,k)%mod;
    if(q==1)
        sum=((n+1)/k*ans%mod+mod)%mod;
    else
        sum=(ans*(pow(q,(n+1)/k)-1)%mod*pow(q-1,mod-2)%mod+mod)%mod;
    printf("%lld\n",sum);
    return 0;
}
