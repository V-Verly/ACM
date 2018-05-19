#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,flag;
    char a[102],b[102];
    int cnt1[26],cnt2[26];
    while(~scanf("%s%s",a,b))
    {
        flag=1;
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        n=strlen(a);
        for(i=0;i<n;i++)
            cnt1[a[i]-'A']++;
        for(i=0;i<n;i++)
            cnt2[b[i]-'A']++;
        sort(cnt1,cnt1+26);
        sort(cnt2,cnt2+26);
        for(i=0;i<26;i++)
        if(cnt1[i]!=cnt2[i]) {flag=0;break;}
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
