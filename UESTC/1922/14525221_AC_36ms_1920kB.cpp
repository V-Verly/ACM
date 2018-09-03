#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=1e5+10;
struct data
{
    int n,t;
};

int main()
{
    int n,op,t,a,b;
    queue <data> que;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&op,&t);
        if(op==1)
        {
            data tmp;
            scanf("%d%d",&tmp.n,&tmp.t);
            tmp.t+=t;
            que.push(tmp);
        }
        else if(op==2)
        {
            while(!que.empty())
            {
                data tmp=que.front();
                if(t>=tmp.t) que.pop();
                else
                {
                    que.pop();
                    break;
                }
            }
        }
        else if(op==3)
        {
            while(!que.empty())
            {
                if(t>=que.front().t) que.pop();
                else
                {
                    printf("%d\n",que.front().n);
                    break;
                }
            }
            if(que.empty()) printf("%d\n",-1);
        }
    }
    return 0;
}
