#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int preorder[1005],inorder[1005];
char a[1005];

typedef struct Node{
int val;
Node *lchild;
Node *rchild;
} *BinaryTree;

BinaryTree Rebuild(int startPre,int endPre,int startIn,int endIn)
{
    if(startPre>endPre||startIn>endIn) return NULL;
    BinaryTree T=new Node;
    T->val=preorder[startPre];
    for(int i=startIn;i<=endIn;i++)
    {
        if(inorder[i]==preorder[startPre])
        {
            T->lchild=Rebuild(startPre+1,startPre+i-startIn,startIn,i-1);
            T->rchild=Rebuild(i-startIn+startPre+1,endPre,i+1,endIn);
            break;
        }
    }
    return T;
}

void SearchPath(BinaryTree p,vector <char> &path,int x)
{
    if(p==NULL) return;
    if(p->val==x)
    {
        vector <char> ::const_iterator iter=path.begin();
        if(iter!=path.end())
        {
            for(; iter!=path.end()-1;iter++)
            cout<<*iter;
            cout<<*iter;
        }
        cout<<endl;
        return;
    }
    if(p->lchild!=NULL)
    {
        path.push_back('E');
        SearchPath(p->lchild,path,x);
        path.pop_back();
    }
    if(p->rchild!=NULL)
    {
        path.push_back('W');
        SearchPath(p->rchild,path,x);
        path.pop_back();
    }
}

int main()
{
    int t,i,n,q,x;

    for(i=0;i<1005;i++) inorder[i]=i+1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&preorder[i]);
        BinaryTree T=Rebuild(0,n-1,0,n-1);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&x);
            vector <char> path;
            SearchPath(T,path,x);
        }
    }
    return 0;
}
