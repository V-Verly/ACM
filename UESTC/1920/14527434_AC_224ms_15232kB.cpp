#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int maxn=1e5+10;

struct Game
{
    int price;
    string name;
    bool operator <(const Game &a) const
    {
        if(price==a.price) return name<a.name;
        return price<a.price;
    }
}game[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int n,op,x,y,res=0;
    string s;
    cin>>n;
    set<Game> lis;
    map <string,int> mp;
    while(n--)
    {
        cin>>op;
        if(op==1)
        {
            Game g;
            cin>>g.name>>g.price;
            if(mp.count(g.name)==0)
            {
                lis.insert(g);
                mp[g.name]=res;
                game[res++]=g;
            }
        }
        else if(op==2)
        {
            cin>>s;
            if(mp.count(s)==1)
            {
                lis.erase(game[mp[s]]);
                mp.erase(s);
            }
        }
        else if(op==3)
        {
            cin>>s>>y;
            if(mp.count(s)==1)
            {
                lis.erase(game[mp[s]]);
                game[mp[s]].price=y;
                lis.insert(game[mp[s]]);
            }
        }
        else if(op==4)
        {
            cin>>x;
            if(!lis.empty())
            {
                set<Game>::iterator it;
                if(x==1)
                    it=lis.begin();
                else if(x==2)
                {
                    it=lis.end();
                    it--;
                }
                cout<<(*it).name<<endl;

            }
        }
    }

    return 0;
}
