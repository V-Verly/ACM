#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int k,m,n;
    scanf("%d",&k);
    if(k>36) printf("-1\n");
    else{
        m=k/2;
        n=k%2;
        while(m--)
            printf("8");
        while(n--)
            printf("9");
        printf("\n");
    }
    return 0;
}
