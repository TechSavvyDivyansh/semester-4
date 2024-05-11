#include<stdio.h>


struct Process
{
    int pid,arrival,burst,priority,completion,turnaround,waiting,remainingBT;
};

struct Process processes[50]={
    {1,0,5,2,-1,-1,-1,-1},
    {2,1,6,4,-1,-1,-1,-1},
    {3,2,3,6,-1,-1,-1,-1},
    {4,3,1,10,-1,-1,-1,-1},
    {5,4,5,8,-1,-1,-1,-1},
    {6,6,4,12,-1,-1,-1,-1}
};

int n=6;

void sort()
{
    struct Process temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].arrival>processes[j+1].arrival)
            {
                temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
}


void FCFS()
{
    sort();
    int current=processes[0].arrival+processes[0].burst;
    processes[0].completion=current;

    // completion time calculation
    for(int i=1;i<n;i++)
    {
        if(processes[i].arrival<=current)
        {
            current+=processes[i].burst;
            processes[i].completion=current;
        }
        else
        {
            current=processes[i].arrival+processes[i].burst;
            processes[i].completion=current;
        }
    }


    // others update
    for(int i=0;i<n;i++)
    {
        processes[i].turnaround=processes[i].completion-processes[i].arrival;
        processes[i].waiting=processes[i].turnaround-processes[i].burst;
    }

}



void SJF()
{
    sort();
    int mini=-1,visited[50]={0};
    int current=0;

    int count=0;

    // completion time calc
    while(count!=n)
    {
        printf("current:%d mini:%d\n",current,mini);
        int temp=mini;
        int minBurst=1000;
        for(int i=0;i<n;i++)
        {
            if(processes[i].arrival<current && processes[i].burst<minBurst && visited[i]!=1)
            {
                minBurst=processes[i].burst;
                mini=i;
            }
            
        }
        if(mini!=temp)
        {
                current+=processes[mini].burst;
                processes[mini].completion=current;
                visited[mini]=1;
                count++;
        }
        else 
        {
            int tempwait=0;
            for(int k=0;k<n;k++)
            {
                if(visited[k]!=1)
                {
                    tempwait=k;
                    break;
                }
            }

            current=processes[tempwait].arrival+processes[tempwait].burst;
            processes[tempwait].completion=current;
            visited[tempwait]=1;
            count++;
        }
    }



    // update others
    for(int i=0;i<n;i++)
    {
        processes[i].turnaround=processes[i].completion-processes[i].arrival;
        processes[i].waiting=processes[i].turnaround-processes[i].burst;
    }    
        

}



void SRTF()
{
    sort();
    for(int i=0;i<n;i++)
    {
        processes[i].remainingBT=processes[i].burst;
    }

    int count=0,currentTime=0;


    // completion time calc
    while(count!=n)
    {
        int minBurst=1000,mini=-1;
        int temp=mini;
        for(int j=0;j<n;j++)
        {
            if(processes[j].arrival<=currentTime && processes[j].remainingBT<minBurst && processes[j].remainingBT!=0)
            {
                minBurst=processes[j].remainingBT;
                mini=j;
            }
        }


        if(mini!=temp)  //if processes[j].arrival<=currentTime turns false
        {
            currentTime++;
            processes[mini].remainingBT--;
            processes[mini].completion=currentTime;
            if(processes[mini].remainingBT==0)
            {
                count++;
            }
        }
        else
        {
            int tempwait=0;
            for(int k=0;k<n;k++)
            {
                if(processes[k].remainingBT!=0)
                {
                    tempwait=k;
                    break;
                }
            }

            currentTime=processes[tempwait].arrival;
        }
    }

    // others update
    for(int i=0;i<n;i++)
    {
        processes[i].turnaround=processes[i].completion-processes[i].arrival;
        processes[i].waiting=processes[i].turnaround-processes[i].burst;
    }
}



