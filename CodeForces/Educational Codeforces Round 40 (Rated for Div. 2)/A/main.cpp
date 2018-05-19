#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,i=0,t;
    char a[105];
    scanf("%d",&n);
    scanf("%s",a);
    t=n;
    while(i<n-1)
    {
        if(a[i]=='R'&&a[i+1]=='U'||a[i]=='U'&&a[i+1]=='R')
        {
            t--;
            i+=2;
        }
        else i++;
    }
    printf("%d\n",t);
    return 0;
}
