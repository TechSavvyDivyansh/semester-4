#include<stdio.h>
#include<stdlib.h>


int trackReq[10]={82,170,43,140,24,16,190};
int head=50,start=0,end=199;

void FIFO()
{
    int temp=head;
    int trackMovement=0;
    for(int i=0;i<7;i++)
    {
        trackMovement+=abs(temp-trackReq[i]);
        temp=trackReq[i];
    }

    printf("track movement:%d",trackMovement);

}

void SSTF()
{
    int temp=head;
    int visited[10]={0};
    int trackMovement=0;
    
    for(int j=0;j<7;j++)
    {
        int min=1000,tempmin=0,tempi=0;
        
        for(int i=0;i<7;i++)
        {
            if(abs(trackReq[i]-temp)<min && visited[i]!=1)
            {
                min=abs(trackReq[i]-temp);
                tempmin=trackReq[i];
                tempi=i;
            }
        }
        visited[tempi]=1;
        
        temp=tempmin;
        // printf("min:%d tempmin:%d temp:%d\n",min,tempmin,temp);
        trackMovement+=min;
        
    }

    printf("trackmovement:%d",trackMovement);

}


void SCAN()
{
    int k,trackMovement=0;
    printf("Enter 1 for up and 2 for down:");
    scanf("%d",&k);

    int max=0,min=1000;
    for(int i=0;i<7;i++)
    {   
        if(trackReq[i]>max)
            max=trackReq[i];
        if(trackReq[i]<min)
            min=trackReq[i];
    }
    switch (k)
    {
        case 1:
        {
            trackMovement=(end-head)+(end-min);
            break;
        }
        case 2:
        {
            trackMovement=(head-start)+(max-start);
            break;
        }
        
        default:
        {
            printf("Kachra mat dalo"); 
            break;
        }
    }
    printf("\ntrack movement:%d\n",trackMovement);
}


void CSCAN()
{
    int k,trackMovement=0;
    printf("Enter 1 for up and 2 for down:");
    scanf("%d",&k);

    int down=1000,up=0;
    for(int i=0;i<7;i++)
    {   
        if(trackReq[i]<down && trackReq[i]>head)
            down=trackReq[i];
        if(trackReq[i]>up && trackReq[i]<head)
            up=trackReq[i];
    }
    printf("up:%d and down:%d",up,down);
    switch (k)
    {
        case 1:
        {
            trackMovement=(end-head)+(end-start)+(up-start);
            break;
        }
        case 2:
        {
            trackMovement=(head-start)+(end-start)+(end-down);   
            break;
        }
        
        default:
        {
            printf("Kachra mat dalo"); 
            break;
        }
    }
    printf("\ntrack movement:%d\n",trackMovement);
}


void LOOK()
{
    int k,trackMovement=0;
    printf("Enter 1 for up and 2 for down:");
    scanf("%d",&k);

    int max=0,min=1000;
    for(int i=0;i<7;i++)
    {   
        if(trackReq[i]>max)
            max=trackReq[i];
        if(trackReq[i]<min)
            min=trackReq[i];
    }
    switch (k)
    {
        case 1:
        {
            trackMovement=(max-head)+(max-min);
            break;
        }
        case 2:
        {
            trackMovement=(head-min)+(max-min);
            break;
        }
        
        default:
        {
            printf("Kachra mat dalo"); 
            break;
        }
    }
    printf("\ntrack movement:%d\n",trackMovement);
}


void CLOOK()
{
    int k,trackMovement=0;
    printf("Enter 1 for up and 2 for down:");
    scanf("%d",&k);

    int max=0,min=1000,up=0,down=1000;
    for(int i=0;i<7;i++)
    {   
        if(trackReq[i]>max)
            max=trackReq[i];
        if(trackReq[i]<min)
            min=trackReq[i];
        if(trackReq[i]>up && trackReq[i]<head)
            up=trackReq[i];
        if(trackReq[i]<down && trackReq[i]>head)
            down=trackReq[i];
    }
    printf("up:%d down:%d",up,down);
    switch (k)
    {
        case 1:
        {
            trackMovement=(max-head)+(max-min)+(up-min);
            break;
        }
        case 2:
        {
            trackMovement=(head-min)+(max-min)+(max-down);
            break;
        }
        
        default:
        {
            printf("Kachra mat dalo"); 
            break;
        }
    }
    printf("\ntrack movement:%d\n",trackMovement);
}





void main()
{
    FIFO();
    SSTF();
    SCAN();
    CSCAN();
    LOOK();
    CLOOK();
}