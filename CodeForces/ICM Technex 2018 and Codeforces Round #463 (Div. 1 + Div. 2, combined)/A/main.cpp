#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char a[5005];
    int i,n;
    scanf("%s",a);
    n=strlen(a);
        for(i=0;i<=n-1;i++)
            a[2*n-i-1]=a[i];
        a[2*n]=0;
    printf("%s",a);
    return 0;
}
