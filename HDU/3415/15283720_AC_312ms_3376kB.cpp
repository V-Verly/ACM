#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=2e5+10;
int a[maxn],sum[maxn];

int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i+n]=a[i];
        }
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n+k;i++)
            sum[i]=sum[i-1]+a[i];
        deque<int> que;
        int ans=-0x3f3f3f3f,st,en;
        for(int i=1;i<=n+k;i++)
        {
            while(!que.empty()&&que.front()<i-k) que.pop_front();
            while(!que.empty()&&sum[que.back()]>=sum[i-1]) que.pop_back();
            que.push_back(i-1);
            if(ans<sum[i]-sum[que.front()])
            {
                ans=sum[i]-sum[que.front()];
                st=que.front()+1;
                en=i;
            }
        }
        if(en>n) en-=n;
        printf("%d %d %d\n",ans,st,en);
    }
    return 0;
}
