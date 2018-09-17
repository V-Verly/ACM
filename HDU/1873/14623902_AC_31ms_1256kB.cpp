#include<cstdio>
#include<queue>
using namespace std;
struct Patient{
    int priority,num;
        bool operator < (const Patient&t)const{  
        if(priority==t.priority)
        return num>t.num;
        else
        return priority<t.priority;
    }  
};

int main()
{
    priority_queue <Patient> a,b,c; 
    int t,n,k;
    Patient patient[2005];
    char s[5];
    while(~scanf("%d",&t))
    {
        k=1;
        while(t--)
        {
            scanf("%s%d",s,&n);
            if(s[0]=='I')
            {
                scanf("%d",&patient[k].priority);
                patient[k].num=k;
                if(n==1) a.push(patient[k]);
                else if(n==2) b.push(patient[k]);
                else if(n==3) c.push(patient[k]);
                k++;
            }
            else
            {
                if(n==1){
                    if(a.empty()) printf("EMPTY\n");
                    else {printf("%d\n",a.top().num);a.pop();}
                }
                else if(n==2){
                    if(b.empty()) printf("EMPTY\n");
                    else {printf("%d\n",b.top().num);b.pop();}
                }
                else if(n==3){
                    if(c.empty()) printf("EMPTY\n");
                    else {printf("%d\n",c.top().num);c.pop();}
                }
            }
        }
        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();
        while(!c.empty()) c.pop();
    }
}