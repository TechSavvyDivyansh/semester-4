//MERGE SORT
#include <stdio.h>
#define n 10000
#include<time.h>

int arr[n];
void conquer(int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int B[n];
    
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            B[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            B[k]=arr[j];
            j++;
            k++;
        }
    }
    
    while(i<=mid)
    {
        B[k]=arr[i];
        k++;
        i++;
    }
    
    while(j<=high)
    {
        B[k]=arr[j];
        j++;
        k++;
    }
    
    for(int m=low;m<high;m++)
    {
        arr[m]=B[m];
    }
    
}

void divide(int low,int high)
{
    int mid;
    mid=(low+high)/2;
    if(low<high)
    {
        divide(low,mid);
        divide(mid+1,high);
        conquer(low,mid,high);
    }
}
int main() {
    int key;
    clock_t t1,t2,t3;
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    t1=clock();
    divide(0,n-1);  
    t2=clock();
    t3=t2-t1;
    printf("\Average Case:%ld",t3);
   
 for(int i=0;i<n;i++)
    {
        arr[i]=i*12;
    }
    t1=clock();
    divide(0,n-1);  
    t2=clock();
    t3=t2-t1;
    printf("\nbest Case:%ld",t3);
    
    for(int i=0;i<n;i++)
    {
        arr[n-i]=i*12;
    }
    t1=clock();
    divide(0,n-1);  
    t2=clock();
    t3=t2-t1;
    printf("\nworst Case:%ld",t3);
    
    return 0;
}