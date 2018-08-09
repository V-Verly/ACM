#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int m,s[150],a[150],b[150];
    while(scanf("%d",&m)!=EOF)
    {
        int n=0,x=0,y=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(s,0,sizeof(s));
        while(m)
        {
            s[n++]=m%3;
            m/=3;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==3)
            {
                s[i]=0;
                s[i+1]++;
            }
            else if(s[i]==0)
            {
                a[i]=0;
                b[i]=0;
            }
            else if(s[i]==1)
            {
                a[i]=0;
                b[i]=1;
            }
            else
            {
                a[i]=1;
                b[i]=0;
                s[i+1]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]) x++;
            if(b[i]) y++;
        }
        if(s[n]) b[n]=1,y++;
        printf("%d",x);
        int base=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]) printf(" %d",base);
            base*=3;
        }
        base=1;
        printf("\n%d",y);
        for(int i=0;i<n+1;i++)
        {
            if(b[i]) printf(" %d",base);
            base*=3;
        }
        printf("\n");
    }
    return 0;
}
