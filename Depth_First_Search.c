// topological sort
#include<stdio.h>

char visit [6];
int edge [6][6];
int stack [6], k=0;

void dfs(int);

int main()
{
    int i, j;

    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            edge[i][j] = 0;
        }

        visit[i] = 0;
    }

    edge[2][3]=1; edge[3][1]=1; edge[4][0]=1; edge[4][1]=1; edge[5][0]=1; edge[5][2]=1;

    for(i=0; i<6; i++)
    {
        if(visit[i]==0)
        {
            dfs(i);
        }
    }

    for(i=5; i>=0; i--)
    {
        printf("%d ",stack[i]);
    }

    return 0;
}

void dfs(int u)
{
    visit[u]=1; 

    for(int v=0; v<6; v++)
    {
        if(edge[u][v]==1)
        {
            if(visit[v]==0)
            {
                //visit[v]=1;
                dfs(v);
            }
        }
    }
    stack[k]=u; k=k+1;
}

