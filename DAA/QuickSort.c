#include<stdio.h>
#include<time.h>

int ar[40],n;


int partition(int ar[],int low,int high)
{
    int pivot=ar[high];
    int i = low-1;

    for(int j=low;j<high;j++)
    {
        if(ar[j]<pivot)
        {
            i++;

            // swap
            int temp;
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
        }
    }
    i++;
    // swap to fix pivot
    int temp;
    temp=ar[i];
    ar[i]=pivot;  //pivot is same as ar[high]
    ar[high]=temp;

    return i;

}

void quickSort(int ar[],int low,int high)
{
    if(low<high)
    {
         int pivotindex=partition(ar,low,high);

         quickSort(ar,low,pivotindex-1);
         quickSort(ar,pivotindex+1,high);
    }
}


void main() {
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements of the array:");
    scanf("%d", &n);
    printf("Enter the array to be sorted:\n");
    for(int i = 0; i < n; i++) {
        ar[i] = rand() % 1000; // Corrected the random number generation
    }

    start = clock();
    quickSort(ar, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by quickSort: %f seconds\n", time_taken);

  
}