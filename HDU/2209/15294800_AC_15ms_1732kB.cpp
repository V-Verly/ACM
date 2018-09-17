#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf=0x3f3f3f3f;

int main()
{
    char s[25];
    int a[25];
    while(scanf("%s",s)!=EOF)
    {
        int n=strlen(s);
        for(int i=0; i<n; i++)
            a[i]=s[i]-'0';
        int ans=inf,tmp=0;
        for(int i=1; i<n; i++)
        {
            if(a[i-1])
            {
                a[i-1]=!a[i-1];
                a[i]=!a[i];
                if(i+1<n)
                    a[i+1]=!a[i+1];
                tmp++;
            }
        }
        if(!a[n-1])
            ans=tmp;
        for(int i=0; i<n; i++)
            a[i]=s[i]-'0';
        a[0]=!a[0];
        a[1]=!a[1];
        tmp=1;
        for(int i=1; i<n; i++)
        {
            if(a[i-1])
            {
                a[i-1]=!a[i-1];
                a[i]=!a[i];
                if(i+1<n)
                    a[i+1]=!a[i+1];
                tmp++;
            }
        }
        if(!a[n-1])
            ans=min(ans,tmp);
        if(ans==inf)
            printf("NO\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
