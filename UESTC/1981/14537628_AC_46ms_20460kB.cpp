#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    set<string> st;
    string leaf;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>leaf;
        st.insert(leaf);
    }
    cout<<st.size();
    return 0;
}
