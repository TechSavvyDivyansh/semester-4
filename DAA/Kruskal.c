// kruskals

#include <stdio.h>
#include <stdlib.h>
int i, j, k, a, b, u, v, n=9, ne = 1;
int cost[50][50]={
    {0,4,0,0,0,0,0,8,0},
    {4,0,8,0,0,0,0,11,0},
    {0,8,0,7,0,4,0,0,2},
    {0,0,7,0,9,14,0,0,0},
    {0,0,0,9,0,10,0,0,0},
    {0,0,4,14,10,0,2,0,0},
    {0,0,0,0,0,2,0,1,6},
    {8,11,0,0,0,0,1,0,7},
    {0,0,2,0,0,0,6,7,0},
};
int min, mincost = 0, parent[10]={0};
int find(int);
int uni(int, int);
int main()
{
    printf("\n\tImplementation of Kruskal's algorithm\n");
    // printf("\nEnter the no. of vertices:");
    // scanf("%d", &n);
    // printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            // scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\tMinimum cost = %d\n", mincost);
}
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}