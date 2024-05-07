#include<stdio.h>

int map[8][8]={
    {0,6,5,5,0,0,0},
    {0,0,0,0,-1,0,0},
    {0,-2,0,0,1,0,0},
    {0,0,-2,0,0,-1,0},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,0},
};

int n=7;
int dist[50],parent[50],visited[50]={0,0,0,0,0,0},source=0,c=0;



void initialize_Single_Source()
{
    for(int i=0;i<n;i++)
    {
        dist[i]=99999;
        parent[i]=-1;
    }
    dist[source]=0;
}

void relax(int u,int v)
{
    if(dist[v]>dist[u]+map[u][v])
    {
        dist[v]=dist[u]+map[u][v];
        parent[v]=u;
    }
}


void BellmanFord()
{
    initialize_Single_Source();

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<n;j++)
            {
                if(map[i][j]!=0)
                {
                    relax(i,j);
                }
            }
        }
    }    
   

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[j]>dist[i]+map[i][j] && map[i][j]!=0)
            {
                    c=1;
            }
        }
    }   


}


void main()
{
    BellmanFord();  
    if(c==1)
    {
        printf("no answer\n");
    }
    else
    {
            printf("Distance :");

            for(int i=0;i<n;i++)
            {
                printf("%d ",dist[i]);
            }
            printf("\n");
            printf("parent:");
            for(int i=0;i<n;i++)
            {
                printf("%d ",parent[i]+1);
            }
            printf("\n");
    }
}