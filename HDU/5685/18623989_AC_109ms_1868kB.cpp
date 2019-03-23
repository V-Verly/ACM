#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;
const int mod=9973;

char s[maxn];
int h[maxn];

int pow(int a,int b=mod-2)
{
    int ans=1,base=a;
    while(b)
    {
        if(b&1) (ans*=base)%=mod;
        (base*=base)%=mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    int q,l,r;
    while(scanf("%d",&q)!=EOF)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        h[0]=1;
        for(int i=1;i<=n;i++)
        {
            h[i]=h[i-1]*(s[i]-28)%mod;
        }
        while(q--)
        {
            scanf("%d%d",&l,&r);
            int x=pow(h[l-1]);
            printf("%d\n",h[r]*x%mod);
        }

    }
    return 0;
}
