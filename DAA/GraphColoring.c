#include<stdio.h>

int graph[40][40]={
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0},
},x[50],n=4,m=3;


int nextValue(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return 0;
        for(j=0;j<n;j++)
        {
            if(graph[k][j]!=0 && x[k]==x[j])
                break;
        }
        if(j==n)
            return 1;
    }   

}


int mColor(int k)
{
    
    while(1)
    {
        nextValue(k);
        if(x[k]==0)
            return 0;
        if(k == n-1)
        {
            for(int i=0;i<n;i++)
            {
                printf("%d ",x[i]);
            }
            printf("\n");
        }
        else
        {
            mColor(k+1);
        }
    }
}



void main()
{
    mColor(0);
}