void PremtivePriority()
{
    sort();
    for(int i=0;i<n;i++)
    {
        processes[i].remainingBT=processes[i].burst;
    }

    int count=0,currentTime=0;

    // completion time calc
    while(count!=n)
    {
        int maxPriority=-1,maxi=-1;
        int temp=maxi;
        for(int j=0;j<n;j++)
        {
            if(processes[j].arrival<=currentTime && processes[j].priority>maxPriority && processes[j].remainingBT!=0)
            {
                maxPriority=processes[j].priority;
                maxi=j;
            }
        }


        if(maxi!=temp)  //if processes[j].arrival<=currentTime turns false
        {
            currentTime++;
            processes[maxi].remainingBT--;
            processes[maxi].completion=currentTime;
            if(processes[maxi].remainingBT==0)
            {
                count++;
            }
        }
        else
        {
            int tempwait=0;
            for(int k=0;k<n;k++)
            {
                if(processes[k].remainingBT!=0)
                {
                    tempwait=k;
                    break;
                }
            }

            currentTime=processes[tempwait].arrival;
        }
    }


    // others calc
    for(int i=0;i<n;i++)
    {
        processes[i].turnaround=processes[i].completion-processes[i].arrival;
        processes[i].waiting=processes[i].turnaround-processes[i].burst;
    }
}



void NonPremtivePriority()
{
    sort();
    int maxi=-1,visited[50]={0};
    int current=0;

    int count=0;

    // completion time calc
    while(count!=n)
    {
        int temp=maxi;
        int maxPriority=-1;
        for(int i=0;i<n;i++)
        {
            if(processes[i].arrival<current && processes[i].priority>maxPriority && visited[i]!=1)
            {
                maxPriority=processes[i].priority;
                maxi=i;
            }
            
        }
        printf("current:%d maxpriority:%d maxi:%d\n",current,maxPriority,maxi);
        if(maxi!=temp)
        {
                current+=processes[maxi].burst;
                processes[maxi].completion=current;
                visited[maxi]=1;
                count++;
        }
        else 
        {
            int tempwait=0;
            for(int k=0;k<n;k++)
            {
                if(visited[k]!=1)
                {
                    tempwait=k;
                    break;
                }
            }

            current=processes[tempwait].arrival+processes[tempwait].burst;
            processes[tempwait].completion=current;
            visited[tempwait]=1;
            count++;
        }
    }



    // update others
    for(int i=0;i<n;i++)
    {
        processes[i].turnaround=processes[i].completion-processes[i].arrival;
        processes[i].waiting=processes[i].turnaround-processes[i].burst;
    }    
}



void roundRobin()
{
    sort();

    int quantum=4,queue[500]={0};
    int front=-1 ,rear=-1;
    int count=0,currentTime=0;
    int visited[500]={0};

    for(int i=0;i<n;i++)
    {
        processes[i].remainingBT=processes[i].burst;
    }


    while(count!=n)
    {
        for(int i=0;i<n;i++)
        {
            if(processes[i].arrival<=currentTime && visited[i]!=1)
            {
                rear+=1;
                queue[rear]=processes[i].pid;
                visited[processes[i].pid-1]=1;
            }
        }  
        printf("currentTime:%d \n",currentTime);
        // queue filled once

        front+=1;
        int item=queue[front]-1;
        printf("item:%d \n",item);

        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
        
        if(processes[item].remainingBT<=quantum)
        {
            currentTime+=processes[item].remainingBT;
            processes[item].remainingBT=0;

            for(int i=0;i<n;i++)
            {
                if(processes[i].arrival<=currentTime && i!=item && visited[i]!=1)
                {
                    rear+=1;
                    queue[rear]=processes[i].pid;
                    visited[processes[i].pid-1]=1;
                }
            }

            processes[item].completion=currentTime;
            count++;
        }

        else
        {
            currentTime+=quantum;
            processes[item].remainingBT-=quantum;
            
            for(int i=0;i<n;i++)
            {
                if(processes[i].arrival<=currentTime && i!=item && visited[i]!=1)
                {
                    rear+=1;
                    queue[rear]=processes[i].pid;
                    visited[processes[i].pid-1]=1;
                }
            }
            rear+=1;
            queue[rear]=processes[item].pid;
        }


    }

}


void main()
{
    // FCFS();
    // SJF();
    // SRTF();
    // PremtivePriority();
    // NonPremtivePriority();
    roundRobin();


    int totalTAT=0,totalWait=0;
    printf("PID\tARRIVAL\tBURST\tCOMPLETION\tTURNAROUND\tWAITING\n");
    for(int i=0;i<n;i++)
    {
        printf("%d \t%d \t%d \t%d \t\t%d \t\t%d\n",processes[i].pid,processes[i].arrival,processes[i].burst,processes[i].completion,processes[i].turnaround,processes[i].waiting);
        totalTAT+=processes[i].turnaround;
        totalWait+=processes[i].waiting;
    }

    printf("TOTAL TAT:%d and TOTAL WAIT=%d\n",totalTAT,totalWait);
}