#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    char a[105];
    scanf("%d",&n);
    scanf("%s",a);
    int ans=0,tmp=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='x')
            tmp++;
        else
        {
            tmp=0;
        }
        if(tmp>=3)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
