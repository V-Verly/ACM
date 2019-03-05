#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;

int n,a[maxn],d[maxn][20],pos;
int cnt[maxn],val[maxn];
int num[maxn],L[maxn],R[maxn];

void init()
{
    for(int i=0;i<pos;i++) d[i][0]=cnt[i];
    for(int j=1;(1<<j)<=pos;j++)
        for(int i=0;i+(1<<j)-1<pos;i++)
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int RMQ(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1) k++;
    return max(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
    int q,l,r;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&q);
        l=0,pos=0;
        memset(cnt,0,sizeof cnt);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0,j;i<n;i++)
        {
            val[pos]=a[i];
            while(a[i]==a[l]&&i<n) L[i]=l,num[i]=pos,cnt[pos]++,i++;
            j=i-1;
            while(a[j]==a[l]&&j>=l) R[j]=i-1,j--;
            if(i==n) break;
            l=i,pos++;
            i--;
        }
        init();
        while(q--)
        {
            scanf("%d%d",&l,&r);
            l--; r--;
            if(num[l]==num[r]) printf("%d\n",r-l+1);
            else {
                int posl=num[l],posr=num[r],ans=max(R[l]-l+1,r-L[r]+1);
                if(num[l]<num[r]-1) ans=max(ans,RMQ(num[l]+1,num[r]-1));
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
