#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int visited[201]={0};
int move[201]={0};
int ans = 0x7ffffff;
int n, a, b;
 
void dfs(int now,int sum)
{
    if(now==b)
        ans = min(ans, sum);
    if(sum>ans)
        return;
    visited[now] = 1;
    if(now+move[now]<=n&&!visited[now+move[now]])
        dfs(now + move[now], ans + 1);
    if(now-move[now]>=1&&!visited[now-move[now]])
        dfs[now - move[now], ans + 1];
    visited[now] = 0;
}


int main()
{

    cin >> n >> a >> b;
    for (int i = 1; i <= n;i++)
        scanf("%d", move + i);
    vistied[a] = 1;
    dfs(a, 0);
    if(ans!=0x7ffffff)
        printf("%d", ans);
        else
            printf("-1");
    return 0;
}