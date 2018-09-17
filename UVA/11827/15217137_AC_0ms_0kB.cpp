#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int t,a[105];
    cin>>t;
    string line;
    stringstream ss;
    getline(cin,line);
    while(t--)
    {
        getline(cin,line);
        ss.clear();
        ss<<line;
        int n=0;
        while(ss>>a[n++]);
        n--;
        int g=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                g=max(g,__gcd(a[i],a[j]));
        }
        cout<<g<<endl;
    }
    return 0;
}
