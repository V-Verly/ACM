#include<cstdio>
#include<queue>
#include<map>
using namespace std;
const int maxt=1000+10;
int main(){
    int t,x,i,n,count=0;
    char cmd[20];
    map<int,int> team;
    while(scanf("%d",&n)!=EOF&&n){
        printf("Scenario #%d\n",++count);
        for(i=0;i<n;i++){
            scanf("%d",&t);
            while(t--) {scanf("%d",&x);team[x]=i;}
        }
        queue<int> q,q2[maxt];
        while(1){
            scanf("%s",cmd);
            if(cmd[0]=='S') break;
            else if(cmd[0]=='E'){
                scanf("%d",&x);
                t=team[x];
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
            else{
                t=q.front();
                printf("%d\n",q2[t].front());
                q2[t].pop();
                if(q2[t].empty()) q.pop();
            }
        }
        printf("\n");
    }
}
