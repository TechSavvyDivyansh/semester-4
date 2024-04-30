#include <stdio.h>
#include <time.h>

int i,j,key,arr[];

void insertionSort(int arr[],int n)
{   
    for(int i=0;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;        
    }
}
int main() {    
    clock_t t1,t2,t3;
    int n;
    n=10000;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }    


    t1=clock();     
    insertionSort(arr,n);
    t2=clock();
    t3=t2-t1;    
    printf("average case:%ld\n",t3);    
    
    t1=clock();     
    insertionSort(arr,n);
    t2=clock();
    t3=t2-t1;    
    printf("best case:%ld\n",t3);    
    
    
    int b[n];
    for(int i=n;i>=0;i--)
    {
        b[i]=arr[n-i];
    }
        
    t1=clock();     
    insertionSort(b,n);
    t2=clock();
    t3=t2-t1;    
    printf("worst case:%ld",t3);
    return 0;
}