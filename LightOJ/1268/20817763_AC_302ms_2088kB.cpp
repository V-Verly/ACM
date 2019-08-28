#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

char ch[maxn], s[maxn];
int nex[maxn];

int cur;
struct Matrix
{
    unsigned a[55][55];
    Matrix() { memset(a, 0, sizeof a); }
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix res;
    for(int i = 0; i < cur; i++)
        for(int j = 0; j < cur; j++)
            for(int k = 0; k < cur; k++)
                res.a[i][j] +=a.a[i][k] * b.a[k][j];
    return res;
}

Matrix pow(Matrix a, int n)
{
    Matrix ans, base = a;
    for(int i = 0; i < cur; i++) ans.a[i][i] = 1;
    while(n)
    {
        if(n & 1) ans = mul(ans, base);
        base = mul(base, base);
        n >>= 1;
    }
    return ans;
}

void getNext()
{
    int n = strlen(s), i = 0, j = -1;
    nex[i] = j;
    while(i < n)
    {
        if(j == -1 || s[i] == s[j]) nex[++ i] = ++ j;
        else j = nex[j];
    }
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for(int _ = 1; _ <= t; _ ++)
    {
        scanf("%d%s%s", &n, ch, s);
        getNext();
        Matrix ans;
        cur = strlen(s);
        for(int i = 0; s[i]; i ++)
        {
            for(int j = 0; ch[j]; j ++)
            {
                int pos = i;
                while(pos != -1 && s[pos] != ch[j]) pos = nex[pos];
                pos ++;
                ans.a[i][pos] ++;
            }
        }
        ans = pow(ans, n);
        unsigned res = 0;
        for(int i = 0; i < cur; i ++) res += ans.a[0][i];
        printf("Case %d: %u\n", _, res);
    }
    return 0;
}
