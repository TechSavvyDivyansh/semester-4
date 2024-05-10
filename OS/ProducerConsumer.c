#include<stdio.h>

int buffer[50],n=8,semaphore=1,in=0,empty=8,full=0,out=0;

void Producer(int item)
{
    semaphore--;
    if(full<n && semaphore==0)
    {
        empty--;
        buffer[in]=item;
        printf("%d entered\n",item);
        in=(in+1)%n;
        full++;         
    }
    else
    {
        printf("cannot produce\n");
    }
    semaphore++;
}

void consumer()
{
    semaphore--;
    if(empty!=n && semaphore==0)
    {
        full--;
        int item=buffer[out];
        buffer[out]=0;
        printf("item:%d\n",item);
        out=(out+1)%n;
        printf("%d left\n",item);
        empty++;
    }
    else
    {
        printf("cannot consume\n");
    }
    semaphore++;
}


void main()
{
    consumer();
    Producer(5);
    Producer(1);
    Producer(6);
    Producer(9);
    Producer(10);
    Producer(11);
    Producer(12);
    Producer(15);
    Producer(16);
    consumer();
    Producer(17);
    Producer(18);
    for(int i=0;i<n;i++)
    {
        printf("%d ",buffer[i]);
    }
}