#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=10000+10;
bool vis[maxn];
vector<int> prime,db;
int ans[maxn]={0};

void init()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=100;i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
           // for(int j=0;j<prime.size()&&i+prime[j]<=10000;j++)
               // db.push_back(i+prime[j]);
            for(int j=i*i;j<=10000;j+=i)
                vis[j]=true;
        }
    }
    for(int i=100;i<=10000;i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
            //for(int j=0;j<prime.size()&&i+prime[j]<=10000;j++)
               // db.push_back(i+prime[j]);
        }
    }
    //sort(db.begin(),db.end());
    /*for(int i=0;i<prime.size();i++)
    {
        for(int j=0;j<db.size()&&prime[i]+db[j]<=10000;j++)
        {
            ans[prime[i]+db[j]]++;
            if(prime[i]+db[j]==9) printf("%d %d\n",prime[i],db[j]);
        }

    }*/
    for(int i=0;i<prime.size();i++)
    {
        for(int j=i;j<prime.size()&&prime[i]+prime[j]<=10000;j++)
        {
            for(int k=j;k<prime.size()&&prime[i]+prime[j]+prime[k]<=10000;k++)
                ans[prime[i]+prime[j]+prime[k]]++;
        }
    }
}

int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",ans[n]);
    return 0;
}
