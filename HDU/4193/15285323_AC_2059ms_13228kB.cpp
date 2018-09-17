#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2e6+10;
int a[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i+n]=a[i];
        }
        a[0]=0;
        for(int i=1;i<=2*n-1;i++)
            a[i]+=a[i-1];
        deque <int> que;
        int ans=0;
        for(int i=1;i<=2*n-1;i++)
        {
            while(!que.empty()&&que.front()<i-n) que.pop_front();
            while(!que.empty()&&a[que.back()]>a[i]) que.pop_back();
            que.push_back(i);
            int st=i-n;
            if(st>=0&&a[que.front()]-a[st]>=0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
