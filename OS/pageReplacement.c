#include<stdio.h>

int frames=3,pageReq[50]={6,0,12,0,30,4,12,6,0,4,12,0},n=12;

void fifo()
{
    int fifoTrack[50],pageTable[50],temp=0;float hit=0,miss=0;

    for(int i=0;i<frames;i++)
    {
        pageTable[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<frames;j++)
        {
            if(pageReq[i]==pageTable[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            hit++;
        }
        else
        {
            miss++;
            pageTable[temp]=pageReq[i];
            temp=(temp+1)%frames;
        }
        for(int i=0;i<frames;i++)
        {
            printf("%d ",pageTable[i]);
        }
        printf("\n");
        
    }

    printf("hit:%0.0f and miss:%0.0f and %%hit:%0.2f%% %%miss:%0.2f%%\n",hit,miss,(hit/n)*100,(miss/n)*100);
    

}

int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;

    for (int i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }

    return pos;
}


void lru()
{
    int pageTable[50],temp=0;float hit=0,miss=0;
    int time[frames];

    for (int i = 0; i < frames; ++i) {
        pageTable[i] = -1; // Initialize frames to -1, indicating empty frames
        time[i] = -1; // Initialize time for each frame
    }

    for (int i = 0; i < n; ++i) {
        int page = pageReq[i];
        int found = 0,index;

        for (int j = 0; j < frames; ++j) {
            if (pageTable[j] == page) {
                found = 1;
                time[j] = i; // Update time for the page in use
                hit++;
                break;
            }
        }

        if (!found) {
            index = findLRU(time, frames);
            pageTable[index] = page;
            time[index] = i;
            ++miss;
        }

        for(int k=0;k<frames;k++)
        {
            printf("%d ",time[k]);
        }
        printf("\n");

        printf("Page %d: ", page);
        printf("time[i]:%d and index:%d\n",time[i],index);
        for (int j = 0; j < frames; ++j) {
            printf("%d ", pageTable[j]);
        }
        printf("\n");
        printf("\n");
    }

    printf("Total Page Faults: %f\n", miss);
        
        
}
   




void optimal()
{
    
    int pageTable[50],hit=0,miss=0,count=0;
    for(int i=0;i<frames;i++)
    {
        pageTable[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d  ->",pageReq[i]);

        int flag=0;
        for(int k=0;k<frames;k++)
        {
            if(pageReq[i]==pageTable[k])
            {
                hit++;
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            if(count<frames)
            {
                pageTable[count]=pageReq[i];
                count++;
                miss++;
            }
            else
            {
                int optimalTrack[50];
                for(int k=0;k<frames;k++)
                {
                    int c=0,ci=0;
                    for(int j=i+1;j<n;j++)
                    {
                        // printf("j:%d \n",j);
                        if(pageTable[k]==pageReq[j])
                        {
                            c=1;
                            ci=j;
                            break;
                        }

                    }
                    if(c==1)
                    {
                        optimalTrack[k]=ci;
                    }
                    else
                    {
                        optimalTrack[k]=9999;
                    }
                }

                printf("optimal track:");
                for(int k=0;k<frames;k++)
                {
                    printf("%d ",optimalTrack[k]);
                }
                printf("\n");
                
                int max=-1,maxi=0;
                for(int k=0;k<frames;k++)
                {
                    if(optimalTrack[k]>max)
                    {
                        max=optimalTrack[k];
                        maxi=k;
                    }
                }
                pageTable[maxi]=pageReq[i];
                miss++;
            }
        }

        for(int k=0;k<frames;k++)
        {
            printf("%d ",pageTable[k]);
        }
        printf("  hit:%d miss:%d",hit,miss);
        printf("\n");
        printf("\n");
    }


}



void main()
{
    // fifo();
    // lru();
    optimal();
    
}