#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2*1e5+10;
char s[maxn];

int main()
{
    int n,a,b,i=0,sum=0,tmp=0;
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s);
    if(a<b) swap(a,b);
    for(i=0;i<n;i++)
    {
        if(s[i]=='*')
        {
            tmp=0;
            if(a<b) swap(a,b);
        }
        else
        {
            tmp++;
            if(tmp%2&&a) {a--;sum++;}
            else if(tmp%2==0&&b) {b--;sum++;}
        }
    }
    printf("%d\n",sum);
    return 0;
}
