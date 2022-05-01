// Floyd Warshall

/*
    Approach: Dynamic Programming
    Time Complexity: WAB - O(V^3)
    Space Complexity: O(V^2)
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
int n;
int dcurrent[10][10], dprevious[10][10], parent[10][10];
void shortestpath(int start, int end)
{
    int pointer = 1;
    int path[10];
    printf("\nThe shortest distance between %c ---> %c is %d", start + 64, end + 64, dcurrent[start][end]);
    path[1] = end;
    while (parent[start][end] != start)
    {
        pointer++;
        path[pointer] = parent[start][end];
        end = parent[start][end];
    }
    pointer++;
    path[pointer] = start;
    printf("\nPath is : ");
    for (int j = pointer; j >= 1; j--)
    {
        if (j == 1)
            printf("%c", path[j] + 64);
        else
            printf("%c->", path[j] + 64);
        path[j] = 0;
    }
}
void printarray()
{
    printf("Array of Shortest Distance(D)\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("\t%d ", dcurrent[i][j]);
        }
        printf("\n");
    }
    printf("Array Parent(P)\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (parent[i][j] == -1)
            {
                printf("\tNil ");
            }
            else
                printf("\t%c ", parent[i][j] + 64);
        }
        printf("\n");
    }
}
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}
void replace(int a)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dprevious[i][j] = dcurrent[i][j];
        }
    }
}
void floydwarshall()
{
    // printf("\nArrived-----\n");
    // printarray();
    for (int k = 1; k <= n; k++)
    {
        replace(k);
        // printf("\nReplaced");
        // printarray();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != k && j != k && i != j)
                {
                    dcurrent[i][j] = min(dprevious[i][j], dprevious[i][k] + dprevious[k][j]);
                    if (dcurrent[i][j] != dprevious[i][j])
                    {
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
        printf("\n %c th iteration-----\n", k + 64);
        printarray();
    }
}
int main()
{
    int start, end, count;
    printf("\nEnter the number of vertices : ");
    scanf("%d", &n);
    printf("Enter the adjecency matrix :\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &dcurrent[i][j]);
            if (dcurrent[i][j] == 999 || dcurrent[i][j] == 0)
                parent[i][j] = -1;
            else
                parent[i][j] = i;
        }
    }
    floydwarshall();
    printf("\nFinal Parent and Shortest Distance Array :\n");
    printarray();
    printf("\nEnter the vertices between which shortest distance is to be found : ");
    scanf("%d %d", &start, &end);
    shortestpath(start, end);
    return 0;
}