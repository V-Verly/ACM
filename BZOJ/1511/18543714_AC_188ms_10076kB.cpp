#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

char a[maxn];
int nex[maxn],f[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",a+1);
	int j=0;
	nex[1]=0;
	for(int i=1;i<n;i++)
    {
        while(j&&a[i+1]!=a[j+1]) j=nex[j];
        if(a[i+1]==a[j+1]) j++;
        nex[i+1]=j;
    }
    long long ans=0;
	for(int i=1;i<=n;i++)
    {
        if(nex[i])
        {
            f[i]+=f[nex[i]]+(i-nex[i]);
            ans+=f[i];
        }
    }
    printf("%lld\n",ans);
}
