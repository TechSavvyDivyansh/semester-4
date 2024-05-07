#include<stdio.h>

int T[50][50],profit[]={60,100,120},weights[]={2,5,4},m=10,finalans[50]={0},n=3;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void fillTable()
{
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                T[i][j] = 0;
            else if (weights[i - 1] <= j)
                T[i][j] = max(profit[i - 1] + T[i - 1][j - weights[i - 1]], T[i - 1][j]);
            else
                T[i][j] = T[i - 1][j];
        }
    }



    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=m;j++)
        {
            printf("%d ",T[i][j]);
        }
        printf("\n");
    }
}

void printAns()
{
    int count=n;
    int j=m;
    while(count!=1)
    {
        while(T[count][j]==T[count][j-1] && j!=0)
        {
            j--;
        }
        while(T[count][j]==T[count-1][j] && j!=0)
        {
            count--;
        }
        if(T[count][j]!=T[count-1][j])
        {
            finalans[count-1]=1;
        }
        
        count--;
    }

    for(int i=0;i<n;i++)
    {
        if(finalans[i]==1)
        {
            printf("%d ",weights[i]);
        }
    }
    printf("total profit:%d",T[n][m]);
}

void main()
{
    fillTable();
    printAns();
}
