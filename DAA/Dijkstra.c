#include<stdio.h>

int map[100][100]={
    {0,7,9,0,0,4},
    {7,0,10,15,0,0},
    {9,10,0,11,0,2},
    {0,15,11,0,6,0},
    {0,0,0,6,0,9},
    {4,0,2,0,9,0},
};

int dist[100],parent[100],visited[100]={0,0,0,0,0,0},source=0,n=6;

int extract_min()
{
    int temp=10000,tempi=0;

    for(int i=0;i<6;i++)
    {
        if(dist[i]<temp && visited[i]!=1)
        {
            temp=dist[i];
            tempi=i;
        }
    }

    return tempi;

}



void initialize_Single_Soure()
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


void Dijkstra()
{
    initialize_Single_Soure();

    for(int i=0;i<n;i++)
    {
        int U=extract_min();

        for(int j=0;j<n;j++)
        {
            if(map[U][j]!=0 && visited[j] != 1)
            {
                relax(U,j);
            }
        }
        visited[U]=1;
    }
}


void main()
{
    Dijkstra();
    printf("Distance :\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",dist[i]);
    }

    printf("parent:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",parent[i]+1);
    }

}