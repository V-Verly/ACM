#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char fb[1005][1000];

void print(int index)
{
    for(int i=strlen(fb[index])-1;i>=0;i--)
        printf("%c",fb[index][i]);
    printf("\n");
}

void add(char *a,char *b,int index)
{
    int m=strlen(a),n=strlen(b);
    char p[1000],q[1000];
    memcpy(p,a,sizeof(p));
    memcpy(q,b,sizeof(q));
    char c[1000];
    memset(c,0,sizeof(c));
    int i=0,s=0,j=0,k=0;
    while(i<m||i<n||s!=0)
    {
        if(j<m) s+=p[j++]-'0';
        if(k<n) s+=q[k++]-'0';
        c[i++]+=s%10+'0';
        s/=10;
    }
    memcpy(fb[index],c,sizeof(c));
}

int main()
{
    int n;
    fb[0][0]='0';
    fb[1][0]='0';
    fb[2][0]='1';
    for(int i=3;i<=1000;i++)
    {
        add(fb[i-1],fb[i-2],i);
        add(fb[i],fb[i-2],i);
    }
    while(scanf("%d",&n)!=EOF)
    {
        print(n);
    }
    return 0;
}
