#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=100+10;
const int mod=100000;

class Matrix
{
public:
    int row,column;
    long long data[maxn][maxn];
    Matrix mul(Matrix a,Matrix b)
    {
        Matrix ans;
        ans.row=ans.column=a.row;
        for(int i=0;i<a.row;i++)
            for(int j=0,k;j<b.column;j++)
                for(ans.data[i][j]=k=0;k<a.row;k++)
                    (ans.data[i][j]+=a.data[i][k]*b.data[k][j])%=mod;
        return ans;
    }
    Matrix pow(long long n)
    {
        Matrix ans,base=*this;
        ans.row=ans.column=row;
        for(int i=0;i<row;i++)
            ans.data[i][i]=1;
        while(n>0)
        {
            if(n%2)
                ans=mul(ans,base);
            base=mul(base,base);
            n>>=1;
        }
        return ans;
    }
}matrix;


int id(char x)
{
    if(x=='A') return 0;
    if(x=='C') return 1;
    if(x=='T') return 2;
    if(x=='G') return 3;
}

class ACAutomation
{
public:
	int trie[maxn][4],fail[maxn];
	int tag[maxn];
	int root,L;

	int newnode()
	{
		for(int i=0;i<4;i++)
			trie[L][i]=-1;
        L++;
		return L-1;
	}

	void init()
	{
		L=0;
		root=newnode();
	}

	//插入模式串，构造单词树(Keyword tree)
	void insert(char buf[])
	{
		int len=strlen(buf);
		int now=root;
		for(int i=0;i<len;i++)
		{
			if(trie[now][id(buf[i])]==-1)
            {
                trie[now][id(buf[i])]=newnode();
                tag[L-1]=false;
            }
			now=trie[now][id(buf[i])];
		}
		tag[now]=true;
	}

	//用BFS计算每个节点的fail指针，构造trie树
	void build()
	{
		queue<int> Q;
		fail[root]=root;
		for(int i=0;i<4;i++)
			if(trie[root][i]==-1)
				trie[root][i]=root;
			else
			{
				fail[trie[root][i]]=root;
				Q.push(trie[root][i]);
			}
		while(!Q.empty())
		{
			int now=Q.front();
			Q.pop();
			if(tag[fail[now]]) tag[now]=true;
			for(int i=0;i<4;i++)
				if(trie[now][i]==-1)
					trie[now][i]=trie[fail[now]][i];
				else
				{
					fail[trie[now][i]]=trie[fail[now]][i];
					Q.push(trie[now][i]);
				}
		}
	}

	void buildMatrix()
	{
	    matrix.row=matrix.column=L;
	    memset(matrix.data,0,sizeof matrix.data);
	    for(int i=0;i<L;i++)
            for(int j=0;j<4;j++)
                if(!tag[i]&&!tag[trie[i][j]])
                    matrix.data[i][trie[i][j]]++;

	}
}AC;

int main()
{
    int m,n;
    char s[20];
    scanf("%d%d",&m,&n);
    AC.init();
    for(int i=0;i<m;i++)
    {
        scanf("%s",s);
        AC.insert(s);
    }
    AC.build();
    AC.buildMatrix();
    matrix=matrix.pow(n);
    int ans=0;
    for(int i=0;i<AC.L;i++)
        (ans+=matrix.data[0][i])%=mod;
    printf("%d\n",ans);
    return 0;
}
