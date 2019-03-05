#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+10;

char a[maxn];
int nex[maxn],f[maxn];

int main()
{
	int n,k;
	scanf("%s",a+1);
    n=strlen(a+1);
    scanf("%d",&k);
    int j,ans=0;
	for(int s=1;s<=n-2*k;s++)
    {
        f[s]=s;
        nex[s]=j=s-1;
        for(int i=s+1;i<=n;i++)
        {
            while(j>=s&&a[i]!=a[j+1]) j=nex[j];
            if(a[i]==a[j+1]) j++;
            nex[i]=j;
            f[i]=(j-s+1<k)?i:f[j];
            if((f[i]-s+1)*2<i-s+1) ans++;
        }
    }
    printf("%d\n",ans);
}
