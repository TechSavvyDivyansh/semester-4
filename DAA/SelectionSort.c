#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

int arr[50],n;


void SelectionSort()
{
    int min,t;
    for(int i=0;i<(n-1);i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
            
        }
        t=arr[i];
        arr[i]=arr[min];
        arr[min]=t;
    }
}


void main()
{
    clock_t start, end;
    int time = end - start;
    

    printf("enter the number of elements of the array:");
    scanf("%d",&n);
    printf("Enter the array to be sorted:\n");
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()*1000;
    }

    start = clock();
    SelectionSort(arr,n);
    end = clock();

    printf("%ld", time);


}