#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n, m, p;

string name[21];
string pp[101];

int main()
{
    scanf("%d%d%d", &n, &m, &p);

    for (int i = 1; i <= n;i++)
    {
        cin >> name[i];
    }

    for (int i = 1; i <= p;i++)
    {
        getline(cin,pp[i]);
    }
    

    printf("ok");

    return 0;
}