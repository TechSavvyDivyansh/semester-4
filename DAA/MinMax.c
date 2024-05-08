#include <stdio.h>

int arr[50];

void MaxMin(int low, int high, int *max, int *min)
{
    if (low == high)
    {
        *min = *max = arr[low];
    }
    else if (low == high - 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int leftMax, leftMin, rightMax, rightMin;
        MaxMin(low, mid, &leftMax, &leftMin);
        MaxMin(mid + 1, high, &rightMax, &rightMin);

        *max = (rightMax > leftMax) ? rightMax : leftMax;
        *min = (rightMin < leftMin) ? rightMin : leftMin;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max, min;
    MaxMin(0, n - 1, &max, &min);
    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);

    return 0;
}
