#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2e4+10;

int s[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn],n;
int ra[maxn],height[maxn];

void build_sa(int m)
{
	int *x=t,*y=t2;
	for(int i=0;i<m;i++) c[i]=0;
	for(int i=0;i<n;i++) c[x[i]=s[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int p=0;
		for(int i=n-k;i<n;i++) y[p++]=i;
		for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		for(int i=0;i<m;i++) c[i]=0;
		for(int i=0;i<n;i++) c[x[y[i]]]++;
		for(int i=0;i<m;i++) c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(int i=1;i<n;i++)
			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if(p>=n) break;
		m=p;
	}
	for(int i=0;i<n;i++) ra[sa[i]]=i;
    for(int i=0,j=0;i<n;i++)
    {
        if(j) j--;
        while(s[i+j]==s[sa[ra[i]-1]+j]) j++;
        height[x[i]]=j;
    }
}

int main()
{
    int k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    if(k==1) return 0*printf("%d\n",n);
    build_sa(101);
    int ans=0;
    for(int i=1;i<=n-k+1;i++)
    {
        int mn=0x3f3f3f3f;
        for(int j=0;j<k-1;j++)
            if(mn>height[i+j]) mn=height[i+j];
        if(ans<mn) ans=mn;
    }
    printf("%d\n",ans);
    return 0;
}
