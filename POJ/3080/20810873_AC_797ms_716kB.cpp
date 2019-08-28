#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int nex[65];

void getNext(string s)
{
    int n = s.size(), i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || s[i] == s[j]) nex[++ i] = ++ j;
        else j = nex[j];
    }
}

bool KMP(string a, string b)
{
    int i = 0, j = 0, n = a.size(), m = b.size();
    while(i < n && j < m)
    {
        if(j == -1 || a[i] == b[j]) i ++, j ++;
        else j = nex[j];
        if(j == m) return true;
    }
    return false;
}

int main()
{
    int t, n;
    string s[15];
    cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> s[i];
        string ans = "";
        for(int i = 1; i <= s[0].size(); i ++)
        {
            for(int j = 0; j <= s[0].size() - i; j ++)
            {
                string op = s[0].substr(j, i);
                getNext(op);
                bool flag = true;
                for(int k = 1; k < n; k ++)
                    if(!KMP(s[k], op)) flag = false;
                if(flag)
                {
                    if(ans.size() < op.size()) ans = op;
                    else if(ans.size() == op.size()) ans = min(ans, op);
                }
            }
        }
        if(ans.size() < 3) cout << "no significant commonalities" << endl;
        else cout << ans << endl;
    }
    return 0;
}
