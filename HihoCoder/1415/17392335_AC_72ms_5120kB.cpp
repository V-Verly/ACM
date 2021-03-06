#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2e5+10;

char a[maxn],b[maxn];

char s[maxn];
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
}

void getHeight()
{
    for(int i=0;i<n;i++) ra[sa[i]]=i;
    for(int i=0,k=0;i<n;i++)
    {
        if(k) k--;
        int j=sa[ra[i]-1];
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k]) k++;
        height[ra[i]]=k;
    }
}


int main()
{
    scanf("%s%s",a,b);
    int la=strlen(a),lb=strlen(b);
    n=la+lb+1;
    for(int i=0;i<la;i++) s[i]=a[i]; s[la]='#';
    for(int i=0;i<lb;i++) s[i+la+1]=b[i];
    build_sa(256);
    getHeight();
    int ans=0;
    for(int i=1;i<n;i++)
        if(sa[i]>la&&sa[i-1]<la||sa[i]<la&&sa[i-1]>la) ans=max(ans,height[i]);
    printf("%d\n",ans);
    return 0;
}
