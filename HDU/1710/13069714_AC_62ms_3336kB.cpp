#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int preorder[1005],inorder[1005],ans;

typedef struct Node{
int val;
Node* lchild;
Node* rchild;
}*BinaryTree,node;

BinaryTree Rebuild(int startPre,int endPre,int startIn,int endIn)
{
    if(startPre>endPre||startIn>endIn)
        return NULL;
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

void postorder(BinaryTree &T)
{
    if(T)
    {
        if(T->lchild) postorder(T->lchild);
        if(T->rchild) postorder(T->rchild);
        if(ans++) printf(" ");
        printf("%d",T->val);
    }
}

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&preorder[i]);
        for(i=0;i<n;i++)
            scanf("%d",&inorder[i]);
        BinaryTree T=Rebuild(0,n-1,0,n-1);
        ans=0;
        postorder(T);
        printf("\n");
    }
    return 0;
}
