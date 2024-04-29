/*Using backtracking approach for algorithm design, write a program to implement N–queen problem */

#include<stdio.h>
#include<stdlib.h>

int n,x[10];

int place(int k,int j)
{   
    for(int i=0;i<k;i++)
    {
        if(x[i]==j || abs(x[i]-j)==abs(i-k))
            return 0;
    }
    return 1;
}

void NQueens(int k,int n)
{   
    for(int j=0;j<n;j++)
    {
        if(place(k,j)==1)
        {
            x[k]=j;
            if(k+1==n)
            {
                for(int i=0;i<n;i++)
                {                    
                    printf("%d ",x[i]+1);
                }
                printf("\n");
                // return;
            }
            else
            {
                // printf("Nqueen of %d called\n",k+1);
                NQueens(k+1,n);
            }
        }
    }
}



void main()
{
    printf("Enter the chessboard size:");
    scanf("%d",&n);

    NQueens(0,n);

}