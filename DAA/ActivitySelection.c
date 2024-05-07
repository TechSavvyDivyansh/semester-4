#include<stdio.h>

int start[50]={1,3,0,5,3,5,6,7,8,2,12},end[50]={4,5,6,7,9,9,10,11,12,14,16},n=11;

void sort()
{
    int tempS=0,tempE=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(end[j]>end[j+1])
            {
                tempE=end[j];
                end[j]=end[j+1];
                end[j+1]=tempE;
                tempS=start[j];
                start[j]=start[j+1];
                start[j+1]=tempS;
            }
        }
    }
}


void ActivitySelection()
{
    int selected=0,count=0;

    for(int i=0;i<n;i++)
    {
        if(start[i]>=selected)
        {
            printf("Taking %d->%d\n",start[i],end[i]);
            selected=end[i];
            count++;
        }
    }

    printf("\nTotal Activities selected: %d\n",count);

}

void main()
{
    sort();
    ActivitySelection();
    
}