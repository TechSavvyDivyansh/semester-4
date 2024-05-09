#include<stdio.h>

int process[50]={450,417,112,290,90},memory[50]={125,500,200,300,600},n=5,m=5;

void firstFit()
{   
    int visited[50]={0},allocated[50]={0};float totalAllocMem=0,totalMem=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(process[i]<=memory[j] && visited[j]!=1)
            {
                allocated[j]=process[i];
                visited[j]=1;
                break;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        printf("%d ",allocated[i]);
        totalAllocMem+=allocated[i];
        totalMem+=memory[i];
    }
    printf("\nMemory utilization:%f%%\n",(totalAllocMem/totalMem)*100);
}


void nextFit()
{   
    int visited[50]={0},allocated[50]={0},c=-1,j=0;float totalAllocMem=0,totalMem=0;
    for(int i=0;i<n;i++)
    {
        while(j!=c)
        {
            if(process[i]<=memory[j] && visited[j]!=1)
            {
                allocated[j]=process[i];
                visited[j]=1;
                c=j;
                j=(j+1)%m;
                break;
            }
            j=(j+1)%m;
        }
    }

    for(int i=0;i<m;i++)
    {
        printf("%d ",allocated[i]);
        totalAllocMem+=allocated[i];
        totalMem+=memory[i];
    }
    printf("\nMemory utilization:%f%%\n",(totalAllocMem/totalMem)*100);
}





void bestFit()
{
    int visited[50]={0},allocated[50]={0},min,temp;
    float totalAllocMem=0,totalMem=0;


    for(int i=0;i<n;i++)
    {
        min=99999,temp=-1;
        for(int j=0;j<m;j++)
        {            
            if(process[i]<=memory[j] && visited[j]!=1 && memory[j]<min)
            {
                min=memory[j];
                temp=j;
            }
        }
        allocated[temp]=process[i];
        visited[temp]=1;
    }

    for(int i=0;i<m;i++)
    {
        printf("%d ",allocated[i]);
        totalAllocMem+=allocated[i];
        totalMem+=memory[i];
    }
    printf("\nMemory utilization:%f%%\n",(totalAllocMem/totalMem)*100);

}


void worstFit()
{
    int visited[50]={0},allocated[50]={0},max,temp;
    float totalAllocMem=0,totalMem=0;


    for(int i=0;i<n;i++)
    {
        max=0,temp=-1;
        for(int j=0;j<m;j++)
        {            
            if(process[i]<=memory[j] && visited[j]!=1 && memory[j]>max)
            {
                max=memory[j];
                temp=j;
            }
        }
        allocated[temp]=process[i];
        visited[temp]=1;
    }

    for(int i=0;i<m;i++)
    {
        printf("%d ",allocated[i]);
        totalAllocMem+=allocated[i];
        totalMem+=memory[i];
    }
    printf("\nMemory utilization:%f%%\n",(totalAllocMem/totalMem)*100);
}



void main()
{
    printf("first Fit:\n");
    firstFit();
    printf("best Fit:\n");
    bestFit();
    printf("worst Fit:\n");
    worstFit();
    printf("next Fit:\n");
    nextFit();
}