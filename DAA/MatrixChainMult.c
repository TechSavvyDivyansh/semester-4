// Implementation of Matrix Chain Multiplication using dynamic programming.
#include<stdio.h>

int d[5]={3,2,4,2,5};
int c[4][4];
int x[4][4];

void cost(int i,int j)
{
    int tempc=1000,tempk=0;
    for(int k=i;k<j;k++)
    {
        if(tempc>(c[i][k]+c[k+1][j]+d[i]*d[j+1]*d[k+1]))
        {
            tempc=c[i][k]+c[k+1][j]+d[i]*d[j+1]*d[k+1];
            tempk=k+1;
        }
    }

    c[i][j]=tempc;
    x[i][j]=tempk;
}

void printOptimalOrder(int i, int j) {
    if (i == j) {
        printf("A%d ", i+1);
    } else {
        printf("(");
        printOptimalOrder(i, x[i][j]-1);
        printOptimalOrder(x[i][j], j);
        printf(")");
    }
}


void tableForm()
{
    for(int i=0;i<4;i++)
    {
        c[i][i]=0;
    }
    
    
    int count=1;
    while(count <=3)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(j-i==count)
                {
                    printf("i:%d j:%d\n",i,j);
                    cost(i,j);
                }
            }
        }
        count++;
    }



}

void main()
{   
    tableForm();

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    printf("\n xtra table\n");

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }

    printOptimalOrder(0,3);

}