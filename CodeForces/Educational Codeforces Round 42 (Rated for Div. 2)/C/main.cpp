#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

bool isSqrt(int n)
{
    for(int i=1;n>0;i+=2) n-=i;
    return 0==n;
}

struct num{
int n,step;
};

int BFS(int n)
{
    if(isSqrt(n)) return 0;
    queue <num> que;
    num a;
    a.n=n;
    a.step=0;
    que.push(a);
    while(!que.empty())
    {
        num t=que.front();
        printf("%d\n",t.n);
        que.pop();
        if(isSqrt(t.n)) {
            return t.step;
        }
       int tmp=0,r=0,ans=0,g,len=0,ls;
       int s=t.n;
       g=s;
       while(g)
       {
           g/=10;
           len++;
       }
       g=s;
       while(s)
       {
           tmp=s%10;
           g=s/10;
           for(int i=0;i<r;i++)
           {
               tmp*=10;
               g*=10;
           }
            num q;
            q.n=ans+g;
            q.step=t.step+1;
            s/=10;

            if(g) que.push(q);
            if(r==len-1&&ls&&ans)
            {
                num q;
                q.n=ans;
                q.step=t.step+1;
                que.push(q);
            }
             ans+=tmp;
            ls=tmp;
            r++;
       }

    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a=BFS(n);
    printf("%d\n",a);
    return 0;
}
