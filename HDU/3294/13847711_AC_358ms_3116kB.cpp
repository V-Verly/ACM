#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;
char s[maxn],t[2*maxn],w[maxn];
int l[2*maxn],len;

void getstr()
{
    int k=0;
    t[k++]='$';
    for(int i=0;i<len;i++)
    {
        t[k++]='#';
        t[k++]=s[i];
    }
    t[k++]='#';
    t[k]=0;
    len=k;
}

void manacher()
{
    getstr();
    int mx=0,id;
    for(int i=1;i<len;i++)
    {
        if(mx>i) l[i]=min(l[2*id-i],mx-i);
        else l[i]=1;
        while(t[i+l[i]]==t[i-l[i]])
            l[i]++;
        if(l[i]+i>mx)
            mx=l[i]+i,id=i;
    }
}

int main()
{
    char a[5];
    while(scanf("%s%s",a,s)!=EOF)
    {
        len=strlen(s);
        for(int i=0;i<len;i++)
        {
            s[i]-=a[0]-'a';
            if(s[i]<'a') s[i]+=26;
        }
        manacher();
        int ans=0,po;
        for(int i=0;i<len;i++)
        {
            if(l[i]>ans)
            {
                ans=l[i];
                po=i;
            }
        }
        po/=2;
        po--;
        ans--;
        int st=po-ans/2,en=po+ans/2;
        if(ans%2==0) st++;
        if(ans>1)
        {
            printf("%d %d\n",st,en);
            for(int i=st;i<=en;i++)
                printf("%c",s[i]);
            printf("\n");
        }
        else
            printf("No solution!\n");
    }
    return 0;
}
