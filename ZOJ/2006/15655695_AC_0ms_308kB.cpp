#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2e4+10;
char a[maxn];
int len;

int MinimunRepresentation()
{
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len)
    {
        int t=a[(i+k)%len]-a[(j+k)%len];
        if(t==0) k++;
        else
        {
            if(t>0) i+=k+1;
            else j+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    return i<j?i:j;

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        len=strlen(a);
        int i=0,j=1,k=0;
        printf("%d\n",MinimunRepresentation()+1);
    }
    return 0;
}
