#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,s,h[105],m[105];
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&h[i],&m[i]);
        int a=0,b=0,sub;
        for(int i=0;i<n;i++)
        {
            sub=m[i]-b+(h[i]-a)*60;
            if(sub>=s+1) break;
            else
            {
                b=m[i]+s+1;
                a=h[i]+b/60;
                b%=60;
            }
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
