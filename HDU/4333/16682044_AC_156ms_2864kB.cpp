#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;
char a[2*maxn],b[maxn];

int nex[maxn],extend[maxn];

void getNext(char *str)
{
    int i=0,j,po,len=strlen(str);
    nex[0]=len;
    while(str[i]==str[i+1]&&i+1<len) i++;
    nex[1]=i;
    po=1;
    for(int i=2;i<len;i++)
    {
        if(nex[i-po]+i<nex[po]+po)
            nex[i]=nex[i-po];
        else
        {
            j=nex[po]+po-i;
            if(j<0) j=0;
            while(i+j<len&&str[j]==str[j+i]) j++;
            nex[i]=j;
            po=i;
        }
    }
}

void EXKMP(char *s1,char *s2)
{
    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
    getNext(s2);
    while(s1[i]==s2[i]&&i<l2&&i<len) i++;
    extend[0]=i;
    po=0;
    for(int i=1;i<len;i++)
    {
        if(nex[i-po]+i<extend[po]+po)
            extend[i]=nex[i-po];
        else
        {
            j=extend[po]+po-i;
            if(j<0) j=0;
            while(i+j<len&&j<l2&&s1[j+i]==s2[j]) j++;
            extend[i]=j;
            po=i;
        }
    }
}

void KMP(char *s)
{
    int n=strlen(s),i=0,j=-1;
	nex[0]=-1;
	while(i<n)
	{
		if(j==-1||s[i]==s[j]) nex[++i]=++j;
		else j=nex[j];
	}
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%s",a);
        int n=strlen(a);
        KMP(a);
        int mod=n%(n-nex[n])==0?n/(n-nex[n]):1;
        for(int i=0;i<n;i++)
        {
            a[i+n]=a[i];
            b[i]=a[i];
        }
        b[n]=a[2*n]=0;
        int len=n,x=0,y=0,z=0;
        n*=2;
        EXKMP(a,b);
        for(int i=0;i<len;i++)
        {
            if(extend[i]>=len) y++;
            else if(a[extend[i]]<a[i+extend[i]]) z++;
            else x++;
        }
        printf("Case %d: %d %d %d\n",_,x/mod,y/mod,z/mod);
    }
    return 0;
}
