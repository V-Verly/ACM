#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
char s[maxn];

int main()
{
    int n,len,r[3],mark[256];
    scanf("%d",&n);
    for(int k=0;k<3;k++)
    {
        scanf("%s",s);
        memset(mark,0,sizeof(mark));
        len=strlen(s);
        for(int i=0;i<len;i++)
            mark[s[i]]++;
        int ans=0;
        for(int i=0;i<256;i++)
            ans=max(ans,mark[i]);
        r[k]=min(len,ans+n);
        if(n==1&&len==ans) r[k]=len-1;
    }
    if(r[0]>r[1]&&r[0]>r[2]) printf("Kuro\n");
    else if(r[1]>r[0]&&r[1]>r[2]) printf("Shiro\n");
    else if(r[2]>r[0]&&r[2]>r[1]) printf("Katie\n");
    else printf("Draw\n");
    return 0;
}
