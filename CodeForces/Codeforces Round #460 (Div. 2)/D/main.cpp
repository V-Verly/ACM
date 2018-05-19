#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int num = 10;
vector<int> visited(num);
//图的邻接表存储结构的类型声明------Begin------
//边结点结构类型
struct ANode {
    int adjvex;     //边的终点位置
    ANode* nextarc; //指向表头结点下一条邻接的边
    int info;       //该边的相关信息，对于带权图可存放权值
};
//邻接表头节点类型
struct VNode {
    char info; //结点信息
    ANode* firstarc; //指向第一条邻接的边
};
//图的邻接表类型
struct AGraph {
    vector<VNode*> adjlist; //所有表头组成的数组
    int n,e; //结点个数，边条数
};
//邻接表存储结构类型声明------END------

//------生成图的邻接表算法------
void createAdj(AGraph* &G, vector<vector<int> > A, int n) {
    //由数组A生成邻接表
    ANode *p;
    G = new AGraph();
    G->n = n;
    G->e = 0;
    for(int i=0;i<n;i++){
        VNode *vnode = new VNode();
        vnode->firstarc = NULL;
        G->adjlist.push_back(vnode);
    }
    for(int j=0;j<n;j++) {
        for(int k=n-1;k>=0;k--) {
            if(A[j][k]!=0) {
                p = new ANode();
                p->adjvex = k;
                p->nextarc = G->adjlist[j]->firstarc;
                G->adjlist[j]->firstarc = p;
                G->e++;
            }
        }
    }
}

//------输出图的邻接表算法------
void dispAdj(AGraph *G) {
    ANode* p;
    for(int i=0;i<G->n;i++) {
        cout<<i<<"->";
        p = G->adjlist[i]->firstarc;
        while(p) {
            cout<<p->adjvex<<"->";
            p = p->nextarc;
        }
        cout<<"NULL"<<endl;
    }
}

//深度优先遍历
void DFS(AGraph *G, int v) {
    ANode *p;
    visited[v] = 1;
    cout<<v<<" ";
    p = G->adjlist[v]->firstarc;
    while(p) {
        if(!visited[p->adjvex])
            DFS(G,p->adjvex);
        p = p->nextarc;
    }
}

//广度优先遍历
void BFS(AGraph* G,int v) {
    ANode *p;
    queue<int> qu;
    vector<int> flag(G->n);
    int w;
    cout<<v<<" ";
    flag[v]=1;
    qu.push(v);
    while(!qu.empty()) {
        w = qu.front();
        qu.pop();
        p = G->adjlist[w]->firstarc;
        while(p) {
            if(!flag[p->adjvex]) {
                cout<<p->adjvex<<" ";
                flag[p->adjvex] = 1;
                qu.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
    cout<<endl;
}

//测试用例
int main() {
    int a[] = {0,1,0,1,0};
    int b[] = {0,0,1,1,0};
    int c[] = {0,0,0,1,1};
    int d[] = {0,0,0,0,0};
    int e[] = {1,0,0,1,0};
    vector<vector<int> > graph;
    vector<int> A(a,a+5);
    vector<int> B(b,b+5);
    vector<int> C(c,c+5);
    vector<int> D(d,d+5);
    vector<int> E(e,e+5);

    graph.push_back(A);
    graph.push_back(B);
    graph.push_back(C);
    graph.push_back(D);
    graph.push_back(E);

    AGraph* G;
    int n=5;
    cout<<"构造图的邻接表："<<endl;
    createAdj(G,graph,n);
    cout<<"输出图的邻接表:"<<endl;
    dispAdj(G);

    DFS(G,0);
    cout<<endl;
    BFS(G,0);
    return 0;
}
