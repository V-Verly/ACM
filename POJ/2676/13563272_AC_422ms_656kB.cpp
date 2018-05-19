#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[15][15],sudoku[15][15];
bool column[10][10],row[10][10],box[10][10];
bool flag;

void DFS(int x,int y)
{
    if(x==9)
    {
        flag=true;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                printf("%d",sudoku[i][j]);
            printf("\n");
        }
        return;
    }
    if(flag) return;
    if(!a[x][y])
    {
        int b=x/3*3+y/3;
        for(int i=1;i<=9;i++)
        {
            if(!column[x][i]&&!row[y][i]&&!box[b][i])
            {
                column[x][i]=row[y][i]=box[b][i]=true;
                sudoku[x][y]=i;

                if(y==8)
                    DFS(x+1,0);
                else
                    DFS(x,y+1);
                sudoku[x][y]=0;
                column[x][i]=row[y][i]=box[b][i]=false;
            }
        }
    }
    else
    {
        if(y==8)
            DFS(x+1,0);
        else
            DFS(x,y+1);
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(column,false,sizeof(column));
        memset(row,false,sizeof(row));
        memset(box,false,sizeof(box));
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                scanf("%1d",&a[i][j]);
                int b=i/3*3+j/3;
                if(a[i][j])
                {
                    column[i][a[i][j]]=true;
                    row[j][a[i][j]]=true;
                    box[b][a[i][j]]=true;
                    sudoku[i][j]=a[i][j];
                }
            }
        flag=false;
        DFS(0,0);

    }
    return 0;
}
