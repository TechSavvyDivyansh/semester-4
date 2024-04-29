/*Regional's CS Department is writing a spell-checker system, and you have been tasked with writing a function to determine how closely two words resemble each other. The algorithm you are to use, albeit not a very good one, is to compare the two words character by character, and count how many times the characters in a given position are the same. For instance, the words "TICK" and "TOCK" have a score of 3, since three characters (T, C, K) are the same. 
Similarly, "CAT" and "DOG" score 0, since no letters match.
You are given Strings A and B and you have to return an integer K indicating the score (as    
defined above) of how closely the two match.*/

#include<stdio.h>
#include<string.h>


char s1[20],s2[20],b[20][20],x[20];
int c[20][20],m,n,count=0;


void LCS()
{
    

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            c[i][j]=0;
        }
    }  

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            b[i][j]='.';
        }
        printf("\n");
    }  


    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else if(c[i-1][j]>c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';                
            }
        }
    }   
    

}


void PRINT_LCS(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='d')
    {
        PRINT_LCS(i-1,j-1);
        x[count]=s1[i-1];   //If this was written above PRINT_LCS(int i,int j) it would print reverse order. Now its using backtracking .Hence no need to reverse order here. 
        count++;
    }
    else if(b[i][j]=='u')
    {
        PRINT_LCS(i-1,j);
    }
    else
    {
        PRINT_LCS(i,j-1);
    }
}



void main()
{
    printf("Enter sequence1:");
    scanf("%s",s1);
    printf("Enter sequence2:");
    scanf("%s",s2);

    m=strlen(s1);
    n=strlen(s2);


    LCS();

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    
    PRINT_LCS(m,n);

    printf("final ans:\n");
    
    for(int i=0;i<count;i++)
    {
        printf("%c",x[i]);
    }

}