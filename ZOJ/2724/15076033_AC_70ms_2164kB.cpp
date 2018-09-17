#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct command
{
    char mes[20];
    int num,pir,time;
}com[60010];

bool cmp(const int &a,const int &b)
{
    if(com[a].pir==com[b].pir) return com[a].time>=com[b].time;
    return com[a].pir>com[b].pir;
}

int main()
{
    char op[10],s[20];
    int heap[60010],cur=0,time=0;
    while(scanf("%s",op)!=EOF)
    {
        if(op[0]=='G')
        {
            if(!cur) printf("EMPTY QUEUE!\n");
            else
            {
                printf("%s %d\n",com[heap[1]].mes,com[heap[1]].num);
                heap[1]=heap[cur--];
                int idx=1;
                while(2*idx<=cur)
                {
                    int pIdx=2*idx;
                    if(pIdx<cur&&cmp(heap[pIdx],heap[pIdx+1]))
                        pIdx++;
                    if(cmp(heap[idx],heap[pIdx]))
                    {
                        swap(heap[pIdx],heap[idx]);
                        idx=pIdx;
                    }
                    else break;
                }
            }
        }
        else
        {
            scanf("%s%d%d",com[time].mes,&com[time].num,&com[time].pir);
            com[time].time=time;
            heap[++cur]=time++;
            int idx=cur;
            while(idx>1)
            {
                int pIdx=idx/2;
                if(cmp(heap[pIdx],heap[idx]))
                {
                    swap(heap[idx],heap[pIdx]);
                    idx=pIdx;
                }
                else break;
            }
        }
    }
    return 0;
}
