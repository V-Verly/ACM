#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
void BFS(int n)
{
    queue <long long> que;
    que.push(1);
    while(!que.empty())
    {
        long long k=que.front();
        que.pop();
        if(k%n==0)
        {
            printf("%lld\n",k);
            break;
        }
        que.push(k*10);
        que.push(k*10+1);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        BFS(n);
    }
    return 0;
}
