#include <iostream>
#include <cstring>

using namespace std;

const int maxn=1e5+10;
char s[maxn];

struct Node
{
    int k;
    Node *nex[26];
    Node()
    {
        int i;
        for(int i=0;i<26;i++)
            nex[i]=nullptr;
        k=0;
    }
}root;

void insert_ch(char *ch)
{
    int i;
    Node *p=&root;

    for(int i=0;ch[i];i++)
    {
        if(p->nex[ch[i]-'a']==nullptr)
            p->nex[ch[i]-'a']=new Node;
        p=p->nex[ch[i]-'a'];
        p->k++;
    }
}

int find_ch(char *ch)
{
    int i;
    Node *p=&root;
    for(int i=0;ch[i];i++)
    {
        if(p->nex[ch[i]-'a']==nullptr)
            return 0;
        p=p->nex[ch[i]-'a'];
    }
    return p->k;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        insert_ch(s);
    }
    cin>>t;
    while(t--)
    {
        cin>>s;
        cout<<find_ch(s)<<endl;
    }
    return 0;
}
