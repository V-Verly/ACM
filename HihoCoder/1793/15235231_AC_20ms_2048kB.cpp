#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
char s[maxn];

int main()
{
    int n;
    while(scanf("%s",s)!=EOF)
    {
        n=strlen(s);
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') a++;
            else b++;
        }
        printf("%d\n",min(a,b));
    }
    return 0;
}
