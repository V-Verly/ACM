#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int maxn = 2000 + 10;

int n, m;
int low[maxn], dfn[maxn], color[maxn], cnt, scc_cnt;
bool instack[maxn];

vector<int> g[maxn];
stack<int> st;

void Tarjan(int u)
{
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    instack[u] = true;
    for(int i = 0; i < g[u].size(); i ++)
    {
        int v = g[u][i];
        if(!dfn[v]) Tarjan(v), low[u] = min(low[u], low[v]);
        else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        ++scc_cnt;
        do
        {
            color[u] = scc_cnt;
            u = st.top(); st.pop();
            instack[u] = false;
        }while(low[u] != dfn[u]);
    }
}

inline void AND(int a, int b, int c)
{
    if(c == 1)
    {
        g[a].push_back(a + n);
        g[b].push_back(b + n);
    }
    else
    {
        g[a + n].push_back(b);
        g[b + n].push_back(a);
    }
}

inline void OR(int a, int b, int c)
{
    if(c == 0)
    {
        g[a + n].push_back(a);
        g[b + n].push_back(b);
    }
    else
    {
        g[a].push_back(b + n);
        g[b].push_back(a + n);
    }
}

inline void XOR(int a, int b, int c)
{
    if(c == 0)
    {
        g[a].push_back(b);
        g[a + n].push_back(b + n);
        g[b].push_back(a);
        g[b + n].push_back(a + n);
    }
    else
    {
        g[a].push_back(b + n);
        g[b].push_back(a + n);
        g[a + n].push_back(b);
        g[b + n].push_back(a);
    }
}

int main()
{
    int a, b, c;
    char s[5];
    scanf("%d%d", &n, &m);
    while(m --)
    {
        scanf("%d%d%d%s", &a, &b, &c, s);
        if(s[0] == 'A') AND(a, b, c);
        else if(s[0] == 'O') OR(a, b, c);
        else if(s[0] == 'X') XOR(a, b, c);
    }
    cnt = scc_cnt = 0;
    for(int i = 0; i <= ((n - 1) << 1); i ++) if(!dfn[i]) Tarjan(i);
    for(int i = 0; i < n; i ++) if(color[i] == color[i + n]) return 0 * puts("NO");
    puts("YES");
    return 0;
}
