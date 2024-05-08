#include<stdio.h>

int key,arr[50]={8,10,50,500,1,20};


int binary(int low,int high)
{
    int mid;

    if(low<=high)
    {
        mid=(low+high)/2;
    
        if(key==arr[mid])
            return;
        else if(key<arr[mid])
        {
            binary(low,mid-1);
        }
        else
        {
            binary(mid+1,high);
        }
    }

    else
        return -1;

}

void main()
{
    printf("Enter value to be searched:");
    scanf("%d",&key);
    
    
}