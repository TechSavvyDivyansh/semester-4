#include<stdio.h>

int process[50]={450,417,112,290,90},memory[50]={110,500,600,300,200},n=5,m=5;

void firstFit()
{   
    int remainingMemory[50]={0},allocated[50]={0};float totalAllocMem=0,totalMem=0;

    for(int i=0;i<m;i++)
    {
        remainingMemory[i]=memory[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(process[i]<=remainingMemory[j] && remainingMemory[j]!=0)
            {
                allocated[j]+=process[i];
                remainingMemory[j]-=process[i];
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
    int remainingMemory[50]={0},allocated[50]={0},c=-1,j=0;float totalAllocMem=0,totalMem=0;

    for(int i=0;i<m;i++)
    {
        remainingMemory[i]=memory[i];
    }


    for(int i=0;i<n;i++)
    {
        while(j!=c)
        {
            if(process[i]<=remainingMemory[j] && remainingMemory[j]!=0)
            {
                allocated[j]+=process[i];
                remainingMemory[j]-=process[i];
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
    int remainingMemory[50]={0},allocated[50]={0},min,temp;
    float totalAllocMem=0,totalMem=0;

    for(int i=0;i<m;i++)
    {
        remainingMemory[i]=memory[i];
    }


    for(int i=0;i<n;i++)
    {
        min=99999,temp=-1;
        for(int j=0;j<m;j++)
        {            
            if(process[i]<=remainingMemory[j] && remainingMemory[j]!=0 && remainingMemory[j]<min)
            {
                min=remainingMemory[j];
                temp=j;
            }
        }
        allocated[temp]+=process[i];
        remainingMemory[temp]-=process[i];
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
    int remainingMemory[50]={0},allocated[50]={0},max,temp;
    float totalAllocMem=0,totalMem=0;

    for(int i=0;i<m;i++)
    {
        remainingMemory[i]=memory[i];
    }

    for(int i=0;i<n;i++)
    {
        max=0,temp=-1;
        for(int j=0;j<m;j++)
        {            
            if(process[i]<=remainingMemory[j] && remainingMemory[j]!=0 && remainingMemory[j]>max)
            {
                max=remainingMemory[j];
                temp=j;
            }
        }
        allocated[temp]+=process[i];
        remainingMemory[temp]-=process[i];
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
    // firstFit();
    // printf("best Fit:\n");
    // bestFit();
    // printf("worst Fit:\n");
    worstFit();
    // printf("next Fit:\n");
    // nextFit();
}