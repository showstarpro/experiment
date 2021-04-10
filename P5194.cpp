#include <iostream>

using namespace std;

long long int  m = 0;
long long int sum[100],a[1000];
int N,C;


void dfs(long long cur,int index)
{
    if(cur+a[index]<=m)
        return;
    m = cur < m ? m : cur;
    if(index==0)
        return;
    if(cur+a[index<=C])
        dfs(cur + a[index], index - 1);
    dfs(cur, index - 1);
}

int main()
{
    cin >> N>>C;
    int i = 1;
    for (; i <= N;i++)
    {
        scanf("%lld", a + i);
        if(a[i]>C)
            break;
        sum[i] = sum[i - 1] + a[i];
    }

    dfs(0, i-1);

    printf("%lld", m);

    return 0;

}