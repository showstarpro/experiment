#include <stdio.h>
#include <iostream>

using namespace std;

struct node {
    int id;
    int cost;
} a[21][21];

int list[400];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = 1; i <= m * n;i++)
    {
        scanf("%d", list + i);
    }

    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            scanf("%d", &a[i][j].id);
        }
    }

    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            scanf("%d", &a[i][j].cost);
        }
    }

    


    return 0;
}


