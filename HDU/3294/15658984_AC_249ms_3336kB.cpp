#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2e5+10;
char s[2*maxn],str[2*maxn];
int Len[maxn*2],len;

void getstr()
{
    int k=0;
    str[k++]='$';
    for(int i=0;i<len;i++)
        str[k++]='#',str[k++]=s[i];
    str[k++]='#';
    len=k;
}

void Manacher()
{
    getstr();
    int mx=0,id;
    memset(Len,0,sizeof Len);
    for(int i=1;i<len;i++)
    {
        if(mx>i) Len[i]=min(Len[2*id-i],mx-i);
        else Len[i]++;
        while(str[i+Len[i]]==str[i-Len[i]]) Len[i]++;
        if(Len[i]+i>mx)
            mx=Len[i]+i,id=i;
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
        Manacher();
        int ans=0,pos;
        for(int i=0;i<len;i++)
        {
            if(ans<Len[i])
            {
                ans=Len[i];
                pos=i;
            }
        }
        pos=pos/2-1;
        ans--;
        int st=pos-ans/2,en=pos+ans/2;
        if(ans%2==0) st++;
        if(ans>1)
        {
            printf("%d %d\n",st,en);
            for(int i=st;i<=en;i++)
                printf("%c",s[i]);
            printf("\n");
        }
        else printf("No solution!\n");
    }
    return 0;
}
