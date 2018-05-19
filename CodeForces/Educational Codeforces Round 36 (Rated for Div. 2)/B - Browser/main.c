#include<stdio.h>

int main()
{
    int n,pos,l,r,front,rear,sum,min;
    scanf("%d%d%d%d",&n,&pos,&l,&r);
    front=1,rear=n;
    if(front!=l&&rear!=r) {
        if(pos>=l&&pos<=r){
        if(pos-l>r-pos) min=r-pos;
        else min=pos-l;
        sum=min+r-l+2;
        }
        else if(pos<l)
        sum=r-pos+2;
        else if(pos>r)
        sum=pos-l+2;
        }
    else if(front!=l&&rear==r) {
        if(pos>=l)
        sum=pos-l+1;
        else
        sum=l-pos+1;
        }
    else if(front==l&&rear!=r) {
        if(pos<=r)
        sum=r-pos+1;
        else
        sum=pos-r+1;
        }
    else if(front==l&&rear==r) sum=0;
    printf("%d\n",sum);
    return 0;
}
