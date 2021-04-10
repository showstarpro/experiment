#include <stdio.h>
#include <iostream>

using namespace std;
    int a[1001][1001]={0};
    int dp[1001][1001] = {0};

int main()
{


    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= i;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }



   
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= i;j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i-1][j]) + a[i][j];
        }
    }

    int ans = -1;

    for (int i = 1; i <= n;i++)
    {
        ans = max(ans, dp[n][i]);
    }

    printf("%d", ans);

    return 0;
}