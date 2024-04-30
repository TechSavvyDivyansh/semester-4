#include<stdio.h>



//To get max value less than or equal to m
int max(int ar[],int n,int m)
{
    int i=0,count=0;
    int x[n];
    for(i=0;i<n;i++)
    {
        if(ar[i]<=m)
        {
             x[count]=ar[i];
             count++;
        }
    }
    int max=x[0];
    for(int i=0;i<count;i++)
    {
        if(x[i]>max)
        {
            max=x[i];
        }
    }

    return max;
    
}

void coinChanging(int m,int arr[],int n)
{       
    // x-> used coins 
    int x[60],count=0;

    while(m>0)
    {
        int coinTaken=max(arr,n,m);
        m-=coinTaken;

        if(m<0)
        {
            printf("exact coin change not possible\n");
        }
        else if(m==0)
        {
            x[count]=coinTaken;
            count++;

            printf("Exact coin change Possible!! changes are :");
            for(int i=0;i<count-1;i++)
            {
                printf("%d,",x[i]);
            }
            printf("%d\n",x[count-1]);
        }
        else
        {
            x[count]=coinTaken;
            count++;
        }
    }

    
}

void main()
{
    int m,coins[50];
    printf("Enter the total cost you need to make:");
    scanf("%d",&m);
    printf("Enter all the available coins:\n");
    
    int coin,i=0;
    do
    {
        printf("Enter coin:");
        scanf("%d",&coin);
        if(coin>0)
        {
            coins[i]=coin;
            i++;
        }

    }while(coin>0);

    coinChanging(m,coins,i);
    

}