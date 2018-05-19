#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int s[maxn];

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    int n,a,b,ans=0,count=0;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        ans+=s[i];
    }

    sort(s+1,s+n,cmp);
    double t;
    for(int i=1;i<n;i++)
    {
        t=a*s[0]/ans;
        if(t>=b) break;
        count++;
        ans-=s[i];
    }
    printf("%d\n",count);
    return 0;
}
