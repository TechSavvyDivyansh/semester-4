#include<stdio.h>
#include<string.h>

char T[50],P[50];int pie[50];


void Compute_prefix()
{
    int m=strlen(P),k=0;
    
    pie[0]=0;

    for(int q=1;q<m;q++)
    {
        while(k>0 && P[k]!=P[q])
        {
            k=pie[q];
        }
        if(P[k]==P[q])
            k++;
        pie[q]=k;
    }    
    printf("Pie:\n");
    for(int i=0;i<m;i++)
    {
        printf("%d ",pie[i]);
    }
}


void KMP()
{
    int m,n;
    n=strlen(T);
    m=strlen(P);

    int q=0;

    for(int i=0;i<n;i++)
    {
        while(q>0 && P[q]!=T[i])
        {
            q=pie[q-1];
        }
        if(P[q]==T[i]) 
            q++;
        if(q==m)
        {
            printf("Pattern occurs shift: %d",i-m+1);
            q=pie[q-1];
        }
        printf("\nq:%d",q);

    }

}



void main()
{
    printf("\nEnter the text to be checked:");
    scanf("%s",T);
    printf("\nEnter the pattern to be checked:");
    scanf("%s",P);

    Compute_prefix();
    KMP();
    
}