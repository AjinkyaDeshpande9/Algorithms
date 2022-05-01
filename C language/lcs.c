// LCS

/*
    Approach: Dynamic Programming
    Time Complexity: WAB - O(mn)
    Space Complexity: O(mn)
*/

#include <stdio.h>
#include <string.h>

int max(int a, int b);
void printLCS(int i, int j)
{
    char X[10], Y[10], L[10][10];
    if (i == 0 || j == 0)
        return;

    if (X[i] == Y[j])
    {
        printLCS(i - 1, j - 1);
        printf("%c", X[i]);
    }
    else if (L[i][j - 1] >= L[i - 1][j])
        printLCS(i, j - 1);
    else
        printLCS(i - 1, j);
}
int lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;
    // char arrow;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
                // arrow="UP";
            }

            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                // arrow="D";
            }

            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                // arrow="B";
            }
            // puts(arrow);
            printf("%d \t", L[i][j]);
        }

        printf("\n");
    }
    printf("\nLongest Common Sub-Sequence is: \n");
    printLCS(m, n);
    return L[m][n];
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char X[10], Y[10];
    printf("Enter first string: \n");
    gets(X);
    printf("Enter second string: \n");
    gets(Y);

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d", lcs(X, Y, m, n));

    // printf("\nLongest Common Sub-Sequence is: bcba \n");
    return 0;
}
