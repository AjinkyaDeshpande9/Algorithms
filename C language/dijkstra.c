// Dijkstra Algorithm

/*
    Approach: Greedy
    Time Complexity: WAB - O(E+VlogV)
    Space Complexity: O(V)
*/

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startNode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, minDistance, nextNode;

    // Creating the cost matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }

    // Initializing pred[], diatance[] and visited[]
    for (int i = 0; i < n; i++)
    {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }
    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while (count < n - 1)
    {
        // Finding the node with minimum distance
        minDistance = INFINITY;
        for (int i = 0; i < n; i++)
        {
            if (distance[i] < minDistance && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        // check if better path exists
        visited[nextNode] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (minDistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }

        count++;
    }

    // Print the path and distance of each node
    for (int i = 0; i < n; i++)
    {
        if (i != startNode)
        {
            printf("\n\nDistance of node%d = %d\n", i, distance[i]);
            // printf("\nShortest Path=%d",i);
        }

        int j = i;
        do
        {
            j = pred[j];
            printf("<-%d", j);

        } while (j != startNode);
    }
    printf("\n-------------------------------------------------------------------------------------------------------------\n");
}

int main()
{
    int G[MAX][MAX], i, j, n, u;
    printf("Enter no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("\nEnter the starting node:");
    scanf("%d", &u);
    dijkstra(G, n, u);

    return 0;
}