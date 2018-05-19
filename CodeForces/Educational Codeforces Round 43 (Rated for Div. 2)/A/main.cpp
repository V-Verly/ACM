#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,ans=0;
    char s[105];
    scanf("%d",&n);
    scanf("%s",s);
    if(n==1&&s[0]=='0')
    {
        printf("0\n");
    }
    else
    {
        for(int i=0;i<n;i++)
            if(s[i]=='0') ans++;
        printf("1");
        for(int i=0;i<ans;i++)
            printf("0");
        printf("\n");
    }


    return 0;
}
