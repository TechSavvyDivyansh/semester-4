#include<stdio.h>

int w[50]={5,10,12,13,15,18},x[50],m=30,n=6;

void SumOfSubset(int s,int k,int r)
{
    x[k]=1;
    if(s+w[k]==m)
    {
        printf("\nans:");
        for(int i=0;i<6;i++)
        {
            printf("%d ",x[i]);
        }
        printf("\n");
    }
    else if(s+w[k]+w[k+1]<=m)
    {
        // printf("\ns:%d k:%d r:%d",s,k,r);
        SumOfSubset(s+w[k],k+1,r-w[k]);
    }
    if(s+w[k+1]<=m && s+r-w[k]>=m)
    {
        x[k]=0;
        // printf("\ns:%d k:%d r:%d",s,k,r);
        SumOfSubset(s,k+1,r-w[k]);
    }
    x[k] = 0;
}

void main()
{
    SumOfSubset(0,0,73);
}
