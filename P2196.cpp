#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int ans = -1;
int start = 0;
int l[21] = {0};
int a[21] = {0};//地雷个数
int map[21][21] = {0};//地图

int cm[21][21] = {0};//更新后的地图,可能没有用


int dp[21] = {0};//储存挖雷个数

int nextt[21] = {0};//储存路径
int nex[21] = {0};
int s[21] = {0};

int dfs(int i)
{
    if(dp[i]!=0)
        return dp[i];
    s[i] = 1;
    dp[i] = a[i];
    for (int j = 1; j <= n;j++)
    {
        if(cm[i][j]==1&&s[j]==0)
        {
            cm[i][j] = 0;

            dfs(j);


            if(dp[j]+a[i]>dp[i])
            {
                dp[i] = dp[j] + a[i];
                nextt[i] = j;
            }
            else
            {
                cm[i][j] = 1;
            }
            
        }
    }

    return dp[i];
}


void clear()
{
    for (int i = 1; i <= n;i++)
    {
        s[i] = 0;

    }
}

void copym()
{
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cm[i][j] = map[i][j];
        }
    }
}


int main()
{

    scanf("%d", &n);

    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);

        }
    }

    for (int i = 1; i <= n;i++)
    {
        clear();
        copym();
        int temp = dfs(i);

        if(ans<temp)
        {
            ans = temp;
            start = i;
        }

    }

    printf("%d", start);
    while(nextt[start]!=0)
    {
        printf(" ");
        printf("%d", nextt[start]);
        start = nextt[start];
    }

    
    printf("\n%d", ans);

    return 0;
}