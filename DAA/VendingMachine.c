/*You are working on the software for a vending machine that accepts both bills and coins. The goal is to implement a dynamic programming solution to determine the minimum number of coins to be returned as change when a customer makes a purchase.
Input:
The purchase amount.
The amount paid by the customer.
A set of available coin denominations in the vending machine.
Output:
The minimum number of coins needed for change.
The combination of coins that make up the minimum number.*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int min(int a,int b)
{
    int x=-1;
    if(a<b)
        x=a; 
    else 
        x=b;
    return x;
}

void coinChange(int weight)
{
    int machineCoins[]={1,2,5,10,20,50,100};
    int coins=sizeof(machineCoins)/sizeof(machineCoins[0]);
    int coinCountArr[100][100];

    for(int i=0;i<=coins;i++)
    {
        for(int j=0;j<=weight;j++)
        {
            coinCountArr[i][j]=0;
        }
    }
    

    for(int j=0;j<=weight;j++)
    {
        coinCountArr[0][j]=j;
    }
    
    for(int i=1;i<=coins;i++)
    {
        for(int j=0;j<=weight;j++)
        {
            int tempw=coinCountArr[0][j];
            int tempc=machineCoins[i-1];
            int count=0;
            while(tempw>=tempc)
            {
                tempw-=tempc;
                count++;
            }
            count+=coinCountArr[i-1][tempw];

            // printf("%d ",tempw);

            coinCountArr[i][j]=min(coinCountArr[i-1][j],count);
        }
        // printf("\n");
    }


    for(int i=0;i<=coins;i++)
    {
        for(int j=0;j<=weight;j++)
        {
            printf("%d ",coinCountArr[i][j]);
        }
        printf("\n");
    }

    int coinNumber=coinCountArr[coins][weight];
    int i=coins,j=weight;
    int x[50];
    int count=0;
    while(coinNumber!=0)
    {
        if(coinCountArr[i][j]==coinCountArr[i-1][j] && i!=1)
        {
            i-=1;
        }
        else
        {
            x[count]=machineCoins[i-1];
            coinNumber--;
            j=coinCountArr[0][j]-x[count];
            count++;
        }
        printf("\ni:%d and j:%d",i,j);
    }

    printf("\nfinal ans:");
    for(int i=0;i<count;i++)
    {
        printf("%d ",x[i]);
    }
    
}

void main()
{
    int bill,paid;
    printf("Enter the bill amount 💰:");
    scanf("%d",&bill);

    printf("Enter the amount paid 💵:");
    scanf("%d",&paid);

    if(paid<bill)
    {
        printf("You have paid less!!😡\n");
    }
    else if(paid==bill)
    {
        printf("Please collect your product. Thank You .Please visit again!!!🥳\n");
    }
    else 
    {
        int payable=paid-bill;
        coinChange(payable);
    }
}