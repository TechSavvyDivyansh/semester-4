#include<stdio.h>


float nutrition[10],weight[10];float PByW[10],sortedPByW[10],finalAr[10];
void main()
{
    int m,n;
    printf("Enter the maximum weight your bag can hold:");
    scanf("%d",&m);
    printf("Enter number of fruits you can see in oasis:");
    scanf("%d",&n);


    for(int i=0;i<n;i++)
    {
        printf("---Fruit %d---\n",(i+1));
        printf("Nutrition of fruit:");
        scanf("%f",&nutrition[i]);
        printf("Weight of fruit:");
        scanf("%f",&weight[i]);
        PByW[i]=nutrition[i]/weight[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("---Fruit %d---\n",(i+1));
        printf("Nutrition:%f\n",nutrition[i]);
        printf("Weight:%f\n",weight[i]);
        printf("Pi/Wi:%f\n",PByW[i]);
    }



    for(int i=0;i<n;i++)
    {
        finalAr[i]=0;
    }

    float test;int j;
    // sortedByW initialization
    for(int i=0;i<n;i++)
    {
        sortedPByW[i]=PByW[i];
    }

    

    printf("\nPBYW:\n");
    for(int i=0;i<n;i++)
    {
        printf("%f ",PByW[i]);
    }

    // sorting PByW
    for(int i=1;i<n;i++)
    {
        test=sortedPByW[i];
        j=i-1;
        while(j>=0 && test>sortedPByW[j])
        {
            sortedPByW[j+1]=sortedPByW[j];
            j--;
        }
        sortedPByW[j+1]=test;
    }



    printf("\nsorted PBYW:\n");
    for(int i=0;i<n;i++)
    {
        printf("%f ",sortedPByW[i]);
    }

    // find position of max value
    int position=0;float value,selectedWeight;

    

    int weightCount=m;
        for(int i=0;i<n;i++)
        {
                value=sortedPByW[i];
                for(int j=0;j<n;j++)
                {
                    if(value==PByW[j])
                    {
                        position=j;
                        selectedWeight=weight[j];
                    }
                }

                if(weight[position]<weightCount)
                {
                    finalAr[position]=1;
                }
                else if(weightCount==0 || weightCount<0)
                {
                    finalAr[position]=0;
                }
                else
                {
                    finalAr[position]=weightCount/weight[position];
                }
                weightCount-=weight[position];
        }
        


    printf("\n final array");
    for(int i=0;i<n;i++)
    {
        printf("%f ",finalAr[i]);
    }

    float Finalnutrition=0;
    for(int i=0;i<n;i++)
    {
        Finalnutrition+=finalAr[i]*nutrition[i];
    }
    printf("\nFinal nutrition:%f",Finalnutrition); 
    
}