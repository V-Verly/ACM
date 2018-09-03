#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<int,int> mp;
set<pair<int,int> > s;

int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(!mp.count(a)) mp[a]=1;
        else mp[a]++;
    }
    map<int,int>::iterator iter;
    for(iter=mp.begin();iter!=mp.end();iter++)
        s.insert(make_pair(iter->second,iter->first));
    if((--s.end())->first*2-1>n) return 0*printf("-1\n");
    int last=-1;
    for(int i=0;i<n;i++)
    {
        int x;
        if(((--s.end())->first*2-1)==(n-i)) x=(--s.end())->second;
        else
        {
            map<int,int>::iterator it=mp.begin();
            if(it->first==last) it++;
            x=it->first;
        }
        s.erase(make_pair(mp[x],x));
        if(--mp[x]>0) s.insert(make_pair(mp[x],x));
        else mp.erase(x);
        last=x;
        if(i) printf(" ");
        printf("%d",x);
    }
    printf("\n");
    return 0;
}
