#include<stdio.h>


float nutrition[10],weight[10];float PByW[10],finalAr[10],totalNutrition=0;int m,n;


void sort()
{
    // sorting PByW  [bubble sort(descending order)]->ANY KIND OF SORTING CAN BE USED and acc to Pbw changing posn of nutrition and weight as well [can be done better using structures]
    for(int i=0;i<n;i++)
    {
        float tempPBW=0,tempW=0,tempN=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(PByW[j]<PByW[j+1])
            {
                tempPBW=PByW[j];
                PByW[j]=PByW[j+1];
                PByW[j+1]=tempPBW;
                tempN=nutrition[j];
                nutrition[j]=nutrition[j+1];
                nutrition[j+1]=tempN;
                tempW=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=tempW;
            }
        }
    }
}


// main logic
void knapsack()
{   
    int count=0;
    int tempm=m;
    int i=0;

    while(tempm>0)
    {
        int tempWeight=weight[i];
        if(tempWeight<=tempm)
        {
            finalAr[count]=1;
            tempm-=tempWeight;
            count++;
        }
        else 
        {
            finalAr[count]=(float)tempm/(float)tempWeight;
            tempm-=tempWeight;
            count++;
        }

        i++;
    }

    printf("\nFINAL ARRAY:");
    for(int i=0;i<n;i++)
    {
        printf("%f ",finalAr[i]);
        totalNutrition+=finalAr[i]*nutrition[i];
    }
    printf("\n");

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
    
    sort();


     // Printing Profit by weight after sorting 
    printf("\nsorted PBYW:");
    for(int i=0;i<n;i++)
    {
        printf("%f ",PByW[i]);
    }
    printf("\n");

    printf("\nsorted weight:");
    for(int i=0;i<n;i++)
    {
        printf("%f ",weight[i]);
    }
    printf("\n");

    printf("\nsorted nutrition:");
    for(int i=0;i<n;i++)
    {
        printf("%f ",nutrition[i]);
    }
    printf("\n");



    knapsack(); 

    printf("You can take total %f nutrition🍒💪 in your bag👜 of %d weight\n",totalNutrition,m);
}