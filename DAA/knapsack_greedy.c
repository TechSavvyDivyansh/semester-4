#include<stdio.h>


float nutrition[10],weight[10];float PByW[10],sortedPByW[10],finalAr[10];int m,n;

void knapsack()
{
    // sortedByW initialization
    for(int i=0;i<n;i++)
    {
        sortedPByW[i]=PByW[i];
    }

    
    // PRINTING PROFIT/WEIGHT for each item
    printf("\n\nPBYW:");
    for(int i=0;i<n;i++)
    {
        printf("%f ",PByW[i]);
    }


    // sorting PByW  [INSERTION SORT]->ANY KIND OF SORTING CAN BE USED
    float test;int j;
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


    // Printing Profit by weight after sorting 
    printf("\nsorted PBYW:");
    for(int i=0;i<n;i++)
    {
        printf("%f ",sortedPByW[i]);
    }
    printf("\n");

    // find position of max value
    int position=0;float value,selectedWeight;

    
    //Main Logic of knapsack greedy
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



}


void main()
{
    
    printf("\nEnter the maximum weight your bag can hold 👜:");
    scanf("%d",&m);
    printf("Enter number of fruits you can see in oasis🍒:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("\n---🍎 Fruit %d---\n",(i+1));
        printf("💪 Enter Nutrition of fruit:");
        scanf("%f",&nutrition[i]);
        printf("🏋️ Enter Weight of fruit:");
        scanf("%f",&weight[i]);
        PByW[i]=nutrition[i]/weight[i];
        printf("Profit💰/Weight🏋️ :%f\n",PByW[i]);
        
    }
    

    
    knapsack(); 


    // printing final array that contains fractional values to be accepted
    printf("\n\nfinal array:");
    for(int i=0;i<n;i++)
    {
        printf("%f ",finalAr[i]);
    }


    // Calculating final nutrition
    float Finalnutrition=0;
    for(int i=0;i<n;i++)
    {
        Finalnutrition+=finalAr[i]*nutrition[i];
    }

    printf("\nMaximum Nutrition 🍒💪 that can be taken in bag 👜 of weight %d units is: %f\n\n",m,Finalnutrition); 
}