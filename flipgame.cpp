#include<stdio.h>

const int inf=9999;
char s[5];
int map[4][4],i,j;
int ans=inf;

int check()
{
    int x=map[0][0];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(map[i][j]!=x)
            {
                return 0;
            }
        }
    }

    return 1;
}


void turn(int x,int y)
{
    map[x][y]=!map[x][y];
    if(x-1>=0)
    map[x-1][y]=!map[x-1][y];
    if(x+1<4)
    map[x+1][y]=!map[x+1][y];
    if(y-1>=0)
    map[x][y-1]=!map[x][y-1];
    if(y+1<4)
    map[x][y+1]=!map[x][y-1];
}

int dfs(int x,int y,int t)
{
    if(check())
    {
        if(ans>t)
        ans=t;
        return 0;
    }

    if(x>=4||y>=4)  return 0;
    int nx,ny;
    nx=(x+1)%4;
    ny=y+(x+1)/4;
    dfs(nx,ny,t);

    turn(x,y);

    dfs(nx,ny,t+1);
    turn (x,y);
    return 0;
}


int main()
{
    for(i=0;i<4;i++)
    {
        scanf("%s",s);
        for(j=0;j<4;j++)
        {
            if(s[j]=='b')
            map[i][j]=0;
            else 
            map[i][j]=1;
        }
    }
    dfs(0,0,0);

    if(ans==inf)
    printf("Impossible\n");
    else printf("%d\n",ans);
    return 0;
}
