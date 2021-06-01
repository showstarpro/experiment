#include <stdio.h>
#include <iostream>

using namespace std;

    int r, c;
int a[101][101] = {0};
int dp[101][101] = {0};
int mx[4] = {0, -1, 0, 1};
int my[4] = {1, 0, -1, 0};
int ans = -1;

int dfs(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4;i++)
    {
        int xx = x + mx[i];
        int yy = y + my[i];

        if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
        {
            if(a[x][y]>a[xx][yy])
                {
                        dfs(xx, yy);
                    dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
                }
        }

    }

    return dp[x][y];
}


int main()
{

    scanf("%d%d", &r, &c);

    for (int i = 1; i <= r;i++)
    {
        for (int j = 1; j <= c;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= r;i++)
    {
        for (int j = 1; j <= c;j++)
        {
            ans=max(ans,dfs(i, j));

        }
    }

    printf("%d", ans);
    return 0;
}