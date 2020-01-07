#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
int nex[maxn], extend[maxn];

//预处理计算Next数组
void getNext(char *str)
{
    int i = 0, j, po, len = strlen(str);
    nex[0] = len;     //初始化nex[0]
    while (str[i] == str[i + 1] && i + 1 < len) i++;   //计算nex[1]
    nex[1] = i;
    po = 1;   //初始化po的位置
    for (int i = 2; i < len; i++)
    {
        if (nex[i - po] + i < nex[po] + po)  //第一种情况，可以直接得到nex[i]的值
            nex[i] = nex[i - po];
        else    //第二种情况，要继续匹配才能得到nex[i]的值
        {
            j = nex[po] + po - i;
            if (j < 0) j = 0;    //如果i>po+nex[po],则要从头开始匹配
            while (i + j < len && str[j] == str[j + i]) j++;
            nex[i] = j;
            po = i;   //更新po的位置
        }
    }
}

char s[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        getNext(s);
        int n = strlen(s);
        long long ans = 0;
        for(int i = 1; i < n; i ++)
        {
            int x = nex[i];
            if(i + nex[i] < n) x ++;
            ans += x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
