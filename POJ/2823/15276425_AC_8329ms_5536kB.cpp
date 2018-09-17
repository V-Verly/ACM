#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=1e6+10;
int a[maxn];

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        deque <int> que;
        for(int i=0;i<n;i++)
        {
            while(!que.empty()&&que.front()<i-k+1) que.pop_front();
            while(!que.empty()&&a[que.back()]>=a[i]) que.pop_back();
            que.push_back(i);
            if(i-k+1>=0)
            {
                printf("%d",a[que.front()]);
                printf("%c",i==n-1?'\n':' ');
            }
        }
        while(!que.empty()) que.pop_back();
        for(int i=0;i<n;i++)
        {
            while(!que.empty()&&que.front()<i-k+1) que.pop_front();
            while(!que.empty()&&a[que.back()]<=a[i]) que.pop_back();
            que.push_back(i);
            if(i-k+1>=0)
            {
                printf("%d",a[que.front()]);
                printf("%c",i==n-1?'\n':' ');
            }
        }
    }
    return 0;
}
