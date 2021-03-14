#include <iostream>
#include <stdio.h>

using namespace std;

const char stick[6][8] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."};//单个方块

char paint[550][550];//画布
int a[55][55];


void draw(int x,int y)//放置方块
{
    for (int i = 0; i < 6;i++)
    {
        for (int j = 0; j < 7;j++)
        {
            if(stick[6-i-1][j]!='.')
            paint[x - i][y+j] = stick[6 - i - 1][j];
        }
    }
}


int main()
{
    int n, m, k(0), l, x, y;
    cin >> n >> m;
    l = 4 * m + 1 + 2 * n;//画布宽度
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            cin >> a[i][j];
            k = max(k, 3 * a[i][j] + 1 + 2 * (n - i + 1));
        }
    }

    for (int i = 1; i <= k;i++)
    {
        for (int j = 1; j <= l;j++)
            paint[i][j] = '.';
    }

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
           
            x=k-2*(n-i);
            y = 4 * (j-1) + 1 + 2 * (n - i);
            while(a[i][j]--)
            {
                draw(x, y);
                x = x - 3;
            }
        }
    }

    for (int i = 1; i <= k;i++)
    {
        for (int j = 1; j <= l;j++)
        {
            printf("%c", paint[i][j]);
        }
        printf("\n");
    }

    return 0;
}



