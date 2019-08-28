#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int nums[maxn], sorted[maxn], root[maxn];
int cnt;

struct node
{
    int sum, ls, rs;
}tree[maxn << 5];

int CreateNode(int sum, int ls, int rs)
{
    int index = ++cnt;
    tree[index].sum = sum;
    tree[index].ls = ls;
    tree[index].rs = rs;
    return index;
}

void insert(int &rt, int preRt, int pos, int l, int r)
{
    rt = CreateNode(tree[preRt].sum + 1, tree[preRt].ls, tree[preRt].rs);
    if(l == r) return;
    int mid = l + r >> 1;
    if(pos <= mid) insert(tree[rt].ls, tree[preRt].ls, pos, l, mid);
    else insert(tree[rt].rs, tree[preRt].rs, pos, mid + 1, r);
}

int Query(int s, int e, int l, int r, int k)
{
    if(l == r) return l;
    int mid = l + r >> 1;
    int sum = tree[tree[e].ls].sum - tree[tree[s].ls].sum;
    if(k <= sum) return Query(tree[s].ls, tree[e].ls, l, mid, k);
    else return Query(tree[s].rs, tree[e].rs, mid + 1, r, k - sum);
}

int main()
{
    int n, m, num, pos, T;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        cnt = 0; root[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &nums[i]);
            sorted[i] = nums[i];
        }
        sort(sorted + 1, sorted + n + 1);
        num = unique(sorted + 1, sorted + n + 1) - (sorted + 1);
        for(int i = 1; i <= n; i++)
        {
            pos = lower_bound(sorted + 1, sorted + num + 1, nums[i]) - sorted;
            insert(root[i], root[i - 1], pos, 1, num);
        }
        int l, r, k;
        while(m--)
        {
            scanf("%d%d%d", &l, &r, &k);
            pos = Query(root[l - 1], root[r], 1, num, k);
            printf("%d\n", sorted[pos]);
        }
    }
    return 0;
}
