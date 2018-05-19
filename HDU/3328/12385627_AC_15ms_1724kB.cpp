#include<cstdio>
#include<stack>
using namespace std;
const int maxn=105;
int main(void){
    int n,i,s[maxn],t,kase=1;
    char a[maxn],change[maxn];
    while(scanf("%d",&n)!=EOF&&n){
        printf("Pile %d\n",kase++);
        stack<int> card[n];
        stack<char> face[n];
        scanf("%s",a);
        scanf("%s",change);
        for(i=0;i<n;i++){
            card[i].push(i+1);
            face[i].push(a[i]);
        }
        int left=0,right=n-1;
        for(i=0;i<n-1;i++){
            if(change[i]=='R'){
                while(!card[right].empty()){
                    card[right-1].push(card[right].top());
                    card[right].pop();
                }
                while(!face[right].empty()){
                    if(face[right].top()=='U')
                    face[right-1].push('D');
                    else
                    face[right-1].push('U');
                    face[right].pop();
                }
                right--;
            }
            else{
                while(!card[left].empty()){
                    card[left+1].push(card[left].top());
                    card[left].pop();
                }
                while(!face[left].empty()){
                    if(face[left].top()=='U')
                    face[left+1].push('D');
                    else
                    face[left+1].push('U');
                    face[left].pop();
                }
                left++;
            }
        }
        for(i=0;i<n;i++){
            s[i]=card[left].top();
            a[i]=face[left].top();
            card[left].pop();
            face[left].pop();
        }
        scanf("%d",&t);
        while(t--){
            scanf("%d",&i);
            i--;
            printf("Card %d is a face %s %d.\n",i+1,'U'==a[i]?"up":"down",s[i]);
        }
    }
}