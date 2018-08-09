#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=1e4+10;

int main()
{
    int n,k,ans=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int k=i*i+j*j,d=sqrt(k);
            if(d*d==k&&d<=n) ans++;
        }
    }


    printf("%d\n",ans);
    return 0;
}
