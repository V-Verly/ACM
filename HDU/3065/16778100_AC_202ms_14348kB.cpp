#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2e6+10;
char s[maxn],a[1010][55];
int cnt,ans[1010];

struct acnode{
    int sum;
    int key;
    acnode* next[27];
    acnode* fail;
    acnode(){
        for(int i =0;i<27;i++)
            next[i]=NULL;
        fail= NULL;
        sum=0;
    }
};
acnode *root;
acnode* newnode(){
    acnode *p = new acnode;
    for(int i =0;i<27;i++)
        p->next[i]=NULL;
    p->fail = NULL;
    p->sum=0;
    return p;
}
//插入函数
void Insert(char *s)
{
    acnode *p = root;
    for(int i = 0; s[i]; i++)
    {
        int x = s[i] - 'A';
        if(p->next[x]==NULL)
        {
            acnode *nn=newnode();
            for(int j=0;j<26;j++)
                nn->next[j] = NULL;
            nn->sum = 0;
            nn->fail = NULL;
            p->next[x]=nn;
        }
        p = p->next[x];
    }
    p->sum++;
    p->key=cnt;
}
//获取fail指针，在插入结束之后使用
void getfail(){
    queue<acnode*> q;
    for(int i = 0 ; i < 26 ; i ++ )
    {
        if(root->next[i]!=NULL){
            root->next[i]->fail = root;
            q.push(root->next[i]);
        }
    }
    while(!q.empty()){
        acnode* tem = q.front();
        q.pop();
        for(int i = 0;i<27;i++){
            if(tem->next[i]!=NULL)
            {
                acnode *p;
                if(tem == root){
                    tem->next[i]->fail = root;
                }
                else
                {
                    p = tem->fail;
                    while(p!=NULL){
                        if(p->next[i]!=NULL){
                            tem->next[i]->fail = p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)
                        tem->next[i]->fail = root;
                }
                q.push(tem->next[i]);
            }
        }
    }
}
//匹配函数
void ac_automation(char *ch)
{
    acnode *p = root;
    int len = strlen(ch);
    for(int i = 0; i < len; i++)
    {
        int x = ch[i] - 'A';
        if(x<0||x>=26) x=26;
        while(p->next[x]==NULL && p != root)//没匹配到，那么就找fail指针。
            p = p->fail;
        p = p->next[x];
        if(!p) p = root;
        acnode *temp = p;
        while(temp != root)
        {
           if(temp->sum > 0)
            /*
            在这里已经匹配成功了，执行想执行的操作即可，怎么改看题目需求+
            */
           {
               ans[temp->key]+=temp->sum;
           }
           else break;
           temp = temp->fail;
        }
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        root=new acnode;
        cnt=0;
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            Insert(a[i]);
            cnt++;
        }
        getfail();
        scanf("%s",s);
        ac_automation(s);
        for(int i=0;i<n;i++)
            if(ans[i]) printf("%s: %d\n",a[i],ans[i]);
    }
    return 0;
}