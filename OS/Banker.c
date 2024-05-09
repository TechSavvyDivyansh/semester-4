#include<stdio.h>

int need[50][50]={
    {7,4,3},
    {21,2,2},
    {6,0,0},
    {0,1,1},
    {4,3,1}
},alloc[50][50]={
    {0, 1, 0},
    {2, 0, 0}, 
    {3, 0, 2}, 
    {2, 1, 1}, 
    {0, 0, 2}
},avail[50]={3,3,2},safeSeq[50]={0},request[50]={1,0,2},Processrequest=1,visited[50],count=0,n=5,resources=3;

int RequestChanges()
{
    int count=0;
    for(int i=0;i<resources;i++)
    {
        if(request[i]<=avail[i])
        {
            count++;
        }
    }
    if(count==resources)
    {
        for(int j=0;j<resources;j++)
        {
            alloc[Processrequest][j]+=request[j];
            avail[j]-=request[j];
            need[Processrequest][j]-=request[j];
        }
        return 1;
    }
    else
    {
        return 0;
    }
}


void banker()
{   
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<resources;j++)
            {
                if(need[i][j]<=avail[j] && visited[i]!=1)
                {
                    temp++;
                }
            }
            if(temp==resources)
            {
                safeSeq[count]=i;
                visited[i]=1;
                count++;
                for(int j=0;j<resources;j++)
                {
                    avail[j]+=alloc[i][j];
                }
            }
        }
    }
}


void main()
{
    int newReq=RequestChanges();
    banker();
    
    if(newReq==0)
    {
        printf("Request not granted!!\n");
    }
    else if(count==n && newReq==1)
    {
        printf("SAFE SEQUENCE✅\n");        
        for(int i=0;i<count;i++)
        {
            printf("%d ",safeSeq[i]);
        }
    }
    else
    {
        printf("DEADLOCK💣!!");        
    }

}