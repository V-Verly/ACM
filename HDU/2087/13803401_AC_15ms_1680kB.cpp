#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int nex[1005];

void getNext(char *m)
{
    int len=strlen(m),i=0,j=-1;
    nex[0]=-1;
    while(i<len)
    {
        if(j==-1||m[i]==m[j])
            nex[++i]=++j;
        else
            j=nex[j];
    }
}

int KMP(char *a,char *b)
{
    int n=strlen(a),m=strlen(b),ans=0;
    int i=0,j=0;
    getNext(b);
    while(i<n)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;
            j++;
        }
        else j=nex[j];
        if(j==m)
        {
            j=0;
            ans++;
        }

    }
    return ans;
}

int main()
{
    char a[1005],b[1005];
    while(scanf("%s",a)!=EOF)
    {
        if(a[0]=='#') break;
        scanf("%s",b);
        printf("%d\n",KMP(a,b));
    }
    return 0;
}
