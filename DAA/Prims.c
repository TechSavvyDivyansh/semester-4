#include<stdio.h>

int map[50][50]={
    {0,4,0,0,0,0,0,8,0},
    {4,0,8,0,0,0,0,11,0},
    {0,8,0,7,0,4,0,0,2},
    {0,0,7,0,9,14,0,0,0},
    {0,0,0,9,0,10,0,0,0},
    {0,0,4,14,10,0,2,0,0},
    {0,0,0,0,0,2,0,1,6},
    {8,11,0,0,0,0,1,0,7},
    {0,0,2,0,0,0,6,7,0},
};

int dist[50],parent[50],visited[50]={0},source=0,n=9;

int extract_min()
{
    int temp=10000,tempi=0;

    for(int i=0;i<n;i++)
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
    if(dist[v]>map[u][v])
    {
        dist[v]=map[u][v];
        parent[v]=u;
    }
}


void Prims()
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
    Prims();
    printf("Distance :\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",dist[i]);
    }

    printf("parent:\n");
    for(int i=0;i<n;i++)
    {
        printf("%c ",parent[i]+65);
    }

}