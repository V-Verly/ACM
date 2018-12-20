#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;

char s[maxn],t[maxn];

char tmp[maxn<<1];
int Len[maxn<<1],cnt[maxn];

int init(char *str)
{
    int i,len=strlen(str);
    tmp[0]='@';
    for(int i=1;i<=2*len;i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=str[i/2];
    }
    tmp[2*len+1]='#';
    tmp[2*len+2]='$';
    tmp[2*len+3]=0;
    return 2*len+1;
}

int manacher(char *str)
{
    int mx=0,ans=0,pos=0;
    int len=init(str);
    for(int i=1;i<=len;i++)
    {
        if(mx>i) Len[i]=min(mx-i,Len[2*pos-i]);
        else Len[i]=1;
        while(tmp[i-Len[i]]==tmp[i+Len[i]]) Len[i]++;
        if(Len[i]+i>mx) mx=Len[i]+i,pos=i;
    }
    for(int i=2;i<len;i++)
    {
        if(tmp[i]=='#'&&Len[i]==1) continue;
        int x=i/2-Len[i]/2,y=(Len[i]-1)/2;
        if((Len[i]-1)%2==0) y--;
        cnt[x]++;
        cnt[x+y+1]--;
    }
}

int extend[maxn],nex[maxn];

void getNext(char *s)
{
    int len=strlen(s);
    nex[0]=len;
    int pos=0;
    while(pos+1<len&&s[pos]==s[pos+1]) pos++;
    nex[1]=pos;
    int k=1,L;
    for(int i=2;i<len;i++)
    {
        pos=k+nex[k]-1;
        L=nex[i-k];
        if(i+L<=pos) nex[i]=L;
        else {
            int j=pos-i+1;
            if(j<0) j=0;
            while(i+j<len&&s[i+j]==s[j]) j++;
            nex[i]=j;
            k=i;
        }
    }
}

void getExtend(char *s,char *t)
{
    int lens=strlen(s),lent=strlen(t);
    getNext(t);
    int pos=0;
    while(pos<lens&&pos<lent&&s[pos]==t[pos]) pos++;
    extend[0]=pos;
    int k=0,L;
    for(int i=1;i<lens;i++)
    {
        pos=k+extend[k]-1;
        L=nex[i-k];
        if(i+L<=pos) extend[i]=L;
        else {
            int j=pos-i+1;
            if(j<0) j=0;
            while(i+j<lens&&j<lent&&s[i+j]==t[j]) j++;
            extend[i]=j;
            k=i;
        }
    }
}

int main()
{
    scanf("%s%s",s,t);
    memset(cnt,0,sizeof cnt);
    int lens=strlen(s),lent=strlen(t);
    manacher(s);
    for(int i=0;i<lens;i++) cnt[i]+=cnt[i-1];
    reverse(s,s+lens);
    getExtend(s,t);
    long long ans=0;
    for(int i=1;i<lens;i++)
        ans+=1ll*cnt[lens-i]*extend[i];
    printf("%lld\n",ans);
    return 0;
}