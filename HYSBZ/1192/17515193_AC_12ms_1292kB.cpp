#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int m;
    scanf("%d",&m);
    set<int> st;
    int cnt=0;
    for(int i=1;i<m;i<<=1)
    {
        cnt++;
        m-=i;
        st.insert(i);
    }
    if(st.count(m)) m--;
    if(m) cnt++;
    printf("%d\n",cnt);
    return 0;
}
