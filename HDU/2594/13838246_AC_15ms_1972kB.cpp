#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5e4+10;
char a[maxn],b[maxn];
int lena,lenb,nex[maxn];

void getNext()
{
    int i=0,j=-1;
    nex[0]=-1;
    while(i<lenb)
    {
        if(j==-1||a[i]==a[j])
            nex[++i]=++j;
        else
            j=nex[j];
    }
}

void KMP()
{
    int i=0,j=0,ans=0;
    getNext();
    while(i<lenb)
    {
        if(j==-1||a[j]==b[i])
        {
            i++;
            j++;
        }
        else j=nex[j];
    }
    if(!j)
        printf("0\n");
    else
    {
        for(int k=0;k<j;k++)
            printf("%c",a[k]);
        printf(" %d\n",j);
    }
}

int main()
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        lena=strlen(a);
        lenb=strlen(b);
        KMP();
    }
    return 0;
}
