// Min Max

/*
    Divide and Conquer
    Time Complexity: WAB - O(n)
    Space Complexity: O(logn)
*/

#include <stdio.h>

struct pair
{
    int min;
    int max;
};
int call_to_stack = 0;
int comp = 0;
struct pair getMinMax(int arr[], int low, int high)
{
    struct pair minmax, mml, mmr;
    int mid;
    call_to_stack++;

    if (low == high)
    {
        comp++;
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1)
    {

        if (arr[low] > arr[high])
        {
            comp++;
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            comp++;
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;

    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);

    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;
    comp++;

    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;
    comp++;
    return minmax;
}

int main()
{
    int arr[5];
    int arr_size = 5;
    printf("****MINIMUM & MAXIMUM****\n");
    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct pair minmax = getMinMax(arr, 0, arr_size - 1);
    printf("\nMinimum element --: %d", minmax.min);
    printf("\nMaximum element --: %d", minmax.max);
    printf("\n--------------------------------");
    printf("\nCalls--: %d", call_to_stack);
    printf("\nNo. Of Comparisons--: %d\n", comp);
}
