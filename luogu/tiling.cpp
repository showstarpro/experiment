#include <stdio.h>

long long int ans[251];


void creat()
{
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 3;
    int i = 3;
    while(i<251)
    {
        ans[i] = ans[i - 1] + 2 * ans[i - 2];
        i++;
    }
}


int main()
{
    creat();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d", ans[n]);
    }
    return n;
}