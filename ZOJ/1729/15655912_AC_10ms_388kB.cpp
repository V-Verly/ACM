#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
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
        scanf("%d",&len);
        scanf("%s",a);
        int i=0,j=1,k=0;
        printf("%d\n",MinimunRepresentation());
    }
    return 0;
}
