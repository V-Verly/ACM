#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=3e6+10;
long long euler[maxn];

void init()
{
    memset(euler,0,sizeof(euler));
    euler[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!euler[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                if(!euler[j])
                    euler[j]=j;
                euler[j]=euler[j]/i*(i-1);
            }
        }
        euler[i]+=euler[i-1];
    }
}


int main()
{
    int a,b;
    init();
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a>b) swap(a,b);
        printf("%lld\n",euler[b]-euler[a-1]);
    }
    return 0;
}
