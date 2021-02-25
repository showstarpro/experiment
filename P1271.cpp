#include<iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans[n+1]={0};
    int t;

    for (int i = 1; i <= m;i++)
    {
        cin >> t;
        ans[t]++;
    }

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= ans[i];j++)
        {
            cout << i<<' ';
        }
    }

    return 0;
}