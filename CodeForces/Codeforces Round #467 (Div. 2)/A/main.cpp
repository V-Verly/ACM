#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    int n,i,s,a[605];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    s=1;
    for(i=1;i<n&&a[i]>0;i++)
        if(a[i]!=a[i-1]) s++;
    printf("%d\n",s);
    return 0;
}
