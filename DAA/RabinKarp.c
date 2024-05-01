#include<stdio.h>
#include<string.h>
#include<math.h>

char T[50],P[50];


void RabinKarp(int d,int q)
{
    int m,n,h,temp=1,p=0,t=0;
    n=strlen(T);
    m=strlen(P);

    for(int i=1;i<m;i++)
    {
        temp*=d;
    }
    h=temp%q;
    // printf("%d",h);

    for(int i=0;i<m;i++)
    {
        p=((d*(p)+P[i])%q);
        t=((d*(t)+T[i])%q);
    }

    // printf("P%d T%d",p,t);

    for(int s=0;s<=n-m;s++)
    {
        int count=0;
        if(p==t)
        {
            for(int i=0;i<m;i++)
            {
                if(P[i]==T[s+i])
                {
                     count++;
                }
            }
            if(count==m)
            {
                printf("Pattern occurs with shift %d",s);
            }
        }

        if(s<n-m)
        {
            printf("\nbefore:%d",t);
            t=(d*(t-T[s]*h)+T[s+m])%q;
            printf("\np:%d",p);
            printf("\nbefore adding q:%d",t);
            if (t < 0)                            //we need to ensure that the value remains within the range [0, q-1], where q is the modulus. However, due to the modulus operation, t might become negative in some cases.This is used to correct that error
            t = (t + q);    
            printf("\nafter:%d",t);
        }

    }


}

void main()
{
    printf("\nEnter the text to be checked:");
    scanf("%s",T);
    printf("\nEnter the pattern to be checked:");
    scanf("%s",P);

    RabinKarp(10,1000);

}