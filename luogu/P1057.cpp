#include <stdio.h>
#include <cstring>

int num;
int sum;
int n, m;
int f[31][31];


void  dfs(int x,int s)
{
    f[x][s] = 0;
    if(s==m&&x==0)
        f[x][s] = 1;
    if(s!=m)
    {
        if(f[(x+1)%n][s+1]==-1)
            dfs((x+1)%n, s + 1);
        if(f[(x-1+n)%n][s+1]==-1)
            dfs((x-1+n)%n, s + 1);
        f[x][s] = f[(x-1+n)%n][s + 1] + f[(x+1)%n][s + 1];
    }
}


int main()
{
    memset(f, -1, sizeof(f));
    scanf("%d%d", &n, &m);

    dfs(0, 0);
    printf("%d", f[0][0]);

    return 0;
}