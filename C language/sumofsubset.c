// Sum of Subset

/*
    Approach: Backtracking
    Time Complexity: WAB - O(2^n)
    Space Complexity: O(1)
*/

#include <stdio.h>
#define MAX 30
void sumofsubsets(int s, int k, int r);
int w[MAX], x[MAX], count = 1;
int m, n;
int main()
{
    int i, r = 0;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter weights of the elements in non decreasing order : ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &w[i]);
    }
    printf("Enter the total sum you want : ");
    scanf("%d", &m);
    for (i = 0; i < n; ++i)
    {
        r += w[i];
    }
    sumofsubsets(0, 0, r);
    return 0;
}

void sumofsubsets(int s, int k, int r)
{
    int j, addzero = 0;
    x[k] = 1;
    if (s + w[k] == m)
    {
        x[k] = 1;
        printf("Subset %d : [ ", count++);
        for (j = 0; j <= k; ++j)
        {
            printf("%d ", x[j]);
            addzero++;
        }
        for (j = addzero; j < n; ++j)
        {
            printf("0 ");
        }
        printf("]\n");
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        sumofsubsets(s + w[k], k + 1, r - w[k]);
    }
    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {
        x[k] = 0;
        sumofsubsets(s, k + 1, r - w[k]);
    }
}