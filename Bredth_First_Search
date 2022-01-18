//bfs
#include<stdio.h>
#include<stdlib.h>

struct vertex
{
    char colour;
    int dist;
    int pi;
};

struct vertex attrib[8];
int edges[8][8];
int queue[8];

int tracker=0;

int enqueue(int);
int dequeue();
void bfs(int);

int main()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            edges[i][j] = 0;
        }

        attrib[i].colour = 'w';
        attrib[i].dist = 999;
        attrib[i].pi = 999;

        queue[i] = 999;
    }

    edges[0][1] = 1; edges[0][4] = 1;
    edges[1][0] = 1; edges[1][5] = 1;
    edges[2][3] = 1; edges[2][5] = 1; edges[2][6] = 1;
    edges[3][2] = 1; edges[3][6] = 1; edges[3][7] = 1;
    edges[4][0] = 1;
    edges[5][1] = 1; edges[5][2] = 1; edges[5][6] = 1;
    edges[6][2] = 1; edges[6][3] = 1; edges[6][5] = 1; edges[6][7] = 1;
    edges[7][3] = 1; edges[7][6] = 1;

    bfs(1);

    return 0;
}

int enqueue(int u)
{
    if(tracker>=8)
    {
        printf("\nQueue is full!");
        return -1;
    }
    
    queue[tracker] = u;
    tracker = tracker+1;
}

int dequeue()
{
    if(tracker<=0)
    {
        printf("\nQueue is empty!");
        return -1;
    }

    int temp = queue[0];

    for(int i=0; i<tracker; i++)
    {
        queue[i] = queue[i+1];
    }
    tracker = tracker-1;

    return temp;
}

void bfs(int s)
{
    attrib[s].colour = 'g';
    attrib[s].dist = 0;
    attrib[s].pi = 999;
    enqueue(s);
    
    int u;

    while(tracker!=0)
    {
        u = dequeue();

        for(int i=0; i<8; i++)
        {
            if(edges[u][i]==1)
            {
                if(attrib[i].colour=='w')
                {
                    attrib[i].colour = 'g';
                    attrib[i].dist = attrib[u].dist + 1;
                    attrib[i].pi = u;

                    enqueue(i);
                }
            }
        }

        attrib[u].colour = 'b';
        printf(" %d",u);
    }
}

