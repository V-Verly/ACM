#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<26;i++)
    {
        int k=1;
        while(k*(k+1)/2<=n) k++;
        n-=k*(k-1)/2;
        while(k--) printf("%c",i+'a');
    }
    return 0;
}
