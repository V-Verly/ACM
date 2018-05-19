#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int main()
{
    char a[maxn];
    int i,n,flag=0,mark[50],t;
    scanf("%s",a);
    n=strlen(a);
    if(n<26) flag=0;
    else{
        t=0;
        for(i=0;i<n;i++)
        {
            if(a[i]-'a'<=t) {
                mark[t++]=i;
            }
            if(t==26) {flag=1;break;}
        }
        for(i=0;i<26;i++)
            a[mark[i]]=i+'a';
    }
    if(flag)
    {
        for(i=0;i<n;i++)
            printf("%c",a[i]);
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}
