#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

char s[maxn], s1[maxn];
int cnt[maxn][26], l[26], r[26], used[26];
vector<int> g[26];

int main()
{
    int n, m;
    while(scanf("%s%d", s, &m) != EOF)
    {
        n = strlen(s);
        for(int i = 0; i < 26; i ++) scanf("%d%d", &l[i], &r[i]);
        memset(used, 0, sizeof used);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < 26; i ++) g[i].clear();
        for(int i = 0; i < n; i ++) g[s[i] - 'a'].push_back(i);
        for(int i = n - 1; i >= 0; i --)
            for(int j = 0; j < 26; j ++)
                cnt[i][j] = cnt[i + 1][j] + (s[i] == 'a' + j);
        vector<int>::iterator head[26];
        for(int i = 0; i < 26; i ++) head[i] = g[i].begin();

        int last = -1, now = 0;
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < 26; j ++)
            {
                if(used[j] == r[j]) continue;
                while(head[j] != g[j].end() && (*head[j]) <= last) head[j] ++;
                if(head[j] == g[j].end()) continue;

                bool flag = true;
                int sum = 0, pos = *head[j];
                used[j] ++;
                for(int k = 0; k < 26; k ++)
                {
                    if(cnt[pos + 1][k] + used[k] < l[k]) flag = false;
                    sum += max(l[k] - used[k], 0);
                }
                if(sum > m - i - 1) flag = false;
                sum = 0;
                for(int k = 0; k < 26; k ++)
                    sum += min(cnt[pos + 1][k], r[k] - used[k]);
                if(sum < m - i - 1) flag = false;

                if(!flag) used[j] --;
                else
                {
                    s1[i] = 'a' + j;
                    last = pos;
                    now ++;
                    break;
                }
            }
            if(now == i) break;
        }
        s1[m] = 0;
        if(now < m) printf("-1\n");
        else printf("%s\n", s1);
    }
    return 0;
}
